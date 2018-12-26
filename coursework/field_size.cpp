#include "field_size.h"
#include "ui_field_size.h"

#include <QDialog>
#include <QWidget>
#include <QMessageBox>

field_size::field_size(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::field_size) {
    ui->setupUi(this);
    ui->warning->setText("Введи числа от 1 до 10!");
}

field_size::~field_size() {
    delete ui;
}


void field_size::on_start_clicked() {
    ui->warning->setVisible(false);
    if(ui->high->text().toInt() > 10 || ui-> weight->text().toInt() > 10 ) {
        QMessageBox::critical(this, "Ошибка!", "Слишком большое поле, введи числа, не превышающие 10");
    }
    else if (ui->high->text().toInt() < 0 || ui-> weight->text().toInt() < 0 ) {
        QMessageBox::critical(this, "Ошибка!", "Так не бывает, введи числа больше 0");
    }
    else {
        H = ui->high->text().toInt();
        W = ui-> weight->text().toInt();
    }
}
