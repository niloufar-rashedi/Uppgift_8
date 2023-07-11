#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication app (argc, argv);

    QWidget window;
     window.setFixedSize(100, 80);

    QPushButton *buttonInfo = new QPushButton("Info", &window);
     buttonInfo->setGeometry(10, 10, 80, 30);
     QObject::connect(buttonInfo, SIGNAL (clicked()), &app, SLOT (aboutQt()));
    QPushButton *buttonQuit = new QPushButton("Quit", &window);
     buttonQuit->setGeometry(10, 40, 80, 30);
     QObject::connect(buttonQuit, SIGNAL (clicked()), &app, SLOT (quit()));

    window.show();

    // Add your code here

    return app.exec();
}
