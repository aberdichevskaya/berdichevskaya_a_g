#pragma once
#ifndef CELLS_H
#define CELLS_H

#include <QPushButton>
#include <QDebug>
#include "game_state.h"

//клетка поля
class Cells : public QPushButton {
  Q_OBJECT

  int row; // Строка для этой клетки на поле
  int col; // Столбец для этой клетки на поле

  game_state* game; // Для передачи информации в "игру"

  public:
  explicit Cells(const char*, QWidget* parent, int row, int col, game_state& game);

  signals:

  public slots:
  void slotCellClicked();
};

#endif // CELLS_H
