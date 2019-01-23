
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QApplication>
#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field_size.h"

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_getSize_clicked() {
    if(ui->hight->text().toInt() > 10 || ui-> weight->text().toInt() > 10 ) {
        QMessageBox::critical(this, "Ошибка!", "Слишком большое поле, введи числа, не превышающие 10");
    }
    else if (ui->hight->text().toInt() < 0 || ui-> weight->text().toInt() < 0 ) {
        QMessageBox::critical(this, "Ошибка!", "Так не бывает, введи числа больше 0");
    }
    else {
        w = ui-> weight->text().toInt();
        h = ui->hight->text().toInt();
    }
    newGame();
	ui->first_score->setText("0");
	ui->second_score->setText("0");
}

void MainWindow::status_string() { //вид поля после совершения хода
	this->resize(700, 500);
    QString b = game.getStateString();
    ui->game_status->setText(b);
	ui->game_status->resize(250, 30);
	int windowSize = this->geometry().width();
	QRect rect = ui->game_status->geometry();
    if(game.ret1 != -1) {
		ui->first_score->setText(QString::number(game.ret1)); 
		rect = ui->first_score->geometry();
		rect.moveRight(rect.width() + 50);
		rect.moveTop(75);
		ui->first_score->setGeometry(rect);
    }
    if(game.ret2 != -1) {
        ui->second_score->setText(QString::number(game.ret2));
		rect = ui->second_score->geometry();
		rect.moveLeft(windowSize - rect.width() - 200);
		rect.moveTop(75);
		ui->second_score->setGeometry(rect);
	}
	rect = ui->game_status->geometry();
	rect.moveLeft(windowSize - rect.width() - 10);
	ui->game_status->setGeometry(rect);

    ui->getSize->resize(135, 30);
    rect = ui->getSize->geometry();
    rect.moveRight(145);
	ui->getSize->setGeometry(rect);

    ui->saveGame->resize(250, 30);
    rect = ui->game_status->geometry();
    rect.moveBottom(320);
    ui->saveGame->setGeometry(rect);
    ui->loadGame->resize(250, 30);
    rect.moveBottom(370);
    ui->loadGame->setGeometry(rect);

    ui->hight->resize(30,30);
    ui->weight->resize(30,30);
    rect = ui->hight->geometry();
    rect.moveRight(55);
    rect.moveTop(255);
    ui->hight->setGeometry(rect);
    rect.moveRight(125);
    ui->weight->setGeometry(rect);
}

void MainWindow::resize_buttons() { //задание размера ассиву клеток
    cells_.resize(h);
    for(int i = 0; i < h; i+=1) {
        cells_[i].resize(w);
    }
}

void MainWindow::update_buttons() {
    int cellSize_w = 200 / w; // ширина кнопки
    int cellSize_h = 300 / h; // высота кнопки
    int cellSpase = 6; // Расстояние между кнопками
    int topSpace = 90; // Отступ сверху
    int leftSpace = 180; // Отступ слева
    int randOffset = 5;
    for (int i = 0; i < cells_.size(); i += 1) {
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
                (cellSize_w + cellSpase) * j + leftSpace ,
                (cellSize_h + cellSpase) * i + topSpace,
                cellSize_w,
                cellSize_h
            );
            cells_[i][j]->setVisible(true);
			cells_[i][j]->setText(QString::number(game.Map[i][j]));
            connect(cells_[i][j], SIGNAL(clicked()), cells_[i][j], SLOT(slotCellClicked())); //нажатие на каждую клетку будет вызывать слот status_string
            connect(cells_[i][j], SIGNAL(clicked()), this, SLOT(status_string()));
        }
    }
}

void MainWindow::newGame() { //новая игра
    game.newGame(h, w);
	game.ret1 = 0;
	game.ret2 = 0;
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



void MainWindow::on_exit_game_triggered() { //выход из игры
    QApplication::quit();
}

void MainWindow::on_new_new_game_triggered() {
    h = 4;
    w = 4;
    newGame();
    ui->first_score->setText("0");
    ui->second_score->setText("0");
}

void MainWindow::on_saveGame_clicked()  { // Сохранить игру в файл
    QString filename = QFileDialog::getSaveFileName(
                         this, "Сохранить игру", "",
                         "Игра Максит (*.txt)");

    if(filename.isEmpty()) {
      return;
    }

    game.save(filename, h, w);
}


void MainWindow::on_loadGame_clicked() {
    QString filename = QFileDialog::getOpenFileName(
                           this, "Загрузить игру", "",
                           "Игра Максит (*.txt)");

    try {
        game.load(filename);
      }
    catch(QString q) {
        QMessageBox::critical(this,
                              QString("Ошибка при чтении файла"),
                              q);
      }
    h = game.hh;
    w = game.ww;
    status_string();
    update_buttons();
    for(int i = 0; i < h; i+=1) {
        for(int j = 0; j < w; j += 1) {
            if(game.Moves[i][j] < 0) {
                if(game.Moves[i][j] == -1) {
                    cells_[i][j]->setStyleSheet("color: green");
                    cells_[i][j]->setProperty("currentState", 1);
                    cells_[i][j]->setEnabled(false);
                }
                if(game.Moves[i][j] == -2) {
                    cells_[i][j]->setStyleSheet("color: red");
                    cells_[i][j]->setProperty("currentState", 0);
                    cells_[i][j]->setEnabled(false);
                }
            }
        }
    }
}



