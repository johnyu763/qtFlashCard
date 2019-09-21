#include "quizwindow.h"
#include "button.h"
#include "mdatabase.h"
#include <QPushButton>
#include <QTextEdit>
#include <QtWidgets>
#include <cstdlib>
#include <QDebug>

QuizWindow::QuizWindow(const QString &dbname, QWidget *parent) : TemplateWindow(parent){
    srand(time(nullptr));
    db = new MDataBase(dbname);


    question = new QTextEdit(this);
    question->setStyleSheet("background-color:#0d0d0d;\
                            color:white;\
                            padding: 30px;");
    question->setFontPointSize(20);
    question->setReadOnly(true);
    question->setGeometry(0,65, 760,420);


    answers[0] = new Button(this);
    answers[1] = new Button(this);
    answers[2]= new Button(this);
    answers[3] = new Button(this);
    answers[3]->setText("None of these");
    next = new Button("Next", this);

    nextQuestion();

    connect(next, SIGNAL(clicked(bool)), this, SLOT(nextQuestion()));
}

void QuizWindow::resizeEvent(QResizeEvent *event){
    question->setGeometry(0,65, width(),height()-130);
    answers[0]->setGeometry((width()/8)-75,height()-53, 150, 40);
    answers[1]->setGeometry((3*width()/8)-75,height()-53, 150, 40);
    answers[2]->setGeometry((5*width()/8)-75,height()-53, 150, 40);
    answers[3]->setGeometry((7*width()/8)-75,height()-53, 150, 40);
    next->setGeometry(width()-85,30, 60, 25);
    TemplateWindow::resizeEvent(event);
}

void QuizWindow::setQuestion(int id){
    question->setText(db->getQuestion(id));
    question->setAlignment(Qt::AlignCenter);
}

void QuizWindow::setCards(int id, int size){
    int r_num;
    int id_num[3];
    for(int i=0; i<3; i++){
        r_num=rand()%size+1;
        bool found = std::find(std::begin(id_num),
                                     std::end(id_num), r_num) !=std::end(id_num);
        if(r_num!=id && !found){
            id_num[i] = r_num;
        }
        else{
            i--;
        }
    }
    r_num = rand()%4;


    for(int n=0;n<4;n++){
        if(r_num==n){
            answers[n]->setCorrect(true);
            if(n<3){
                id_num[n]=id;
            }
        }
        else{
            answers[n]->setCorrect(false);
        }

        if(n<3){
            answers[n]->setText(db->getOption(id_num[n]));
        }
    }
}

void QuizWindow::nextQuestion(){
    int size = db->getSize();
    if(size){
        int r_num = rand()%size+1;
        setQuestion(r_num);
        setCards(r_num, size);
    }
}



QuizWindow::~QuizWindow(){
    delete answers[4];
    delete next;
    delete question;
    delete background;
    delete db;
}
