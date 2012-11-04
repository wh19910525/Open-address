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
   QFile file(fileName); // 新建QFile对象
   if (!file.open(QFile::ReadOnly | QFile::Text)) {
       QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
       return false; // 只读方式打开文件，出错则提示，并返回false
   }

   QTextStream in(&file); // 新建文本流对象
   QApplication::setOverrideCursor(Qt::WaitCursor);

   // 读取文件的全部文本内容，并添加到编辑器中
   ui->textEdit->setPlainText(in.readAll());
   QApplication::restoreOverrideCursor();

   // 设置当前文件
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

        //重新创建一个 进程 来 执行 外部程序
        //process->start("unpack_update_zip.bat", args);

        //阻塞 等待 外部程序 执行完毕
        process->execute("unpack_update_zip.bat", args);


     }



}
