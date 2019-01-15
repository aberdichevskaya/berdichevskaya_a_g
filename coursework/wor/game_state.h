#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <QString>
#include <vector>
#include <QPair>
#include <QString>

enum State {
  first_move,
  second_move,
  first_win,
  second_win,
  draw
};

class game_state {
private:
    int first_score {0};
    int second_score{0};
    State state;
	QPair <int, int> last = qMakePair(-1, -1);
public:
	std::vector<std::vector<int>> Map;
    game_state();
    void mapResize(int h, int w); // Присвоение карте размерa
    void newGame(int h, int w); // Новая игра без пересоздания объекта
    QString getStateString(); //состояниe игры
    QString makeMove(int row, int col);  // Совершаем ход
    QString checkGameOver();  // Проверяем на окончание игры
    const char* getCell(int i, int j);   // Состояние ячейки
    int ret1{0};
    int ret2{0};
  };

#endif // GAME_STATE_H
