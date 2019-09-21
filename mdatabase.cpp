#include "mdatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

MDataBase::MDataBase(const QString &filename)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString fstring = QString(filename);
    qDebug()<<fstring;
    db.setDatabaseName(fstring);
    db.open();
    query = new QSqlQuery(db);
    QString table_qry = "CREATE TABLE deck ("
                        "ID integer,"
                        "QUESTION VARCHAR(40),"
                        "ANSWER VARCHAR(20),"
                        "UNIQUE (QUESTION, ANSWER));";

    query->exec(table_qry);

}

void MDataBase::insertEntry(const QString &question, const QString &answer){
    QString size = QString::number(getSize()+1);
    QString in_qry = QString("INSERT INTO deck (ID, QUESTION, ANSWER)"
                             "VALUES (%1, '%2', '%3');").arg(size, question, answer);
    query->exec(in_qry);
}

QString MDataBase::getQuestion(int id){
    query->clear();
    QString q_qry = QString("SELECT QUESTION "
                            "FROM deck "
                            "WHERE ID=%1;").arg(id);
    query->exec(q_qry);
    query->next();
    return query->value(0).toString();
}

QString MDataBase::getOption(int id){
    query->clear();
    QString o_qry = QString("SELECT ANSWER "
                            "FROM deck "
                            "WHERE ID=%1;").arg(id);
    query->exec(o_qry);
    query->next();
    return query->value(0).toString();
}

int MDataBase::getSize(){
    query->clear();
    query->exec("SELECT COUNT(*) FROM deck;");
    query->next();
    return query->value(0).toInt();
}

MDataBase::~MDataBase(){
    db.close();
    delete query;
}
