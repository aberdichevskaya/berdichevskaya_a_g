#include <QString>
#include <QMessageBox>

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
}

// При нажатии на клетку
void Cells::slotCellClicked() {
  QString a = game->makeMove(row, col);
  if ((a == "Первый игрок сделал ход") || (a == "Второй игрок сделал ход")) {
	  setEnabled(false);
  }
  else {
	  QMessageBox::warning(this, "Аккуратнее!", a);
  }
}
