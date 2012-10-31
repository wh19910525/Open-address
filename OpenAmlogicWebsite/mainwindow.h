#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QProcess>
#include <QMouseEvent>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    QProcess *process;
    QString program;
    QStringList args;
    QString ttt;


protected:
    void mousePressEvent(QMouseEvent *);


private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
