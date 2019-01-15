#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>  //стоит использовать его или std::vector?
#include <QDialog>

#include "cells.h"
#include "game_state.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resize_buttons();
    void exit_application();
    int h{4};
    int w{4};

private slots:
    void status_string();
    void newGame();
    void on_getSize_clicked();
    void on_exit_game_triggered();

private:
    Ui::MainWindow *ui;
    game_state game;
    std::vector<std::vector<Cells*>> cells_;
    void update_buttons();
};

#endif // MAINWINDOW_H
