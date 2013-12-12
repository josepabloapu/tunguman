#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QString>

int id, timeMS;
QString name, team;
int number;
int xpos, ypos;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    id = 1;
    timeMS = 1800;
    name = "\'pirlo\'";
    team = "\'italy\'";
    number = 21;
    xpos = 450;
    ypos = 120;

    /*
    MainWindow w;
    w.show();
    */

    QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL" );

    db.setHostName( "localhost" );
    db.setDatabaseName( "test" );

    db.setUserName( "root" );
    db.setPassword( "root" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }

    qDebug( "Connected!" );
    QSqlQuery qry;

    qry.prepare( "CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE KEY, time INTEGER, name VARCHAR(30), team VARCHAR(30), number INTEGER, xpos INTEGER, ypos INTEGER)" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table created!";

    qry.prepare( QString("INSERT INTO names (id, time, name, team, number, xpos, ypos) VALUES (%1, %2, %3, %4, %5, %6, %7)").arg(id).arg(timeMS).arg(name).arg(team).arg(number).arg(xpos).arg(ypos) );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug( "Inserted!" );


    return a.exec();
}
