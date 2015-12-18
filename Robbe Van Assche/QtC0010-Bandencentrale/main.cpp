#include <QCoreApplication>
#include <QObject>
#include <QTimer>

#include "globals.h"
#include "BCapplication.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BCapplication *task = new BCapplication(argc, argv, &a);

    QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));

    QTimer::singleShot(0, task, SLOT(run()));

    return a.exec();
}
