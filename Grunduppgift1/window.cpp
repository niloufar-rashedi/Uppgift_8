#include "window.h"
#include <QPushButton>
#include <QApplication>
Window::Window(QWidget *parent)
    : QWidget{parent}
{
setFixedSize(100, 50);

m_button = new QPushButton("CloseX", this);
m_button->setGeometry(10, 10, 80, 30);
 m_button->setCheckable(true);

 m_counter = 0;

  //connect(m_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
  connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
  connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));
}

void Window::slotButtonClicked(bool checked)
{
 if (checked) {
 m_button->setText("Checked");
 } else {
 m_button->setText("Hello World");
 }
 m_counter++;
 if (m_counter == 3) {
 emit counterReached();
 }
}
