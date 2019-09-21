#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextEdit>
#include <QWidget>
#include "button.h"
#include "quizwindow.h"

class MainWindow : public TemplateWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


signals:

private slots:
    void openQuiz();

private:
    Button *quiz;
    QuizWindow *qwin;
    void resizeEvent(QResizeEvent *event);


};

#endif // MAINWINDOW_H
