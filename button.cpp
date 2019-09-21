#include "button.h"
#include <iostream>
#include <QApplication>


Button::Button(QWidget *parent) : QPushButton(parent){
    this->correct = false;
    connect(this, SIGNAL(clicked(bool)), this, SLOT(answerClicked()));
    //this->setStyleSheet("border-radius:25%;");
}

Button::Button(const QString &message, QWidget *parent) : QPushButton(message,parent){

}


void Button::answerClicked(){
    if(this->correct){
        this->setStyleSheet("border:1px solid green;");
    }
    else{
        this->setStyleSheet("border:1px solid red;");
        emit rightAnswer();
    }
}

void Button::setCorrect(bool right){
    this->correct = right;
    this->setStyleSheet("");
}

bool Button::getCorrect(){
    return this->correct;
}
