#include <ctime>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QPair>

#include "game_state.h"

game_state::game_state() {
    newGame(5, 5);
}

void game_state::mapResize(int h, int w) {
    Map.resize(h);
    for(int i = 0; i < h; i += 1) {
        Map[i].resize(w);
    }
}

void game_state::newGame(int h, int w) {
    mapResize(h, w);

    state = first_move; //Первым ходит первый игрок
    srand(time(0));
    int mult = h*w;
    for(int i = 0; i < h; i += 1) {
        for(int j = 0; j < w; j += 1) {
            Map[i][j] = (rand() % mult + 1); //Карта заполняется случайными числами
        }
    }
}

QString game_state::getStateString() {
    QString a = " ";
    switch(state) {
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

QString game_state::makeMove(int row, int col) {
    QString a = " ";
    if (Map[row][col] == 0) {
        a = "Ошибка! Эта клетка уже использована!";
    }
    switch(state) {

    case(first_move):
        if(row==last.first) {
        first_score += Map[row][col];
        moves.push_back("Первый игрок выбрал число " + QString::number(Map[row][col]));
        Map[row][col] = 0;
        state = second_move;
        a = "Первый игрок сделал ход";
        }
        else {
            a = "Ты должен выбрать клетку в этой вертикали!";
        }
        ret1 = first_score;
        ret2 = -1;
        break;

    case(second_move):
        if (col == last.second) {
        second_score += Map[row][col];
        moves.push_back("Второй игрок выбрал число " + QString::number(Map[row][col]));
        Map[row][col] = 0;
        state = first_move;
        a = "Второй игрок сделал ход";
        }
        else {
            a = "Ты должен выбрать клетку в этой горизонтали!";
        }
        ret2 = second_score;
        ret1 = -1;
        break;

    default:
        a =  "Упс! Что-то пошло не так";
        ret1 = -1;
        ret2 = -1;
        break;
    }
    last = qMakePair(row, col);
    checkGameOver();
    return a;
}


QString game_state::checkGameOver() {
    int a = 0;
    int o = 0;
    QString r = "  ";
    switch (state) {
    case(second_move):
        o = last.first;
        for (int i = 0; i < Map[o].size(); ++i) {
            if (Map[o][i] != 0) {
                a += 1;
            }
        }
        break;
    case(first_move):
        o = last.second;
        for (int i = 0; i < Map.size(); ++i) {
            if (Map[i][o] != 0) {
                a += 1;
            }
        }
        break;
    }
    if (a == 0) {
        if(first_score > second_score) {
            state = first_win;
        }
        if(first_score < second_score) {
            state = second_win;
        }
        if(first_score == second_score) {
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


















