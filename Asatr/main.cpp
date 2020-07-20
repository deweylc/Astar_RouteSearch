#include "Asatr.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Asatr w;
	
    w.show();
    return a.exec();
}
