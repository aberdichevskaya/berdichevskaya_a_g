#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <QString>
#include <vector>
#include <QPair>
#include <QString>
//здесь описывается состояние и процесс игры
enum State { //список возможных состояний игры
	first_move, //ход первого игрока
	second_move, //ход второго игрока
	first_win, //победа первого игрока
	second_win, //победа второго игрока
	draw //ничья
};

class game_state {
private:
	int first_score{ 0 }; //счет первого игрока
	int second_score{ 0 }; //счет второго игрока
	State state; //состояние игры
	QPair <int, int> last = qMakePair(-1, -1); //клетка, в которую был совершён последний ход
public:
	std::vector<std::vector<int>> Map; //карта игры, заполненная случайными числами
	std::vector<std::vector<int>> Moves; //карта игры, на которой отмечаются уже использованные клетки
	game_state(); //конструктор
	void mapResize(int h, int w); // Присвоение карте размерa
	void newGame(int h, int w); // Новая игра без пересоздания объекта
	QString getStateString(); //состояние игрового поля 
	QString makeMove(int row, int col);  // Совершаем ход
	QString checkGameOver();  // Проверка на окончание игры
	const char* getCell(int i, int j);   // Состояние ячейки
	void save(QString fileName, int h, int w); //Сохранение игры
	void load(QString fileName); //загрузка игры из файла
	int ret1{ 0 }; //счет первого для вывода на экран
	int ret2{ 0 }; //счет второго для вывода на экран
	int hh{ 4 }; //размер
	int ww{ 4 }; //размер
};

#endif // GAME_STATE_H
