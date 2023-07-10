#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "window.h"
#include "appwithtwobuttons.h"
#include <QProgressBar>
#include <QSlider>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 QPushButton button1;
 QPushButton button2("other", &button1);
 button1.setText("My text");
 button1.setToolTip("A tooltip");

 QFont font ("Courier");
 button1.setFont(font);

 QIcon icon ("/home/niloufar/Pictures/1.png");
 button1.setIcon(icon);
 button1.setIcon(QIcon::fromTheme("face-smile"));

 button1.show();


 Window windowFromAnotherClass;
 windowFromAnotherClass.setFixedSize(500, 250);
 windowFromAnotherClass.show();

 QWidget window;
  window.setFixedSize(200, 80);

 QProgressBar *progressBar = new QProgressBar(&window);
  progressBar->setRange(0, 100);
  progressBar->setValue(0);
  progressBar->setGeometry(10, 10, 180, 30);

  QSlider *slider = new QSlider(&window);
   slider->setOrientation(Qt::Horizontal);
   slider->setRange(0, 100);
   slider->setValue(0);
   slider->setGeometry(10, 40, 180, 30);

   window.show();
 //QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));


 //QWidget application_with_two_buttons;
 // application_with_two_buttons.setFixedSize(100, 80);

 //QPushButton *buttonInfo = new QPushButton("Info", &application_with_two_buttons);
 // buttonInfo->setGeometry(10, 10, 80, 30);

 //QPushButton *buttonQuit = new QPushButton("Quit", &application_with_two_buttons);
 // buttonQuit->setGeometry(10, 40, 80, 30);

 //application_with_two_buttons.show();

 return app.exec();
}
