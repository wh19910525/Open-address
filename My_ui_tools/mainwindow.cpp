#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->update_output->setReadOnly(true);//使这个控件为 只读的
    process = new QProcess(this);
    connect(process, SIGNAL(readyRead()), this, SLOT(readOutput()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_update_package_clicked()
{
    //打开对话框，获取将要打开的文件名,将要打开的文件类型
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open update.zip"), ".", tr("update.zip *.zip | *.txt"));

    // 如果文件名不为空，则加载文件
    if (!fileName.isEmpty()) {

        //获取 压缩包的 名字
        curFile = QFileInfo(fileName).canonicalFilePath();

        //用 "\"替换 当前字符串里 所有的 "/"
        curFile.replace(QString("/"), QString("\\"));

        ui->lineEdit->setText(curFile);

        //process->start("unpack_update_zip.bat update.zip");
        args.clear();
        args<< curFile;

        //重新创建一个 进程 来 执行 外部程序,这样 主程序就不会阻塞
        process->start("unpack_update_zip.bat", args);

        //阻塞 等待 外部程序 执行完毕
        //process->execute("unpack_update_zip.bat", args);

        output = tr("");
        ui->update_output->setText(output);

     }
}

void MainWindow::readOutput()
{
    output += process->readAll();
    ui->update_output->setText(output);
}




