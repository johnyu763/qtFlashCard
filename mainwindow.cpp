#include "mainwindow.h"
#include <QTextEdit>
#include <QtWidgets>
#include "quizwindow.h"
#include "templatewindow.h"

MainWindow::MainWindow(QWidget *parent) : TemplateWindow(parent)
{

    quiz = new Button("Quiz Mode", this);
    qwin = new QuizWindow("first",this);

    connect(quiz, SIGNAL(clicked(bool)), this, SLOT(openQuiz()));
}

void MainWindow::openQuiz(){
    qwin->show();
}

void MainWindow::resizeEvent(QResizeEvent *event){
    TemplateWindow::resizeEvent(event);
    quiz->setGeometry(width()/2-50, height()/2-15, 100, 30);
}

MainWindow::~MainWindow(){

}
