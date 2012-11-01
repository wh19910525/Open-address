
#include <QtGui>
int main(int argc, char* *argv)
{
    QApplication app(argc, argv);

    QWidget *tt = new QWidget();
    //tt->show();
    QMainWindow *mm = new QMainWindow();
    //mm->show();
    QDialog *dd = new QDialog();
    dd->show();


    return app.exec();


}

