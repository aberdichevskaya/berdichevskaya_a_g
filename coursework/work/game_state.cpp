#include <ctime>
#include <QTextStream>
#include <QString>
#include <QPair>
#include <vector>
#include <QFile>

#include "game_state.h"

game_state::game_state() {
	newGame(4, 4);
}

void game_state::mapResize(int h, int w) {
	for (int i = 0; i < Map.size(); i += 1) {
		Map[i].clear();
	}
	for (int i = 0; i < Moves.size(); i += 1) {
		Moves[i].clear();
	}
	std::vector<std::vector<int>> r(h, std::vector<int>(w, 0));
	Map = r;
	Moves = r;
}

void game_state::newGame(int h, int w) {
	mapResize(h, w);
	last = qMakePair(-1, -1);
	first_score = 0;
	second_score = 0;
	state = first_move; //Первым ходит первый игрок
	srand(time(0));
	int mult = h * w;
	for (int i = 0; i < h; i += 1) {
		for (int j = 0; j < w; j += 1) {
			Map[i][j] = (rand() % mult + 1); //Карта заполняется случайными числами
		}
	}
}

QString game_state::getStateString() { //Строка состояний игры
	QString a = " ";
	switch (state) {
	case(first_move):
		a = "Сейчас ходит первый игрок!";
		break;

	case(second_move):
		a = "Сейчас ходит второй игрок!";
		break;

	case(first_win):
		a = "Первый игрок победил!";
		break;

	case(second_win):
		a = "Второй игрок победил!";
		break;

	case(draw):
		a = "Ничья!";
		break;

	default:
		a = "Упс! Что-то пошло не так";
		break;

	}
	return a;
}

QString game_state::makeMove(int row, int col) { //совершение хода
	QString a = "";
	switch (state) {

	case(first_move):
		if ((row == last.first) || (last.first == -1)) {
			first_score += Map[row][col];
			Moves[row][col] = 1;
			state = second_move;
			a = "Первый игрок сделал ход";
			last = qMakePair(row, col);
		}
		else {
			a = "Ты должен выбрать клетку в этой горизонтали!";
		}
		ret1 = first_score;
		ret2 = -1;
		break;

	case(second_move):
		if ((col == last.second) || (last.second == -1)) {
			second_score += Map[row][col];
			Moves[row][col] = 2;
			state = first_move;
			a = "Второй игрок сделал ход";
			last = qMakePair(row, col);
		}
		else {
			a = "Ты должен выбрать клетку в этой вертикали!";
		}
		ret2 = second_score;
		ret1 = -1;
		break;

	default:
		a = "Упс! Что-то пошло не так";
		ret1 = -1;
		ret2 = -1;
		break;
	}
	checkGameOver();
	return a;
}


QString game_state::checkGameOver() { //проверка на возможность совершить следующий ход
	int a = 0;
	int o = 0;
	QString r = "";
	switch (state) {
	case(second_move):
		o = last.second;
		for (int i = 0; i < Map[o].size(); ++i) {
			if (Moves[i][o] == 0) {
				a += 1;
			}
		}
		break;
	case(first_move):
		o = last.first;
		for (int i = 0; i < Map.size(); ++i) {
			if (Moves[o][i] == 0) {
				a += 1;
			}
		}
		break;
	}
	if (a == 0) {
		if (first_score > second_score) {
			state = first_win;
		}
		if (first_score < second_score) {
			state = second_win;
		}
		if (first_score == second_score) {
			state = draw;
		}
		r = "Игра окончена!";
	}
	return r;
}

const char* game_state::getCell(int i, int j) {
	static char buf[3];
	int h = 0;
	int l = Map[i][j];
	int w = 0;
	while ((w < 3) && (l % 10 != 0)) {
		buf[3 - 1 - w] = (l % 10) - '0';
		l /= 10;
		w++;
	}
	w--;
	if (w < 2) {
		for (int j = w; j < 3; j += 1) {
			buf[3 - 1 - w] = ' ';
		}
	}
	return buf;
}


void game_state::save(QString fileName, int h, int w) {
	QFile f(fileName);
	f.open(QIODevice::WriteOnly | QIODevice::Text);
	// Сохраняем данные
	QTextStream out(&f);
	out << h << endl;
	out << w << endl;
	out << first_score << endl;
	out << second_score << endl;
	out << last.first << endl;
	out << last.second << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			out << Map[i][j] << endl;;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			out << Moves[i][j] << endl;;
		}
	}
	f.close();
}


void game_state::load(QString fileName) { // Загрузка игры
	QFile f(fileName); // Создаем объект - файл
	f.open(QIODevice::ReadOnly | QIODevice::Text); // Открываем его для чтения
	// Читаем данные
	QTextStream in(&f);
	// Считываем размер карты
	in >> hh;
	in >> ww;
	in >> first_score;
	in >> second_score;
	int a, b;
	in >> a >> b;
	last = qMakePair(a, b);
	ret1 = first_score;
	ret2 = second_score;
	mapResize(hh, ww);
	int first_cnt = 0, second_cnt = 0;

	for (int i = 0; i < hh; i++) {
		for (int j = 0; j < ww; j++) {
			in >> Map[i][j];
		}
	}
	for (int i = 0; i < hh; i++) {
		for (int j = 0; j < ww; j++) {
			in >> Moves[i][j];

			switch (Moves[i][j]) {
			case 1:
				first_cnt++;
				break;

			case 2:
				second_cnt++;
				break;

			case 0:
				break;

			default:
				throw QString("Ошибка при чтении файла %1\n: строка %2 столбец %3 символ '%4' ")
					.arg(fileName).arg(i).arg(j).arg(Map[i][j]);

			}
		}

	}

	f.close();

	if ((first_cnt >= 2) && (second_cnt == 0))
		throw QString("Все ходы - ходы первого игрока!");

	if ((first_cnt >= 2) && (second_cnt == 0))
		throw QString("Все ходы - ходы второго игрока!");

	if (first_cnt > (second_cnt + 1))
		throw QString("Слишком много ходов первого игрока");

	if (second_cnt > (first_cnt + 1))
		throw QString("Слишком много ходов второго игрока");

	if (first_cnt > second_cnt)
		state = second_move;
	else
		state = first_move;

	checkGameOver();
}

















