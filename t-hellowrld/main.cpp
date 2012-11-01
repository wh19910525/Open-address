
#include <QtGui>
//#include <QLabel>

int main(int argc, char* *argv)
{
    QApplication app(argc, argv);

    //QWidget *tt = new QWidget();
    //tt->show();

    //QMainWindow *mm = new QMainWindow();
    //mm->show();

    //QDialog *dd = new QDialog();
    QDialog dd;

    QLabel * label = new QLabel(&dd);
    label->setText("hello world!");

    //dd->show();
    dd.show();

    return app.exec();


}

