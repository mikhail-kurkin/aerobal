#include "skkp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    skkp w;
    w.show();

    return a.exec();
}
