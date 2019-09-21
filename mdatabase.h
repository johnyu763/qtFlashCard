#ifndef MDATABASE_H
#define MDATABASE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

class MDataBase
{
public:
    MDataBase(const QString &filename);
    ~MDataBase();
    void insertEntry(const QString &question, const QString &answer);
    QString getQuestion(int id);
    QString getOption(int id);
    int getSize();

private:
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // MDATABASE_H
