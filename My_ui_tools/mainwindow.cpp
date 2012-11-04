#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->update_output->setReadOnly(true);//ʹ����ؼ�Ϊ ֻ����
    process = new QProcess(this);
    connect(process, SIGNAL(readyRead()), this, SLOT(readOutput()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_update_package_clicked()
{
    //�򿪶Ի��򣬻�ȡ��Ҫ�򿪵��ļ���,��Ҫ�򿪵��ļ�����
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open update.zip"), ".", tr("update.zip *.zip | *.txt"));

    // ����ļ�����Ϊ�գ�������ļ�
    if (!fileName.isEmpty()) {

        //��ȡ ѹ������ ����
        curFile = QFileInfo(fileName).canonicalFilePath();

        //�� "\"�滻 ��ǰ�ַ����� ���е� "/"
        curFile.replace(QString("/"), QString("\\"));

        ui->lineEdit->setText(curFile);

        //process->start("unpack_update_zip.bat update.zip");
        args.clear();
        args<< curFile;

        //���´���һ�� ���� �� ִ�� �ⲿ����,���� ������Ͳ�������
        process->start("unpack_update_zip.bat", args);

        //���� �ȴ� �ⲿ���� ִ�����
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




