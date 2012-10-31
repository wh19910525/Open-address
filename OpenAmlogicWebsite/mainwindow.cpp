#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess(this);
    program = "explorer.exe";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    //���� ��� ��ʾ����Ȼ�� �� ճ��������� д��ȥ
    ui->textEdit_address->clear();
    ui->textEdit_address->paste();

    //��ȡ Line Edit�ؼ���� �ַ���
    ttt = ui->textEdit_address->text();
    args<<ttt;
}


void MainWindow::on_pushButton_clicked()
{
    //QProcess *process=new QProcess(this);
    //QString program="explorer.exe";
    //QStringList args;
    //QString ttt = "\\10.28.8.15\nfsroot\hai.wang\ics-amlogic-g06-0525-20120808145125";

    process->start(program,args);
    args.clear();
}
