#ifndef FIELD_SIZE_H
#define FIELD_SIZE_H

#include <QWidget>
#include <QDialog>

namespace Ui {
    class field_size;
}

class field_size : public QDialog {
    Q_OBJECT

public:
    explicit field_size(QWidget *parent = 0);
    ~field_size();
    int H{4};
    int W{4};

private slots:
    void on_start_clicked();

private:
    Ui::field_size *ui;
};

#endif // FIELD_SIZE_H
