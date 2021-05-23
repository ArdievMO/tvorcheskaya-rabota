#include "mainwindow.h"
#include "ui_mainwindow.h"

int choose_box = 0;
int h, m, s, h1, m1, s1, h_out, m_out, s_out;
bool flag = 0, flag_2 = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_equal->hide();
    ui->pushButton_minus->hide();
    ui->pushButton_plus->hide();
    ui->out_hour->hide();
    ui->out_min->hide();
    ui->out_sec->hide();
    ui->pushButton_red_h->hide();
    ui->pushButton_red_m->hide();
    ui->pushButton_red_s->hide();
    ui->show_result->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_plus_clicked()
{
    ui->sign_label->setText("+");
    choose_box = 1;
    s_out = s1;
    m_out = m1;
    h_out = h1;
}

void MainWindow::on_pushButton_minus_clicked()
{
    ui->sign_label->setText("-");
    choose_box = 2;
    s_out = s1;
    m_out = m1;
    h_out = h1;
}

void MainWindow::on_pushButton_equal_clicked()
{
    if(choose_box == 1)
    {
        h_out = h_out+h+(m_out+m+(s_out+s)/60)/60;
        m_out = (m_out+m+(s_out+s)/60)%60;
        s_out = (s+s_out)%60;
        ui->out_hour->setText(QString::number(h_out));
        ui->out_min->setText(QString::number(m_out));
        ui->out_sec->setText(QString::number(s_out));
    }
    if(choose_box == 2)
    {
        s_out-=s;
        m_out-=m;
        h_out-=h;

        if(s_out<0)
        {
            s_out+=60;
            m_out--;
        }

        if(m_out<0)
        {
            m_out+=60;
            h_out--;
        }

        if(h_out<0)
        {
            ui->out_hour->setText("Ошибка!");
        }
        else
        {
            ui->out_hour->setText(QString::number(h_out,'i',0));
            ui->out_min->setText(QString::number(m_out,'i',0));
            ui->out_sec->setText(QString::number(s_out,'i',0));
        }
    }
}

double abs_time;

void MainWindow::on_pushButton_red_h_clicked()
{
    abs_time = (double)h1 + (double)m1/60.0f + (double)s1/1440.0f;
    ui->show_result->setText(QString::number(abs_time));
    ui->result_sign->setText("ч");
}

void MainWindow::on_pushButton_red_m_clicked()
{
    abs_time = (double)h1 * 60.0f + (double)m1 + (double)s1/60.0f;
    ui->show_result->setText(QString::number(abs_time));
    ui->result_sign->setText("мин");
}

void MainWindow::on_pushButton_red_s_clicked()
{
    abs_time = (double)h1*1440.0f + (double)m1*60.0f + (double)s1;
    ui->show_result->setText(QString::number(abs_time));
    ui->result_sign->setText("сек");
}

void MainWindow::on_spinBox_hour_valueChanged(int arg1)
{
    h = arg1;
}

void MainWindow::on_spinBox_min_valueChanged(int arg1)
{
    m = arg1;
}

void MainWindow::on_spinBox_sec_valueChanged(int arg1)
{
    s = arg1;
}

void MainWindow::on_spinBox_hour_2_valueChanged(int arg1)
{
    h1 = arg1;
}

void MainWindow::on_spinBox_min_2_valueChanged(int arg1)
{
    m1 = arg1;
}

void MainWindow::on_spinBox_sec_2_valueChanged(int arg1)
{
    s1 = arg1;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!flag_2)
    {
        ui->sign_label->hide();
        ui->label_9->hide();
        ui->label_10->hide();
        ui->label_12->hide();
        ui->spinBox_hour->hide();
        ui->spinBox_min->hide();
        ui->spinBox_sec->hide();

        flag_2 = 1;
        ui->pushButton_red_h->show();
        ui->pushButton_red_m->show();
        ui->pushButton_red_s->show();
        ui->show_result->show();
        flag = 0;
        ui->pushButton_equal->hide();
        ui->pushButton_minus->hide();
        ui->pushButton_plus->hide();
        ui->out_hour->hide();
        ui->out_min->hide();
        ui->out_sec->hide();
    }
    else if(flag_2)
    {
        flag_2 = 0;
        ui->pushButton_red_h->hide();
        ui->pushButton_red_m->hide();
        ui->pushButton_red_s->hide();
        ui->show_result->hide();
    }

}

void MainWindow::on_pushButton_clicked()
{
    if(!flag)
    {
        ui->sign_label->show();
        ui->label_9->show();
        ui->label_10->show();
        ui->label_12->show();
        ui->spinBox_hour->show();
        ui->spinBox_min->show();
        ui->spinBox_sec->show();

        flag = 1;
        ui->pushButton_equal->show();
        ui->pushButton_minus->show();
        ui->pushButton_plus->show();
        ui->out_hour->show();
        ui->out_min->show();
        ui->out_sec->show();
        flag_2 = 0;
        ui->pushButton_red_h->hide();
        ui->pushButton_red_m->hide();
        ui->pushButton_red_s->hide();
        ui->show_result->hide();
    }
    else if(flag)
    {
        flag = 0;
        ui->pushButton_equal->hide();
        ui->pushButton_minus->hide();
        ui->pushButton_plus->hide();
        ui->out_hour->hide();
        ui->out_min->hide();
        ui->out_sec->hide();
    }
}
