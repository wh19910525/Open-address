#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess(this);

}

/*
bool MainWindow::loadFile(const QString &fileName)
{
   QFile file(fileName); // �½�QFile����
   if (!file.open(QFile::ReadOnly | QFile::Text)) {
       QMessageBox::warning(this, tr("���ĵ��༭��"),
                             tr("�޷���ȡ�ļ� %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
       return false; // ֻ����ʽ���ļ�����������ʾ��������false
   }

   QTextStream in(&file); // �½��ı�������
   QApplication::setOverrideCursor(Qt::WaitCursor);

   // ��ȡ�ļ���ȫ���ı����ݣ�����ӵ��༭����
   ui->textEdit->setPlainText(in.readAll());
   QApplication::restoreOverrideCursor();

   // ���õ�ǰ�ļ�
   curFile = QFileInfo(fileName).canonicalFilePath();
   setWindowTitle(curFile);
   return true;
}
*/

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

        //���´���һ�� ���� �� ִ�� �ⲿ����
        //process->start("unpack_update_zip.bat", args);

        //���� �ȴ� �ⲿ���� ִ�����
        process->execute("unpack_update_zip.bat", args);


     }



}
