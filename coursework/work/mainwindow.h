#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>  
#include <QDialog>

#include "cells.h"
#include "game_state.h"
//основное окно иры
namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void resize_buttons(); //изменение размера игрового поля
	void exit_application();
	int h{ 4 }; //количество строк игрового поля, умолчательное - 4
	int w{ 4 }; //количество столбцов игрового поля, умочательное - 4

private slots:
	void status_string(); //состояние игрового поля после совершения каждого хода
	void newGame(); //запуск новой игры без перезапуска программы
	void on_getSize_triggered(); //вызов диалогового окна для ввода нового размера
	void on_exit_game_triggered(); //выход из игры
	void on_new_new_game_triggered(); //перезапуск игры
	void on_saveGame_clicked(); //сохранение текущей игры
	void on_loadGame_clicked(); //загрузка сохранённой игры

private:
	Ui::MainWindow *ui;
	game_state game; //состояние и ход игры
	std::vector<std::vector<Cells*>> cells_; //игровое поле, состоящее из клеток-кнопок
	void update_buttons(); //создание/изменение поля клеток
};

#endif // MAINWINDOW_H
