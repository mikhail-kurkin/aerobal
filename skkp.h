#ifndef SKKP_H
#define SKKP_H

#include <QMainWindow>
#include <QApplication>
#include <QTime>
#include <math.h>

#define   Mu        398600.44
#define   Omega_Zem .7292115085e-4
#define R_Zem     6378.137
#define   E_Zem     3.3528e-3
#define   GR        M_PI/180.
#define   RG        180./M_PI
#define   Eps       2.634e10
#define   PI        3.1415926535 8979323846
#define O_LAND    7.2921158e-5
#define R_LAND    6378.137
#define G0        9.80665
#define cos70     0.342020143325669

#define  sign(x) (((x)<0)?(-1):(1))

//float m;//звездная велечина

namespace Ui {
class skkp;
}

class skkp : public QMainWindow
{
    Q_OBJECT

public:
    explicit skkp(QWidget *parent = 0);
    ~skkp();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::skkp *ui;
};

#endif // SKKP_H



