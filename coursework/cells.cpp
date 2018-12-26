#include "cells.h"

// Параметры:
//  text - текст на кнопке
//  parent - окно, в котором кнопка будет расположена
//    для корретного удаления кнопки
//  row - строка, col - столбец на поле
//  game - ссылка на игру
Cells::Cells(const char* text, QWidget* parent, int row, int col,game_state& game)
    : QPushButton(text, parent)
    , row(row)
    , col(col)
    , game(&game) {
  if(text[0] == '0')
    setEnabled(false);
}

// При нажатии на клетку
void Cells::slotCellClicked() {
  qDebug() << "row = " << row << "   col = " << col; //координаты нажатия
  setText( game->makeMove(row, col) );
  setEnabled(false);
}
