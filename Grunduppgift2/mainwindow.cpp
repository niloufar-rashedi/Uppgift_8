#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::updateSpinBoxValues);
    connect(ui->spinBoxRed, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::checkSpinBoxValue);
    connect(ui->spinBoxGreen, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::checkSpinBoxValue);
    connect(ui->spinBoxBlue, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::checkSpinBoxValue);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qApp->exit();
}

void MainWindow::updateSpinBoxValues(const QString& text)
{
    int step = text.toInt();

    ui->spinBoxRed->setSingleStep(step);
    ui->spinBoxGreen->setSingleStep(step);
    ui->spinBoxBlue->setSingleStep(step);

}

void MainWindow::checkSpinBoxValue(int value)
{
    if (value == ui->spinBoxRed->minimum() || value == ui->spinBoxRed->maximum() ||
        value == ui->spinBoxGreen->minimum() || value == ui->spinBoxGreen->maximum() ||
        value == ui->spinBoxBlue->minimum() || value == ui->spinBoxBlue->maximum()) {
        QMessageBox::information(this, "Limit Reached", "You reached the Min/Max value!");
    }
}
