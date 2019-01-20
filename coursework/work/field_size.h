#ifndef FIELD_SIZE_H
#define FIELD_SIZE_H

#include <QWidget>
#include <QDialog>
//размер игрового поля, вводится через диалоговое окно, описанное в этом классе
namespace Ui {
    class field_size;
}

class field_size : public QDialog {
    Q_OBJECT

public:
    explicit field_size(QWidget *parent = 0);
    ~field_size();
    int H{4}; //количество строк в игровом поле, умолчательное значение - 4
    int W{4}; //количество столбцов в поле, умолчательное значение - 4

private slots:
    void on_start_clicked(); //нажатие на кнопку - перезапуск игры с новым размером поля

private:
    Ui::field_size *ui;
};

#endif // FIELD_SIZE_H
