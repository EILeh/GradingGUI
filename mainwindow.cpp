#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBoxN_valueChanged(int n)
{
    n_ = n;

}


void MainWindow::on_spinBoxG_valueChanged(int g)
{
    g_ = g;

}


void MainWindow::on_spinBoxP_valueChanged(int p)
{
    p_ = p;
}


void MainWindow::on_spinBoxE_valueChanged(int e)
{
    e_ = e;
}


void MainWindow::on_calculatePushButton_clicked()
{
    int total_grade = calculate_total_grade(n_, g_, p_, e_);
    int w_score = score_from_weekly_exercises(n_, g_);
    int p_score = score_from_projects(p_);

    QString total_string_grade = QString::number(total_grade);
    QString str_w_score = QString::number(w_score);
    QString str_p_score = QString::number(p_score);

    ui->textBrowser->setText("W-Score: " + str_w_score +
                             "\nP-Score: " + str_p_score +
                             "\nTotal grade: " + total_string_grade);

}


