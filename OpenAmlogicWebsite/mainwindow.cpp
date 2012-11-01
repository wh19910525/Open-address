#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess(this);

    //设置窗口标题
    program = "explorer.exe";
    curfilename = tr("OpenAddress");

    setWindowTitle(curfilename);

    //当第一次 打开 本程序时，就会 显示出来 粘贴板的内容
    mousePressEvent(tmpe);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    //首先 清除 显示区，然后 把 粘贴板的内容 写上去
    ui->textEdit_address->clear();
    ui->textEdit_address->paste();

    //获取 Line Edit控件里的 字符串
    ttt = ui->textEdit_address->text();

    //删除 字符串里的 "$"字符
    ttt.remove("$");
    //用 "\"替换 当前字符串里 所有的 "/"
    ttt.replace(QString("/"), QString("\\"));

    //================= start ========================
    ttt.replace(QString("hai.wang@droid07-sz:\\mnt"), QString("\\\\10.28.8.17"));
    ttt.replace(QString("hai.wang@droid05-sz:\\mnt"), QString("\\\\10.28.8.15"));
    ttt.replace(QString("hai.wang@droid01-sz:\\mnt"), QString("\\\\10.28.8.10"));




    //======================== end ==============================
    //在 另一个 Line edit 里显示 转换后的 字符串
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






