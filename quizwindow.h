#ifndef WINDOW_H
#define WINDOW_H

#include <QTextEdit>
#include "mdatabase.h"
#include "button.h"
#include "templatewindow.h"

class QuizWindow : public TemplateWindow
{
    Q_OBJECT
public:
    QuizWindow(const QString &dbname, QWidget *parent = nullptr);
    ~QuizWindow();

signals:

private slots:
    void nextQuestion();
    void setQuestion(int id);
    void setCards(int id, int size);

private:
    MDataBase *db;
    Button *answers[4];
    Button *next;
    QTextEdit *question;
    void resizeEvent(QResizeEvent *event);


};

#endif // WINDOW_H
