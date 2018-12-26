

//иконки не отображаются



#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QApplication>
#include <QDialog>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field_size.h"

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_getSize_clicked() {
    field_size gt(this);
    gt.setModal(true);
    gt.exec();
    h = gt.H;
    w = gt.W;
    newGame();
}

void MainWindow::status_string() {
    QString b = game.getStateString();
    ui->game_status->setText(b);
    if(game.ret1 != -1) {
    ui->first_score->setText(QString::number(game.ret1));
    }
    if(game.ret2 != -1) {
        ui->first_score->setText(QString::number(game.ret1));
    }
}

void MainWindow::resize_buttons() {
    cells_.resize(h);
    for(int i = 0; i < h; i+=1) {
        cells_[i].resize(w);
    }
}

void MainWindow::update_buttons() {
    int cellSize_w = 200 / w; // ширина кнопки
    int cellSize_h = 300 / h; // высота кнопки
    int cellSpase = 6; // Расстояние между кнопками
    int topSpace = 80; // Отступ сверху
    int leftSpace = 50; // Отступ слева
    int randOffset = 5;
    for (int i; i < cells_.size(); i += 1) {
        for (int j = 0; j < cells_[i].size(); j += 1) {
            if (cells_[i][j] != NULL) {
                delete cells_[i][j];
            }
        }
    }
    resize_buttons();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cells_[i][j] = new Cells(game.getCell(i, j), this, i, j, game);
            // Задаём размеры и положение кнопки
            cells_[i][j]->setGeometry(
                (cellSize_w + cellSpase) * j + leftSpace + (rand() % randOffset),
                (cellSize_h + cellSpase) * i + topSpace + (rand() % randOffset),
                cellSize_w,
                cellSize_h
            );
            cells_[i][j]->setVisible(true);
            connect(cells_[i][j], SIGNAL(clicked()), cells_[i][j], SLOT(slotCellClicked()));
            connect(cells_[i][j], SIGNAL(clicked()), this, SLOT(status_string()));
        }
    }
}

void MainWindow::newGame() {
    game.newGame(h, w);
    status_string();
    update_buttons();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    resize_buttons();
    for(int i = 0; i < h; i += 1) {
        for(int j = 0; j < w; j += 1) {
          cells_[i][j] = NULL;
        }
    }
    newGame(); //начало игры
}


void MainWindow::on_exit_game_triggered() {
    QApplication::quit();
}


