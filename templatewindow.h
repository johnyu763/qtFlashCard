#ifndef TEMPLATEWINDOW_H
#define TEMPLATEWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class TemplateWindow : public QMainWindow
{
    Q_OBJECT
public:
    TemplateWindow(QWidget *parent = nullptr);

signals:

public slots:

protected slots:
    void newFile();
    void openFile();

protected:
    void createAction();
    void createMenu();
    void resizeEvent(QResizeEvent *event);
    QTextEdit *background;
    QAction *newAction;
    QAction *openAction;
    QMenu *fileMenu;

};

#endif // TEMPLATEWINDOW_H
