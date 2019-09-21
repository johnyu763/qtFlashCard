#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QWidget>
#include <QPushButton>


class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);
    Button(const QString &message, QWidget *parent = nullptr);
    void setCorrect(bool right);
    bool getCorrect();

signals:
    void rightAnswer();

private slots:
    void answerClicked();

private:
    bool correct;

};

#endif // PUSHBUTTON_H
