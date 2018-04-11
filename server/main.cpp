/****************************************************************************
** Copyright (C) 2018 Olaf Japp
**
** This file is part of Wandel.
**
**  Wandel is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Wandel is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include <QCoreApplication>
#include <QTextStream>
#include <QtSql>
#include <QUrlQuery>

QSqlError initDb()
{
    QTextStream cout(stdout);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("wandel");
    db.setUserName("wandel");
    db.setPassword("wandel");
    if (!db.open())
        return db.lastError();

    QStringList tables = db.tables();
    if (tables.contains("member", Qt::CaseInsensitive))
        return QSqlError();

    QSqlQuery q;
    if (!q.exec("create table member(id integer primary key auto_increment, name varchar(255), email varchar(255))"))
        return q.lastError();
    cout << "table member created" << endl;
    if (!q.exec("insert into member(name, email) values('Art', 'artanidos@gmail.com')"))
        return q.lastError();
    if (!q.exec("insert into member(name, email) values('Mike Mustermann', 'mike@mustermann.com')"))
        return q.lastError();
    cout << "member added" << endl;

    return QSqlError();
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream cout(stdout);

    cout << "Content-type: text/xml;charset=utf-8" << endl << endl;
    cout << "<wandel>" << endl;

    QUrlQuery query(qgetenv("QUERY_STRING"));
    QString action = query.queryItemValue("action");
    QString id = query.queryItemValue("id");

    if (!QSqlDatabase::drivers().contains("QMYSQL"))
    {
        cout << "<error>MYSQL driver has not been loaded</error>";
        return -1;
    }

    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError)
    {
        cout << "<error>Unable to initialize Database " + err.text() << "</error>" << endl;
        return -1;
    }

    if(action == "member")
    {
        QSqlQuery q;
        cout << "<members>" << endl;
        if(id.isEmpty())
            q.exec("select id, name, email from member");
        else
            q.exec("select id, name, email from member where id = " + id);
        while(q.next())
        {
            cout << "<member id=\"" + q.value("id").toString() + "\" name=\"" << q.value("name").toString() << "\" email=\"" << q.value("email").toString() << "\"/>" << endl;
        }
        cout << "</members>" << endl;
    }
    cout << "</wandel>" << endl;
}
