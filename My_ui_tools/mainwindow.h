#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>

#include<QProcess>




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
    bool loadFile(const QString &fileName); // ╪стьнд╪Ч




    
private slots:
    void on_open_update_package_clicked();



private:
    Ui::MainWindow *ui;

    QProcess *process;
    QString program;
    QStringList args;

    QString curFile;


};

#endif // MAINWINDOW_H
