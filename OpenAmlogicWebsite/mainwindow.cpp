#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess(this);

    //���ô��ڱ���
    program = "explorer.exe";
    curfilename = tr("OpenAddress");

    setWindowTitle(curfilename);

    //����һ�� �� ������ʱ���ͻ� ��ʾ���� ճ���������
    mousePressEvent(tmpe);
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

    //ɾ�� �ַ������ "$"�ַ�
    ttt.remove("$");
    //�� "\"�滻 ��ǰ�ַ����� ���е� "/"
    ttt.replace(QString("/"), QString("\\"));

    //================= start ========================
    ttt.replace(QString("hai.wang@droid07-sz:\\mnt"), QString("\\\\10.28.8.17"));
    ttt.replace(QString("hai.wang@droid05-sz:\\mnt"), QString("\\\\10.28.8.15"));
    ttt.replace(QString("hai.wang@droid01-sz:\\mnt"), QString("\\\\10.28.8.10"));




    //======================== end ==============================
    //�� ��һ�� Line edit ����ʾ ת����� �ַ���
    ui->lineEdit->clear();
    ui->lineEdit->setText(ttt);



}


void MainWindow::on_pushButton_clicked()
{
    //QProcess *process=new QProcess(this);
    //QString program="explorer.exe";
    //QStringList args;
    //QString ttt = "\\10.28.8.15\nfsroot\hai.wang\ics-amlogic-g06-0525-20120808145125";


    args.clear();
    args<<ttt;
    process->start(program,args);
    //process->execute(program,args);
   // args.clear();
}






