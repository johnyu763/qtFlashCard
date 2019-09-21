#include <QApplication>

#include "quizwindow.h"
#include "button.h"
#include "mainwindow.h"


int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow();
    window->show();

    return app.exec();
}

