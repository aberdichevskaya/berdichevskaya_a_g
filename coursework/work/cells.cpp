#include <QString>
#include <QMessageBox>

#include "cells.h"

Cells::Cells(const char* text, QWidget* parent, int row, int col, game_state& game)
	: QPushButton(text, parent)
	, row(row)
	, col(col)
	, game(&game) {

}

// При нажатии на клетку
void Cells::slotCellClicked() {
	QString a = game->makeMove(row, col);

	if (a == "Первый игрок сделал ход") {
		setStyleSheet("color: green");
		setProperty("currentState", 1);
		setEnabled(false);

	}
	else if (a == "Второй игрок сделал ход") {
		setStyleSheet("color: red");
		setProperty("currentState", 0);
		setEnabled(false);

	}
	else {
		QMessageBox::warning(this, "Аккуратнее!", a);
	}
}
