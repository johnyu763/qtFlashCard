#include "templatewindow.h"
#include <QtWidgets>

TemplateWindow::TemplateWindow(QWidget *parent) : QMainWindow(parent)
{
    setMinimumSize(760, 550);
    filename = new QString();

    background = new QTextEdit(this);
    background->setStyleSheet("background-color: #595959;");
    background->setReadOnly(true);
    background->setGeometry(0,0,760,550);

    createAction();
    createMenu();
}

void TemplateWindow::createAction(){
    newAction = new QAction(tr("&New"), this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new flashcard set"));
    connect(newAction, &QAction::triggered, this, &TemplateWindow::newFile);

    openAction = new QAction(tr("&Open"), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing flashcard set"));
    connect(openAction, &QAction::triggered, this, &TemplateWindow::openFile);
}

void TemplateWindow::createMenu(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
}

void TemplateWindow::resizeEvent(QResizeEvent *event){
    background->setGeometry(0,0,width(),height());
    QWidget::resizeEvent(event);
}

void TemplateWindow::newFile(){

}

void TemplateWindow::openFile(){
    filename =  new QString(QFileDialog::getOpenFileName(
          this,
          "Open Document",
          "/Users/johnyu/Documents/",
          "Database files (*.db)"));
    qDebug()<<*filename;
}
