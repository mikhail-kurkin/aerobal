#include "skkp.h"
#include "ui_skkp.h"
#include "tel.h"

#include <iostream>

using namespace std;

void   xyz_stw(double *xyz, double *alfa, double *stw);
void   stw_xyz(double *stw, double *alfa, double *xyz);
void   Add_Error(double t_meeting, double *stw_err, double *rvt);
void   Proportion(double prir_Vhar, double *stw_har);
void   ImagePlot(double *xyz_p, double xyz_c[], double result[][3], int prinadlejnost);
void ImagePlot(double xyz_p[], double xyz_c[], double result[][3], int prinadlejnost);


void  pr(double *bx1,int id,int ip,double h,double tu,double *bx2);
void  pr1(double *y,double *th,double *t,double *h,int *ip,double *u,int *id);
void  pu(double *r,double *p);
void  pv(double *p,double *r,int i);
double aasin(double x,double b);


void  alfa_beta_gamma(double i,double Om,double u,double *alfa);
void  rvt_xyz(double *rvt, double *xyz);
double  cratan(double s,double c);
void  filambdah(double *rvt, double *fl);
double  arg(double x);
void  xyz_xyzG(double *xyz, double *xyz_g);
void  rvt_hahp(double *r,double *ha, double *hp);
int   xyz_rvt (double *xyz,double *rvt );
int   xyz_iOmu(double*xyz,double*i,double*Om,double*u);
void mod_du(void);
void RIMX(void);
float star_def(float n_t, float n_v, float delt_t, float tetta);

FILE *out_cxyz;
FILE *out_pxyz;

FILE *out_x;
FILE *out_y;
FILE *out_z;

FILE *out_cpt;
FILE *out_cpx;
FILE *out_cpy;
FILE *out_cpz;
FILE *out_c;
FILE *out_p;
FILE *D;
FILE *Plot;
FILE *eps;
FILE *f_wa;
FILE *f_d;
FILE *tel;

float tm;

double f1[6];
double arg_and, Step_By_Time, T0, Tk;
double rvt_c[7], xyz_c[6], flh_c[3], stw[6], stw_p[6];
double rvt_p[7], xyz_p[6], flh_p[3];
double d_xyz[6];
double alfa[9];// м триц  пересчет
int    exact, regim;
double step;
double D_abs, D_osk;
double Vs_osk;
double result[4][3];
int prinadlejnost;
double ds,dt,dw, Ws, Ww, Wt;
double dx,dy,dz;
int i;


double Mvx,
       Mvy,
       Mvz;

double Ix=3500,
       Iy=2100,
       Iz=1900,
       Im;


double Purd,
       Lm,
       Murd;
int a1,
    a0,
    a1_2,
    a0_2;
double Mt;

double uskor_max;

double w[3];

double fi[3],
       dfi[3],
       dom[3],
       f[3];

int priz_sso,
    priz_raz[3];

double dtau=0.5;

int i_dk;//номер ДК;
double L_dk[3]; //плечи по осям
double Mdk[6][3],//моменты от ДК
       Fdk[6][3];//силы от ДК
double R_DKc, R_DK=0;
double Tdk_vkl[6], Tdk_vukl[6];

const double
            Pvxkn = 8.0, // давление на входе ДК
            Pvxmn = 8.0; // давление на входе ДМ

double Rk_dk[8]; // максимальная тяга ДK[i] [гс]

const double Mpoln = 4000.00;
const double Mas0 = 4000.00;
const double Msux  = 2100.0;


//МИХ КА после отделения от РБ (СБ, антенны и КРТ раскрыты)
const double Jx_poln =3500.0, Jy_poln =2100.0, Jz_poln =1900.0,
             Jyz_poln=108.6, Jzx_poln=-13.7, Jxy_poln=-34.2;

//МИХ сухого КА
const double Jx_sux =1300.0, Jy_sux =1100.0, Jz_sux =900.0;

double
Mas;    //[кг] Текущая масса КА на i-м и i+1-м шаге

double
del_tp1k = 0.06;// время выхода тяги на уровень Rk_dk[i]/

double
dMas_dk_sum;   //[кг] Текущий расход массы от всех ГД

double b = 0.0083333333333333; //30"

float m;

float costet;

skkp::skkp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::skkp)
{
    ui->setupUi(this);
       ui->listWidget->insertItem(0,QString(trUtf8(" ")));
       ui->listWidget->insertItem(1,QString(trUtf8(" ")));
       ui->listWidget->insertItem(2,QString(trUtf8(" ")));
       ui->listWidget->insertItem(3,QString(trUtf8(" ")));
       ui->listWidget->insertItem(4,QString(trUtf8(" ")));
       ui->listWidget->insertItem(5,QString(trUtf8(" ")));
       ui->listWidget->insertItem(6,QString(trUtf8(" ")));
       ui->listWidget->insertItem(7,QString(trUtf8(" ")));
       ui->listWidget->insertItem(8,QString(trUtf8(" ")));
       ui->listWidget->insertItem(9,QString(trUtf8(" ")));
       ui->listWidget->insertItem(10,QString(trUtf8(" ")));
       ui->listWidget->insertItem(11,QString(trUtf8(" ")));


       ui->listWidget_2->insertItem(0,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(1,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(2,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(3,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(4,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(5,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(6,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(7,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(8,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(9,QString(trUtf8(" ")));
       ui->listWidget_2->insertItem(10,QString(trUtf8(" ")));

       /*
       ui->listWidget_3->insertItem(0,QString(trUtf8(" ")));
       ui->listWidget_3->insertItem(1,QString(trUtf8(" ")));
       ui->listWidget_3->insertItem(2,QString(trUtf8(" ")));
       ui->listWidget_3->insertItem(3,QString(trUtf8(" ")));
       ui->listWidget_3->insertItem(4,QString(trUtf8(" ")));
       */

       ui->listWidget_4->insertItem(0,QString(trUtf8(" ")));
       ui->listWidget_4->insertItem(1,QString(trUtf8(" ")));
       ui->listWidget_4->insertItem(2,QString(trUtf8(" ")));
       ui->listWidget_4->insertItem(3,QString(trUtf8(" ")));
       ui->listWidget_4->insertItem(4,QString(trUtf8(" ")));
       ui->listWidget_4->insertItem(5,QString(trUtf8(" ")));
       ui->listWidget_4->insertItem(6,QString(trUtf8(" ")));
       ui->listWidget_4->insertItem(7,QString(trUtf8(" ")));




       ui->listWidget->item(0)->setText(QString(trUtf8("Спутник:")));
       ui->listWidget->item(1)->setText(QString(trUtf8("Текущий радиус-вектор:%1 км")).arg(rvt_c[0]));
       ui->listWidget->item(2)->setText(QString(trUtf8("Скорость:%1 км/с")).arg(rvt_c[1]));
       ui->listWidget->item(3)->setText(QString(trUtf8("Угол наклона вектора скорости к местному горизонту:%1 рад")).arg(rvt_c[2]));
       ui->listWidget->item(4)->setText(QString(trUtf8("Наклонение плоскости орбиты:%1 рад")).arg(rvt_c[3]));
       ui->listWidget->item(5)->setText(QString(trUtf8("Долгота восходящего узла:%1 рад")).arg(rvt_c[4]));
       ui->listWidget->item(6)->setText(QString(trUtf8("Аргумент широты:%1 рад")).arg(rvt_c[5]));
       ui->listWidget->item(7)->setText(QString(trUtf8("Текущее время:%1 с")).arg(rvt_c[6]));
    // ui->listWidget->item(8)->setText(QString(trUtf8("Составляющие угловой скорости:%1 %2 %3 рад")).arg(fi[0]*RG).arg(fi[1]*RG).arg(fi[2]*RG));



       ui->listWidget_2->item(0)->setText(QString(trUtf8("Цель:")));
       ui->listWidget_2->item(1)->setText(QString(trUtf8("Текущий радиус-вектор:%1 км")).arg(rvt_p[0]));
       ui->listWidget_2->item(2)->setText(QString(trUtf8("Скорость:%1 км/с")).arg(rvt_p[1]));
       ui->listWidget_2->item(3)->setText(QString(trUtf8("Угол наклона вектора скорости к местному горизонту:%1 рад")).arg(rvt_p[2]));
       ui->listWidget_2->item(4)->setText(QString(trUtf8("Наклонение плоскости орбиты:%1 рад")).arg(rvt_p[3]));
       ui->listWidget_2->item(5)->setText(QString(trUtf8("Долгота восходящего узла:%1 рад")).arg(rvt_p[4]));
       ui->listWidget_2->item(6)->setText(QString(trUtf8("Аргумент широты:%1 рад")).arg(rvt_p[5]));
       ui->listWidget_2->item(7)->setText(QString(trUtf8("Текущее время:%1 с")).arg(rvt_p[6]));

       /*
       ui->listWidget_3->item(0)->setText(QString(trUtf8("Координаты области поля зрения:")));
       ui->listWidget_3->item(1)->setText(QString(trUtf8("%1 %2 %3")).arg(result[0][0]).arg(result[0][1]).arg(result[0][2]));
       ui->listWidget_3->item(2)->setText(QString(trUtf8("%1 %2 %3")).arg(result[1][0]).arg(result[1][1]).arg(result[1][2]));
       ui->listWidget_3->item(3)->setText(QString(trUtf8("%1 %2 %3")).arg(result[2][0]).arg(result[2][1]).arg(result[2][2]));
       ui->listWidget_3->item(4)->setText(QString(trUtf8("%1 %2 %3")).arg(result[3][0]).arg(result[3][1]).arg(result[3][2]));
       */

       //ui->listWidget_4->item(0)->setText(QString(trUtf8("Величина составляющих текущего промаха в ОСК перехватчика:")));
       //ui->listWidget_4->item(1)->setText(QString(trUtf8("%1 %2 %3")).arg(dt).arg(ds).arg(dw));
       ui->listWidget_4->item(0)->setText(QString(trUtf8("Дистанция спутник-цель:")));
       ui->listWidget_4->item(1)->setText(QString(trUtf8("%1 км")).arg(D_abs));





}

skkp::~skkp()
{
    delete ui;
}

void skkp::on_pushButton_clicked()
{
/*
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
     scene->addText("fi(t)");

        QPen pen(Qt::green);
        QPen pen2(Qt::blue);
        */
   /*
   - текущий радиус-вектор
   - скорость
   - угол наклона вектора скорости к местному горизонту
   - наклонение плоскости орбиты
   - долгота восходящего узла
   - аргумент широты
   - текущее время
   */
     out_cxyz = fopen("chel.txt", "wt");
     out_pxyz = fopen("sputnik.txt", "wt");

     out_x = fopen("x.txt", "wt");
     out_y = fopen("y.txt", "wt");
     out_z = fopen("z.txt", "wt");


     out_cpt = fopen("pologenie cheli v osk sputnikat.txt", "wt");
     out_cpx = fopen("pologenie cheli v osk sputnikax.txt", "wt");
     out_cpy = fopen("pologenie cheli v osk sputnikay.txt", "wt");
     out_cpz = fopen("pologenie cheli v osk sputnikaz.txt", "wt");

     out_c = fopen("pologenie cheli.txt", "wt");
     out_p = fopen("pologenie sputnika.txt", "wt");
     D = fopen("Distanchiya sputnik-chel.txt", "wt");
     Plot = fopen("koordinaty.txt", "wt");
     eps = fopen("oshibki.txt", "wt");
     f_wa = fopen("Wa.bin", "wb");
     f_d = fopen("D.bin", "wb");
     tel = fopen("tel.txt", "wb");

     fprintf(out_c,"R, км||V, км/с||Tet, рад||I, рад||Omega, рад||U, рад||T, с\n");
     fprintf(out_p,"R, км||V, км/с||Tet, рад||I, рад||Omega, рад||U, рад||T, с\n");
     //fprintf(ImagePlot,"\n");
     fprintf(eps,"T||dt||ds||dw\n");

     rvt_c[0]=ui->doubleSpinBox_9->value();
     rvt_c[1]=ui->doubleSpinBox_10->value();
     rvt_c[2]=ui->doubleSpinBox_11->value();
     rvt_c[3]=ui->doubleSpinBox_2->value();
     rvt_c[4]=ui->doubleSpinBox_3->value();
     rvt_c[5]=ui->doubleSpinBox_4->value();
     rvt_c[6]=ui->doubleSpinBox_12->value();

     rvt_p[0]=ui->doubleSpinBox_13->value();
     rvt_p[1]=ui->doubleSpinBox_14->value();
     rvt_p[2]=ui->doubleSpinBox_15->value();
     rvt_p[3]=ui->doubleSpinBox_6->value();
     rvt_p[4]=ui->doubleSpinBox_7->value();
     rvt_p[5]=ui->doubleSpinBox_8->value();
     rvt_p[6]=ui->doubleSpinBox_12->value();

     T0=rvt_p[6];
     Tk=ui->doubleSpinBox_16->value();

      regim=0;//0 - прогноз по времени, 1 - прогноз по аргументу широты
      exact=2;
      step=1.;

      Step_By_Time=1;

      Mvx = 0;
      Mvy = 0;
      Mvz = 0;

   //   Ix = 3500;
   //   Iy = 2100;
   //   Iz = 1900;
      Im = 20;

      Purd = 0.5;
      Lm = 1.7;
      L_dk[0]=2.0;
      L_dk[1]=1.7;
      L_dk[2]=0;
      Murd=0.006;

      a1 = 40;
      a0 = 10;
      a1_2 = 2;
      a0_2 = 1;

      Mt = 20;

      uskor_max = 1;


      for(i=0;i<3;i++)
      {
       w[i]=0;
       fi[i]=0;
       dfi[i]=0;
       dom[i]=0;
       f[i]=0;
       priz_raz[i]=0;
      }

      priz_sso=0;

     conf();

        if(true)
        for(arg_and=rvt_c[6];arg_and<Tk;arg_and+=Step_By_Time)
        {


            mod_du();
            RIMX();
        //прог­оз п р метров движе­ия цели и перехв тчик  с ш гом StepByTime

            cout << rvt_c[0];
         pr(rvt_c, exact, regim, step, arg_and, rvt_c);
         pr(rvt_p, exact, regim, step, arg_and, rvt_p);

         //пересчет из rvtetiOu to xyzVxVyVz в  бсолют­ой ГСК
         rvt_xyz(rvt_c, xyz_c);//Про цедура пересчета из орбитальной СК в абсолютную геоцентрическую СК
         rvt_xyz(rvt_p, xyz_p);//Процедура пересчета из орбитальной СК в абсолютную геоцентрическую СК
         ImagePlot(xyz_p, xyz_c, result, prinadlejnost);

         //положе­ие цели от­оситель­о перехв тчик  в ГСК
         for(i=0; i<6; i++) d_xyz[i]=xyz_c[i]-xyz_p[i];

         //м триц  переход  из ГСК в STW перехв тчик
         alfa_beta_gamma(rvt_p[3], rvt_p[4], rvt_p[5], alfa);

         //положе­ие цели в орбит ль­ой системе коорди­ т перехв тчик
         xyz_stw(d_xyz, alfa,stw);

         xyz_stw(xyz_p, alfa,stw_p);

         filambdah(rvt_c, flh_c);//Процедура пересчета из орбитальной СК в географическую
         filambdah(rvt_p, flh_p);//Процедура пересчета из орбитальной СК в географическую
         //ВХОД
         //rvt[0] R радиус-вектор, км
         //rvt[1] V скорость, км/с
         //rvt[2] Tet угол наклона вектора скорости к линии местного горизонта, рад
         //rvt[3] I наклонение орбиты, рад
        // rvt[4] Omega долгота восходящего узла, рад
         //rvt[5] U аргумент широты, рад
         //rvt[6] T момент времени, на который определены орбитальные параметры, с
        // ВЫХОД
         //fl[0] – широта подспутниковой точки, рад
         //fl[1] – долгота подспутниковой точки, рад
         //fl[2] – высота объекта над поверхностью Земли, км


         if(arg_and==rvt_c[6]) {
             setFirstly();
         }


         D_abs = sqrt((xyz_c[0]-xyz_p[0])*(xyz_c[0]-xyz_p[0])+
              (xyz_c[1]-xyz_p[1])*(xyz_c[1]-xyz_p[1])+
              (xyz_c[2]-xyz_p[2])*(xyz_c[2]-xyz_p[2]));

         D_osk = sqrt(stw[0]*stw[0] + stw[1]*stw[1] + stw[2]*stw[2]);/*Дальность до цели*/
         Vs_osk = sqrt(stw[3]*stw[3] + stw[4]*stw[4] + stw[5]*stw[5]);
         //расчет составляющих текущего промаха в ОСК перехватчика
         if(D_abs>1000)
         {
         /*dY*/	 ds = (stw[2]*stw[4] - stw[1]*stw[5])/Vs_osk;
         /*dX*/	 dt = (stw[0]*stw[5] - stw[2]*stw[3])/Vs_osk;
         /*dZ*/   dw = (stw[1]*stw[3] - stw[0]*stw[4])/Vs_osk;

         /*
         if((dt/stw[0])>= 1 || (dt/stw[0])<=-1)
         {dx=0;}
         else{dx = asin(dt/stw[0]);}

         if((ds/stw[2])>= 1 || (ds/stw[2])<=-1)
         {dy=0;}
         else{dy = asin(ds/stw[2]);}

         if((dw/stw[1])>= 1 || (dw/stw[1])<=-1)
         {dz=0;}
         else{ dz = asin(dw/stw[1]);}
         fi[0]=dx;
         fi[1]=dy;
         fi[2]=dz;
         */

             //расчет составляющих угловой скорости вращения ЛВ цели по осям STW
                  Ws = dw * Vs_osk/D_osk/D_osk;
                  Ww = ds * Vs_osk/D_osk/D_osk;

                  dfi[0]=Ws;
                  dfi[1]=Ww;
         }

        // end ballistic
        // //////////////////////СИСТЕМА ОРИЕНТАЦИИ и СТАБИЛИЗАЦИИ
         if(D_abs<1000)
         {

             if (priz_raz[0]==0)
             {

                 dom[0] = a0 * fi[0]+a1 * dfi[0];
                 fi[0] = fi[0]+dtau * dfi[0];
                 dfi[0] = dfi[0] + dtau * (((Gdrive.real_moment) / Ix) - (Mt / Ix) * dom[0]);
                 w[0] = w[0] + dtau * dom[0];


                 if(w[0] == 900)
                 {
                     priz_raz[0]=1;
                 }
             }

             if (priz_raz[0]==1)
             {
                 f[0] = a0_2 * fi[0] + a1_2 * dfi[0];
                 dfi[0] = dfi[0] + dtau * ((Mt / Ix) + ((M_tel[0]) / Ix) - ((Murd*f[0])));
                 fi[0] = fi[0] + dtau * dfi[0];
                 w[0] = w[0]- dtau * uskor_max;

                 if(w[0] == 0)
                 {
                     priz_raz[0]=0;
                 }
             }

             if (priz_raz[1]==0)
             {

                 dom[1] = a0 * fi[1]+a1 * dfi[1];
                 fi[1] = fi[1]+dtau * dfi[1];
                 dfi[1] = dfi[1] + dtau * (((M_tel[1]) / Iy) - (Mt / Iy) * dom[1]);
                 w[1] = w[1] + dtau * dom[1];


                 if(w[1] == 900)
                 {
                     priz_raz[1]=1;
                 }
             }

             if (priz_raz[1]==1)
             {
                 f[1] = a0_2 * fi[1] + a1_2 * dfi[1];
                 dfi[1] = dfi[1] + dtau * ((Mt / Iy) + ((M_tel[2]) / Iy) - ((Mdk[i_dk][0]*f[1])));
                 fi[1] = fi[1] + dtau * dfi[1];
                 w[1] = w[1]- dtau * uskor_max;

                 if(w[1] == 0)
                 {
                     priz_raz[1]=0;
                 }
             }
/*
             if (priz_raz[2]==0)
             {
                 dom[2] = a0 * fi[2]+a1 * dfi[2];
                 fi[2] = fi[2]+dtau * dfi[2];
                 dfi[2] = dfi[2] + dtau * (((Mvz) / Iz) - (Mt / Iz) * dom[2]);
                 w[2] = w[2] + dtau * dom[2];

                 if(w[2] == 900)
                 {
                     priz_raz[2]=1;
                 }
             }

             if (priz_raz[2]==1)
             {
                 f[2] = a0_2 * fi[2] + a1_2 * dfi[2];
                 dfi[2] = dfi[2] + dtau * ((Mt / Iz) + ((Mvz) / Iz) - ((Murd*f[2])));
                 fi[2] = fi[2] + dtau * dfi[2];
                 w[2] = w[2]- dtau * uskor_max;

                 if(w[2] == 0)
                 {
                     priz_raz[2]=0;
                 }
             }
*/
             /*
             dt=sin(fi[0])*stw[0];
             ds=sin(fi[1])*stw[1];
             dw=sin(fi[2])*stw[2];
             */

             ds=dfi[1]/(Vs_osk/D_osk/D_osk);
             dw=dfi[0]/(Vs_osk/D_osk/D_osk);
             dt = (stw[0]*stw[5] - stw[2]*stw[3])/Vs_osk;
         }
         // /////////////////////Система стаб и ориентации КОНЕЦ
         // ///////////////////// Кардан
         set(d_xyz[0],d_xyz[1],d_xyz[2],Step_By_Time);
         // end

costet=((rvt_p[0]*rvt_p[0]-D_abs*D_abs-rvt_c[0]*rvt_c[0])/(2*D_abs*rvt_c[0]));
m=star_def(rvt_p[0],rvt_c[0],D_abs,costet);

         QTime time;
         time.start();
         for(;time.elapsed() < 1;)
         {

         }

                 tm = (float)arg_and;
                 fwrite(&tm, 4, 1, f_wa);
                 tm = (float)dfi[0];
                 fwrite(&tm, 4, 1, f_wa);
                 tm = (float)dfi[1];
                 fwrite(&tm, 4, 1, f_wa);



                 tm = (float)arg_and;
                 fwrite(&tm, 4, 1, f_d);
                 tm = (float)D_abs;
                 fwrite(&tm, 4, 1, f_d);

       //  if(fi[0]<-b&&fi[0]>b)
       //      fi[0]=0;
       //  if(fi[1]<-b&&fi[1]>b)
       //      fi[1]=0;
      ui->listWidget->item(0)->setText(QString(trUtf8("Спутник:")));
      ui->listWidget->item(1)->setText(QString(trUtf8("Текущий радиус-вектор:%1 км")).arg(rvt_c[0]));
      ui->listWidget->item(2)->setText(QString(trUtf8("Скорость:%1 км/с")).arg(rvt_c[1]));
      ui->listWidget->item(3)->setText(QString(trUtf8("Угол наклона вектора скорости к местному горизонту:%1 рад")).arg(rvt_c[2]));
      ui->listWidget->item(4)->setText(QString(trUtf8("Наклонение плоскости орбиты:%1 рад")).arg(rvt_c[3]));
      ui->listWidget->item(5)->setText(QString(trUtf8("Долгота восходящего узла:%1 рад")).arg(rvt_c[4]));
      ui->listWidget->item(6)->setText(QString(trUtf8("Аргумент широты:%1 рад")).arg(rvt_c[5]));
      ui->listWidget->item(7)->setText(QString(trUtf8("Текущее время:%1 с")).arg(rvt_c[6]));
   // ui->listWidget->item(8)->setText(QString(trUtf8("Составляющие угловой скорости:%1 %2 %3 рад")).arg(fi[0]*RG).arg(fi[1]*RG).arg(fi[2]*RG));


/*
      scene->addLine(0,90,100,90,pen);//x
      scene->addLine(90,0,90,180,pen);//y

      ui->graphicsView->setScene(scene);
*/
      ui->listWidget_2->item(0)->setText(QString(trUtf8("Цель:")));
      ui->listWidget_2->item(1)->setText(QString(trUtf8("Текущий радиус-вектор:%1 км")).arg(rvt_p[0]));
      ui->listWidget_2->item(2)->setText(QString(trUtf8("Скорость:%1 км/с")).arg(rvt_p[1]));
      ui->listWidget_2->item(3)->setText(QString(trUtf8("Угол наклона вектора скорости к местному горизонту:%1 рад")).arg(rvt_p[2]));
      ui->listWidget_2->item(4)->setText(QString(trUtf8("Наклонение плоскости орбиты:%1 рад")).arg(rvt_p[3]));
      ui->listWidget_2->item(5)->setText(QString(trUtf8("Долгота восходящего узла:%1 рад")).arg(rvt_p[4]));
      ui->listWidget_2->item(6)->setText(QString(trUtf8("Аргумент широты:%1 рад")).arg(rvt_p[5]));
      ui->listWidget_2->item(7)->setText(QString(trUtf8("Текущее время:%1 с")).arg(rvt_p[6]));

      /*
      ui->listWidget_3->item(0)->setText(QString(trUtf8("Координаты области поля зрения:")));
      ui->listWidget_3->item(1)->setText(QString(trUtf8("%1 %2 %3")).arg(result[0][0]).arg(result[0][1]).arg(result[0][2]));
      ui->listWidget_3->item(2)->setText(QString(trUtf8("%1 %2 %3")).arg(result[1][0]).arg(result[1][1]).arg(result[1][2]));
      ui->listWidget_3->item(3)->setText(QString(trUtf8("%1 %2 %3")).arg(result[2][0]).arg(result[2][1]).arg(result[2][2]));
      ui->listWidget_3->item(4)->setText(QString(trUtf8("%1 %2 %3")).arg(result[3][0]).arg(result[3][1]).arg(result[3][2]));
      */

      //ui->listWidget_4->item(0)->setText(QString(trUtf8("Величина составляющих текущего промаха в ОСК перехватчика:")));
      //ui->listWidget_4->item(1)->setText(QString(trUtf8("%1 %2 %3")).arg(dt).arg(ds).arg(dw));
      ui->listWidget_4->item(0)->setText(QString(trUtf8("Дистанция спутник-цель:")));
      ui->listWidget_4->item(1)->setText(QString(trUtf8("%1 км")).arg(D_abs));





      QApplication::processEvents();



      fprintf(out_cxyz,"[%f] = {{ %f, %f, %f}},\n", rvt_c[6],xyz_c[0],xyz_c[1],xyz_c[2]);
      fprintf(out_pxyz,"[%f] = {{ %f, %f, %f}},\n", rvt_p[6],xyz_p[0],xyz_p[1],xyz_p[2]);


      fprintf(out_x,"%f\n",xyz_c[0]);
      fprintf(out_y,"%f\n",xyz_c[1]);
      fprintf(out_z,"%f\n",xyz_c[2]);


      fprintf(out_cpt,"%f\n", rvt_p[6]);
      fprintf(out_cpx,"%f\n", acos(stw[0]/D_osk)*57.295779513082);
      fprintf(out_cpy,"%f\n", acos(stw[1]/D_osk)*57.295779513082);
      fprintf(out_cpz,"%f\n", acos(stw[2]/D_osk)*57.295779513082);




      fprintf(out_c,"%9.3lf, км||%9.3lf, км/с||%9.3lf, рад||%9.3lf, рад||%9.3lf, рад||%9.3lf, рад||%9.3lf, с\n", rvt_c[0], rvt_c[1], rvt_c[2], rvt_c[3], rvt_c[4], rvt_c[5], rvt_c[6]);
      fprintf(out_p,"%9.3lf, км||%9.3lf, км/с||%9.3lf, рад||%9.3lf, рад||%9.3lf, рад||%9.3lf, рад||%9.3lf, с\n", rvt_p[0], rvt_p[1], rvt_p[2], rvt_p[3], rvt_p[4], rvt_p[5], rvt_p[6]);
      fprintf(D,"%9.31lf\n", D_abs);
      fprintf(Plot,"          %9.3lf %9.3lf %9.3lf\n", result[0][0], result[0][1], result[0][2]);
      fprintf(Plot,"%9.3lf %9.3lf %9.3lf %9.3lf\n", rvt_p[6], result[1][0], result[1][1], result[1][2]);
      fprintf(Plot,"          %9.3lf %9.3lf %9.3lf\n", result[2][0], result[2][1], result[2][2]);
      fprintf(Plot,"          %9.3lf %9.3lf %9.3lf\n", result[3][0], result[3][1], result[3][2]);
      fprintf(eps,"%9.3lf||%9.3lf||%9.3lf||%9.3lf\n",rvt_p[6],dt,ds,dw);
      fprintf(tel,"%f %f %f %f %f\n",M_tel[0],M_tel[1],M_tel[2],d_xyz[0],d_xyz[1],d_xyz[2]);
        }

        fclose(out_cxyz);
        fclose(out_pxyz);

        fclose(out_cpt);
        fclose(out_cpx);
        fclose(out_cpy);
        fclose(out_cpz);

        fclose(out_c);
        fclose(out_p);
        fclose(Plot);
        fclose(eps);
        fclose(tel);
 }

void skkp::on_pushButton_2_clicked()
{
    arg_and=Tk;
    for(int k=0;k<7;k++)
    {
        rvt_c[k]=0;
        rvt_p[k]=0;
    }

    for(int j=0;j<4;j++)
        for(int i=0;i<3;i++)
        {
        result[j][i]=0;
        }

    for(int j=0;j<6;j++)
        for(int i=0;i<3;i++)
        {
        Mdk[j][i]=0;
        Fdk[j][i]=0;
        }

    dt=0;
    ds=0;
    dw=0;
    dx=0;
    dy=0;
    dz=0;
    D_abs=0;
    Ix=3500;
    Iy=2100;
    Iz=1900;

    ui->listWidget->item(0)->setText(QString(trUtf8("Спутник:")));
    ui->listWidget->item(1)->setText(QString(trUtf8("Текущий радиус-вектор:%1 км")).arg(rvt_c[0]));
    ui->listWidget->item(2)->setText(QString(trUtf8("Скорость:%1 км/с")).arg(rvt_c[1]));
    ui->listWidget->item(3)->setText(QString(trUtf8("Угол наклона вектора скорости к местному горизонту:%1 рад")).arg(rvt_c[2]));
    ui->listWidget->item(4)->setText(QString(trUtf8("Наклонение плоскости орбиты:%1 рад")).arg(rvt_c[3]));
    ui->listWidget->item(5)->setText(QString(trUtf8("Долгота восходящего узла:%1 рад")).arg(rvt_c[4]));
    ui->listWidget->item(6)->setText(QString(trUtf8("Аргумент широты:%1 рад")).arg(rvt_c[5]));
    ui->listWidget->item(7)->setText(QString(trUtf8("Текущее время:%1 с")).arg(rvt_c[6]));


    ui->listWidget_2->item(0)->setText(QString(trUtf8("Цель:")));
    ui->listWidget_2->item(1)->setText(QString(trUtf8("Текущий радиус-вектор:%1 км")).arg(rvt_p[0]));
    ui->listWidget_2->item(2)->setText(QString(trUtf8("Скорость:%1 км/с")).arg(rvt_p[1]));
    ui->listWidget_2->item(3)->setText(QString(trUtf8("Угол наклона вектора скорости к местному горизонту:%1 рад")).arg(rvt_p[2]));
    ui->listWidget_2->item(4)->setText(QString(trUtf8("Наклонение плоскости орбиты:%1 рад")).arg(rvt_p[3]));
    ui->listWidget_2->item(5)->setText(QString(trUtf8("Долгота восходящего узла:%1 рад")).arg(rvt_p[4]));
    ui->listWidget_2->item(6)->setText(QString(trUtf8("Аргумент широты:%1 рад")).arg(rvt_p[5]));
    ui->listWidget_2->item(7)->setText(QString(trUtf8("Текущее время:%1 с")).arg(rvt_p[6]));

    /*
    ui->listWidget_3->item(0)->setText(QString(trUtf8("Координаты области поля зрения:")));
    ui->listWidget_3->item(1)->setText(QString(trUtf8("%1 %2 %3")).arg(result[0][0]).arg(result[0][1]).arg(result[0][2]));
    ui->listWidget_3->item(2)->setText(QString(trUtf8("%1 %2 %3")).arg(result[1][0]).arg(result[1][1]).arg(result[1][2]));
    ui->listWidget_3->item(3)->setText(QString(trUtf8("%1 %2 %3")).arg(result[2][0]).arg(result[2][1]).arg(result[2][2]));
    ui->listWidget_3->item(4)->setText(QString(trUtf8("%1 %2 %3")).arg(result[3][0]).arg(result[3][1]).arg(result[3][2]));
    */

    //ui->listWidget_4->item(0)->setText(QString(trUtf8("Величина составляющих текущего промаха в ОСК перехватчика:")));
    //ui->listWidget_4->item(1)->setText(QString(trUtf8("%1 %2 %3")).arg(dt).arg(ds).arg(dw));
    ui->listWidget_4->item(0)->setText(QString(trUtf8("Дистанция спутник-цель:")));
    ui->listWidget_4->item(1)->setText(QString(trUtf8("%1 км")).arg(D_abs));





}


/**************************************************************************************/
/**************************************************************************************/
/***************************************************************************************/

void Proportion(double prir_Vhar, double *stw_har)
{
 double V_prop;

   if(stw_har[3]!=0.0 && stw_har[5]!=0.0)
     {
      V_prop = fabs(stw_har[3])/fabs(stw_har[5]);
      stw_har[3]=V_prop*prir_Vhar/(1+V_prop) * stw_har[3]/fabs(stw_har[3]);
      stw_har[5]=       prir_Vhar/(1+V_prop) * stw_har[5]/fabs(stw_har[5]);
     }

   if(fabs(stw_har[3])==0.0)
       stw_har[5]=prir_Vhar * stw_har[5]/fabs(stw_har[5]);
   if(fabs(stw_har[5])==0.0)
       stw_har[3]=prir_Vhar * stw_har[3]/fabs(stw_har[3]);

}

void   xyz_stw(double *xyz, double *alfa, double *stw)
{
 stw[0] = xyz[0]*alfa[0] + xyz[1]*alfa[1] + xyz[2]*alfa[2]; // S
 stw[1] = xyz[0]*alfa[3] + xyz[1]*alfa[4] + xyz[2]*alfa[5]; // T
 stw[2] = xyz[0]*alfa[6] + xyz[1]*alfa[7] + xyz[2]*alfa[8]; // W

 stw[3] = xyz[3]*alfa[0] + xyz[4]*alfa[1] + xyz[5]*alfa[2]; // Vs
 stw[4] = xyz[3]*alfa[3] + xyz[4]*alfa[4] + xyz[5]*alfa[5]; // Vt
 stw[5] = xyz[3]*alfa[6] + xyz[4]*alfa[7] + xyz[5]*alfa[8]; // Vw
}


void   stw_xyz(double *stw, double *alfa, double *xyz)
{
 xyz[0] = stw[0]*alfa[0] + stw[1]*alfa[3] + stw[2]*alfa[6]; // X
 xyz[1] = stw[0]*alfa[1] + stw[1]*alfa[4] + stw[2]*alfa[7]; // Y
 xyz[2] = stw[0]*alfa[2] + stw[1]*alfa[5] + stw[2]*alfa[8]; // Z

 xyz[3] = stw[3]*alfa[0] + stw[4]*alfa[3] + stw[5]*alfa[6]; // Vx
 xyz[4] = stw[3]*alfa[1] + stw[4]*alfa[4] + stw[5]*alfa[7]; // Vy
 xyz[5] = stw[3]*alfa[2] + stw[4]*alfa[5] + stw[5]*alfa[8]; // Vz
}


void   Add_Error(double t_meeting, double *stw_err, double *rvt)
{
 double xyz[6], xyz_err[6];
 double alfa[9];
 double t_kau;
 int i;

 t_kau = rvt[6];


 pr(rvt, 1, 0, 1.0, t_meeting, rvt);
 alfa_beta_gamma(rvt[3], rvt[4], rvt[5], alfa);
 stw_xyz(stw_err, alfa, xyz_err);


 rvt_xyz(rvt, xyz);
 for(i=0; i<6; i++) xyz[i] = xyz[i] + xyz_err[i];
 xyz_rvt(xyz, rvt);

 pr(rvt, 1, 0, 1.0, t_kau, rvt);
}
//-------------------------------------------------------------------
void ImagePlot(double xyz_p[], double xyz_c[], double result[][3], int prinadlejnost)
{

double k, k1,k2;
double r;

//int prinadlejnost;
    r=42271;
    k=xyz_p[1]/xyz_p[0];
    k1 = tan(atan(k) - 1.5*3.14 / 180);
    k2 = tan( atan(k) + 1.5*3.14 / 180);
    result[0][0]=2* (-xyz_p[0])+ sqrt((2 * k2 * (-xyz_p[1]) + 2 * (-xyz_p[0]))*
    (2 * k2 *(-xyz_p[1]) + 2 * (-xyz_p[0]))- 4* (k2 * k2 + 1) * ((-xyz_p[1])*
    (-xyz_p[1])+(-xyz_p[0])*(-xyz_p[0])-r*r))  + 2*k2 * (-xyz_p[1])/
    (2*(k2 * k2 + 1));
    result[0][1]=k2 * (2*(-xyz_p[0]) + sqrt((2*k2*(-xyz_p[1])+2*
    (-xyz_p[0]))*	(2*k2*(-xyz_p[1])+2*(-xyz_p[0]))-4*(k2*k2+1) * ((-xyz_p[1])*
    (-xyz_p[1])+(-xyz_p[0])*(-xyz_p[0])-r*r) ) 	+ 2*k2 * (-xyz_p[1]))/
    (2*(k2 * k2 + 1));

    result[0][2]=sqrt((result[0][0]-xyz_p[0])*(result[0][0]-xyz_p[0])+(result[0][1]-xyz_p[1])*(result[0][1]-xyz_p[1]))*tan(3*3.14/180);
    result[1][0]=result[0][0];
    result[1][1]=result[0][1];
    result[1][2]=-result[0][2];
    result[2][0]=2* (-xyz_p[0])+ sqrt((2 * k1 * (-xyz_p[1]) + 2 * (-xyz_p[0]))*
    (2 * k1 *(-xyz_p[1]) + 2 * (-xyz_p[0]))- 4* (k1 * k1 + 1) * ((-xyz_p[1])*
    (-xyz_p[1])+(-xyz_p[0])*(-xyz_p[0])-r*r) ) + 2*k1 * (-xyz_p[1])/
    (2*(k1 * k1 + 1));
    result[2][1]=k1 * (2*(-xyz_p[0]) + sqrt((2*k1*(-xyz_p[1])+2*
    (-xyz_p[0]))*	(2*k2*(-xyz_p[1])+2*(-xyz_p[0]))-4*(k1*k1+1) * ((-xyz_p[1])*
    (-xyz_p[1])+(-xyz_p[0])*(-xyz_p[0])-r*r) ) 	+ 2*k1 * (-xyz_p[1]))/
    (2*(k1 * k1 + 1));
    result[3][0]=result[2][0];
    result[3][1]=result[2][1];
    result[2][2]=result[0][2];
    result[3][2]=-result[0][2];


    if((result[2][0]>=xyz_c[0]) && (result[2][1]>=xyz_c[1]) && (result[2][2]>=xyz_c[2])
    &&(result[3][0]>=xyz_c[0]) && (result[3][1]>=xyz_c[1]) && (result[3][2]>=xyz_c[2])
    &&(result[0][0]<=xyz_c[0]) && (result[0][1]<=xyz_c[1]) && (result[0][2]<=xyz_c[2])
    &&(result[1][0]<=xyz_c[0]) && (result[1][1]<=xyz_c[1]) && (result[1][2]<=xyz_c[2])){
    prinadlejnost=1;
    }
    else{
        prinadlejnost=0;
    }
}

/***********************************************************************/
/***********************************************************************/
/************************************************************************/

void pr(double *bx1,int id,int ip,double h,double tu,double *bx2)
{
    //bx1 – входной массив орбитальных параметров (r, v. Tet, I, Omega, u, tн) начальные,
    //id – признак точности прогноза (либо по Кеплеру, либо с учетом гармоник С00, С20),
    //ip – признак направления прогноза по времени вперед (Т кон> Т нач) или назад (Т кон< Т нач),
    //h – шаг по времени,
    //tu – момент времени, на который осуществляется прогноз,
   // bx2 – выходной массив орбит. Парам. (r, v. Tet, I, Omega, u, tк) конечные
    //(tк = tн+-h*n=tu)

static int   j,i;
static double y[6],k,th,u,t;
    for(j=1; j<=6; j++) f1[j-1] = 0.0;
    j = 0;
    k = fabs(h);
/*    if(fabs(*(bx1+1)) < 1.0) {
    j = 1;
    for(i=0; i<6; i++) *(y+i) = *(bx1+i);
    }
    else*/
    pu(bx1,y);
    th = *(bx1+6);
    u = t = tu;
    if(ip == 0 && t < th) k = -fabs(k);
    if(ip == 1 && u < *(bx1+5)) k = -fabs(k);
    pr1(y,&th,&t,&k,&ip,&u,&id);
    for(i=0; i<6; i++) *(y+i) += f1[i];
    *(y+5) -= (floor(*(y+5)/(2.0*M_PI))*2.0*M_PI);
    if(j == 0) pv(y,bx2,1);
    else  {
    for(i=0; i<6; i++) *(bx2+i) = *(y+i);
    *(bx2+7) = 0.0;
    }
    *(bx2+6) = t;
}


void pr1(double *y,double *th,double *t,double *h,int *ip,double *u,int *id)
{
static int   nku,j,k1,i;
static double y1[6],yn[6],yf[6],f[6],d[5],
         cy,pi2,h0,t0,tn,c1,
         a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,
         a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,
         a21,a22,a23,a24,a25,a26,a27,a28,a29,
         c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
/*-----------------------------------------------------------------*/
    c1  = 398600.0;
    c2  = 0.000072921158;/* WЗ-угловая скорость вращения Земли (рад/сек)  */
    c3  =-1.0826277E-3  ;/* C20-коэффициент при зональной гармонике 2     */
    c4  = 2.5344372E-6  ;/* C30-коэффициент при зональной гармонике 3     */
    c5  = 1.6248302E-6  ;/* C40-коэффициент при зональной гармонике 4     */
    c6  = 2.1983755E-6  ;/* C31-коэффициент при тессеральной гармонике 31 */
    c7  = 0.2651704E-6  ;/* D31-коэффициент при тессеральной гармонике 31 */
    c8  = 1.5730252E-6  ;/* C22-коэффициент при секториальной гармонике 2 */
    c9  =-0.900643E-6   ;/* D22-коэффициент при секториальной гармонике 2 */
    c10 = 0.            ;/* Л0-долгота гринвич. меридиана от-но т.в.р.    */
    c11 = 6378.137      ;/* RЗ-экваториальный радиус Земли                */
    c12 = 130.          ;/* F-коэф.,учитыв.пл.потока радиоизлучения Солнца*/
    c13 = 150.            ;/* KБ-баллистический коэффициент                 */

    cy = 86400.0;
    pi2 = M_PI*2.0;
    nku = 1;
    h0 = *h;
    t0 = *th;
S6:
    for(j=0; j<6; j++)
      {
       *(yn+j) = *(y1+j) = *(y+j)+f1[j];
       *(yf+j) = 0.0;
      }
    if(*ip == 0 && fabs(*th-*t) <= fabs(*h))
      {
       *h = *t-*th;
       nku = 0;
      }
    else if(*ip != 0.0 && fabs(*u-*(y1+5)) < 1.0E-5) {
    nku = 0;
    goto S13;
    }
    *d = *(d+1) = *(d+4) = *h/2.0;
    *(d+2) = *(d+3) = *h;
    tn = *th;
    for(j=1; j<=4; j++)
      {
    a1 = sin(*(yn+3));
    a2 = cos(*(yn+3));
    a3 = sin(*(yn+5));
    a4 = cos(*(yn+5));
    a5 = sqrt(*yn/c1);
    a11 = (*(yn+2)*a3-*(yn+1)*a4)/a5;
    a29 = 1.0+*(yn+1)*a3+*(yn+2)*a4;
    a12 = a29/a5;
    a6 = *yn/a29;
    a7 = a1*a3;
    a8 = sqrt(1.0-a7*a7);
    a16 = a1*a4;
    a17 = a7*a7;
    a26 = c11/a6;
    a27 = a26*a26;
    a21 = c1/(a6*a6)*a27;
    a13 = 1.5*c3*(3.0*a17-1.0);
    a14 = 3.0*c3*a7;
    a15 = a14*a2;
    a14 *= a16;
    a18 = a8*a8;
    if(*id == 1)
      {
        a9 = a3*a2/a8;
        a10 = a4/a8;
        if(fabs(a9) > 1) a9 = sign(a9);
        a10 = aasin(a9,a10);
        a9 = *(yn+4)-c2*tn+a10+c10;
        a10 = cos(a9);
        a9 = sin(a9);
        a19 = 2.0*a9*a10;
        a20 = 2.0*a10*a10-1.0;
        a24 = c6*a10+c7*a9;
        a25 = c8*a20+c9*a19;
        a28 = 5.0*a17-1.0;
        a13 += (2.0*a26*c4*(a28-2.0)*a7+0.625*a27*c5*(35.0*
          a17*a17-30.0*a17+3.0)+9.0*a25*a18+6.0*a26*a24*a28*a8);
        a22 = 1.5*a26*c4*a28+2.5*a27*c5*(7.0*a17-3.0)*a7-6.0*
          a25*a7+1.5*a26*a24*(11.0-15.0*a17)*a7/a8;
        a23 = 6.0*(c8*a19-c9*a20)+1.5*a26*(c6*a9-c7*a10)*a28/a8;
        a14 += (a22*a16-a23*a2);
        a15 += (a22*a2+a23*a16);
      }
    a13 = -(a21*a13);
    a14 = a21*a14;
    a15 = a21*a15;
    if(c13 > 1.0E-13)
      {
        a26 = a12-c2*a6*a2;
        a27 = c2*a6*a1*a4;
        a28 = sqrt(a11*a11+a26*a26+a27*a27);
        a21 = c11/sqrt(a18+a17/pow(1.0-3.352329E-3,2.0));
        a22 = a6-a21;
        a23 = -(106.0/c12)+6.327E-3*c12-5.5247;
        a24 = fabs(1.0E-2*a22-1.2);
        a25 = sqrt(a24)-0.63246;
        a24 = 1.09*exp(a23*a25);
        a25 = -(c13*a24*a28);
        a13 += (a25*a11);
        a14 += (a25*a26);
        a15 += (a25*a27);
      }
    a13 *= a5;
    a14 *= a5;
    a15 *= a5;
    a24 = 1.0/a29;
    *f = 2.0**yn*a14*a24;
    a25 = a2/a1;
    a26 = a3*a25*a15*a24;
    *(f+1) = -(*(yn+2)*a26)+((*(yn+1)+a3)*a24+a3)*a14-a13*a4;
    *(f+2) = *(yn+1)*a26+((*(yn+2)+a4)*a24+a4)*a14+a13*a3;
    *(f+3) = a4*a15*a24;
    *(f+4) = a3*a15/(a29*a1);
    *(f+5) = a29*a29/(*yn*a5)-a26;
    tn = *th+*(d+j-1);
    for(k1=0; k1<6; k1++)
      {
       *(yn+k1) = *(y1+k1)+*(d+j-1)**(f+k1);
       *(yf+k1) += (*(d+j)**(f+k1)/3.0);
      }
      }
    for(i=0; i<6; i++)
      {
       f1[i] += *(yf+i);
       *(yf+i) = 0.0;
      }
    if(fabs(f1[5]) >= 1.0)
      {
       *(y+5) += floor(f1[5]);
       f1[5]  -= floor(f1[5]);
      }
    *th += *h;
    if(*ip == 1)
     {
    *t = *th-*h;
    if((*(y1+5)< *(y+5)+f1[5] && *(y1+5)<*u && *u<*(y+5)+f1[5]) ||
       (*(y1+5)>=*(y+5)+f1[5] && *(y1+5)>*u && *u>*(y+5)+f1[5])) goto S11;
    if(nku != 2) goto S12;
S11:
    nku = 2;
    *h *= (*(y+5)+f1[5]-*u)/(*(y1+5)-*(y+5)-f1[5]);
    if(*h == 0.0) nku = 0;
     }
    if(fabs(*h) > fabs(h0)) *h = h0;
S12:
    if(nku != 0) goto S6;
S13:
    *h = h0;
    *(y+5) -= (floor(*(y+5)/pi2)*pi2);
}
/*-----------------------------------------------------------------*/
/*    Пересчет координат 1 (R V Q I OM U T)->(P Л1 Л2 I OM U T)    */
/*-----------------------------------------------------------------*/
void pu(double *r,double *p)
{
static double s,c,su,cu,r1,r2,c1=398600.0;

    s = sin(*(r+2));
    c = cos(*(r+2));
    su = sin(*(r+5));
    cu = cos(*(r+5));
    r1 = *r**(r+1)**(r+1)*c/c1;
    r2 = r1*s;
    r1 *= c;
    *p = *r*r1;
    r1 -= 1.0;
    *(p+1) = r1*su-r2*cu;
    *(p+2) = r2*su+r1*cu;
    *(p+3) = *(r+3);
    *(p+4) = *(r+4);
    *(p+5) = *(r+5);
}
/*-----------------------------------------------------------------*/
/*    Пересчет координат 2 (P Л1 Л2 I OM U T)->(R V Q I OM U T)    */
/*-----------------------------------------------------------------*/
void pv(double *p,double *r,int i)
{
static int j;
static double e1,s,c,u,c1=398600.0;
    e1 = *(p+1)**(p+1)+*(p+2)**(p+2);
    s = sin(*(p+5));
    c = cos(*(p+5));
    u = 1.0+*(p+2)*c+*(p+1)*s;
    *r = *p/u;
    *(r+1) = sqrt(c1/ *p*(1+e1+2*(*(p+2)*c+*(p+1)*s)));
    *(r+2) = atan((s**(p+2)-c**(p+1))/u);
    if(i == 1)
     {
      for(j=3; j<6; j++) *(r+j) = *(p+j);
     }
    else
     {
      *(r+3) = *(r+1)*cos(*(r+2));
      *(r+4) = *(r+1)*sin(*(r+2));
     }
}
/*-----------------------------------------------------------------*/
/*                  ПРОЦЕДУРА-ФУНКЦИЯ КРУГОВОГО ARCSIN             */
/*-----------------------------------------------------------------*/
double aasin(double x,double b)
{
    double aasin=0.0;
    if(b < 0.0) aasin = -asin(x)+M_PI;
    else if(x < 0.0) aasin = asin(x)+M_PI*2.0;
    else  aasin = asin(x);
    return aasin;
}

/***************************************************************/
/***************************************************************/
/***************************************************************/

void alfa_beta_gamma(double i,double Om,double u,double *alfa)
{
   double c_u,s_u,c_i,s_i,c_Om,s_Om;
   c_u =cos(u);  s_u =sin(u);
   c_i =cos(i);  s_i =sin(i);
   c_Om =cos(Om);  s_Om =sin(Om);
   cout << "u=" << u << endl;
   cout << "cu=" << c_u << endl << "su=" << s_u << endl << "ci=" << c_i << endl << "s_i=" << s_i << endl << "cOm=" << c_Om << endl << "sOm=" << s_Om << endl;
   alfa[0] =  c_u*c_Om-s_u*s_Om*c_i;
   alfa[1] =  c_u*s_Om+s_u*c_Om*c_i;
   alfa[2] =  s_u*s_i;
   alfa[3] = -s_u*c_Om-c_u*s_Om*c_i;
   alfa[4] = -s_u*s_Om+c_u*c_Om*c_i;
   alfa[5] =  c_u*s_i;
   alfa[6] =  s_Om*s_i;
   alfa[7] = -c_Om*s_i;
   alfa[8] =  c_i;
    cout << "alfa[0]=" << alfa[0] << endl << "alfa[1]" << alfa[1] << endl << "alfa[2]" << alfa[2] << endl << "alfa[3]" << alfa[3] << endl << "alfa[4]" << alfa[4] << endl << "alfa[5]" << alfa[5] << "alfa[6]" << alfa[6]<< "alfa[7]" << alfa[7]<< "alfa[8]" << alfa[8]<< endl;
}

double cratan(double s,double c)
{
   if(c==0) return (s>=0)? M_PI/2:3/2*M_PI;
   else if(c<0) return atan(s/c)+M_PI;
    else if(s<0) return atan(s/c)+2*M_PI;
         else return atan(s/c);
}

void rvt_xyz(double *rvt, double *xyz)
{
 double alfa[9], Vr, Vt;

  alfa_beta_gamma(rvt[3],rvt[4],rvt[5],alfa); /* ¬ âà¨æ  ¯¥à¥áç¥â   */
    cout << "в rvt alfa[0]=" << alfa[0] <<endl;
  Vr       = *(rvt+1)*sin(*(rvt+2));
  Vt       = *(rvt+1)*cos(*(rvt+2));
  *xyz     = *rvt**alfa;
  *(xyz+1) = *rvt**(alfa+1);
  *(xyz+2) = *rvt**(alfa+2);
  *(xyz+3) = Vr**alfa+Vt**(alfa+3);
  *(xyz+4) = Vr**(alfa+1)+Vt**(alfa+4);
  *(xyz+5) = Vr**(alfa+2)+Vt**(alfa+5);
}

void   filambdah(double *rvt, double *fl)
{
 double f = 1/298.25;
 double xyz[7],xyz_g[7];

 rvt_xyz(rvt, xyz);
 xyz[6]=rvt[6];
 xyz_xyzG(xyz,xyz_g);

 fl[0] = atan(xyz_g[2]/sqrt(xyz_g[0]*xyz_g[0] + xyz_g[1]*xyz_g[1]));
 fl[1] = cratan(xyz_g[1],xyz_g[0]);
 fl[2] = sqrt(xyz_g[0]*xyz_g[0] + xyz_g[1]*xyz_g[1] + xyz_g[2]*xyz_g[2]) -
     R_LAND*(1-f*sin(fl[0])*sin(fl[0]));
}

double arg(double x)
{
double z;
int    i;
     i = (int)(x/M_PI/2.0);
     z = x - i*M_PI*2.0;
     if(z < 0.0) z += M_PI*2.0;
     return z;
}

void xyz_xyzG(double *xyz, double *xyz_g)
{
double dx;

    dx = arg(O_LAND*xyz[6]);
    xyz_g[0] =  xyz[0]*cos(dx) + xyz[1]*sin(dx);
    xyz_g[1] = -xyz[0]*sin(dx) + xyz[1]*cos(dx);
    xyz_g[2] =  xyz[2];
    xyz_g[3] =  xyz[3]*cos(dx) + xyz[4]*sin(dx) + xyz_g[1]*O_LAND;
    xyz_g[4] = -xyz[3]*sin(dx) + xyz[4]*cos(dx) - xyz_g[0]*O_LAND;
    xyz_g[5] =  xyz[5];
}

void rvt_hahp(double *r,double *ha, double *hp)
{
static double a, c, e, p, k, Vt;

    c  = cos(r[2]);
    p  = r[0]*r[0]*r[1]*r[1]*c*c/Mu;
    k  = r[0]*r[1]*r[1]/Mu;
    a  = r[0]/(2.-k);
    Vt = r[1]*cos(r[2]);
    e  = sqrt(1-r[0]/a*r[0]/Mu*Vt*Vt);
   *ha = p/(1. - e) - R_Zem;
   *hp = p/(1. + e) - R_Zem;
}

int xyz_rvt (double *xyz,double *rvt )
{
   double s;
   if (xyz_iOmu(xyz,rvt+3,rvt+4,rvt+5)) return 1;
   *rvt     = *xyz**xyz+*(xyz+1)**(xyz+1)+*(xyz+2)**(xyz+2);
   *(rvt+1) = *(xyz+3)**(xyz+3)+*(xyz+4)**(xyz+4)+*(xyz+5)**(xyz+5);
   s        = *xyz**(xyz+3)+*(xyz+1)**(xyz+4)+*(xyz+2)**(xyz+5);
   *(rvt+2) = atan (s/sqrt(*rvt**(rvt+1)-s*s));
   *rvt     = sqrt(*rvt);
   *(rvt+1) = sqrt(rvt[1]);
   return 0;
}

int xyz_iOmu(double*xyz,double*i,double*Om,double*u)
{
   double  c1,c2,c3,c;

   c1     = *(xyz+1)**(xyz+5)-*(xyz+2)**(xyz+4);
   c2     = *(xyz+2)**(xyz+3)-*xyz**(xyz+5);
   c3     = *xyz**(xyz+4)-*(xyz+1)**(xyz+3);
   c      = sqrt (c1*c1 + c2*c2 + c3*c3);
   *Om    = cratan(c1,-c2);
   *i     = acos(c3/c);
   *u     = cratan(*(xyz+2)/sin(*i),*xyz*cos(*Om)+*(xyz+1)*sin(*Om));
   return 0;
}

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/




void mod_du(void)
{

    Rk_dk[i_dk] = 5.75*(Pvxkn)-0.62;
    R_DK = Rk_dk[i_dk-1];
    R_DKc = R_DK*G0/1000.;

            Fdk[0][1] = R_DKc*cos70;
            Fdk[1][1] = R_DKc;
            Fdk[2][1] = R_DKc*cos70;
            Fdk[3][1] = R_DKc*cos70;
            Fdk[4][1] = R_DKc;
            Fdk[5][1] = R_DKc*cos70;


       if(i_dk==1)
       {
           Mdk[0][0] = Fdk[0][1]*L_dk[2] -  Fdk[0][2]*L_dk[0] ;		//OX
           Mdk[0][1] = Fdk[0][2]*L_dk[0]  - Fdk[0][0]*L_dk[2] ;				//OY
           Mdk[0][2] = Fdk[0][0]*L_dk[1]  - Fdk[0][1]*L_dk[0] ;				//OZ
       }
       if(i_dk==2)
       {
           Mdk[1][0] = Fdk[1][1] * L_dk[2] -  Fdk[1][2] * L_dk[0] ;		//OX
           Mdk[1][1] = Fdk[1][2] * L_dk[0]  - Fdk[1][0]*L_dk[2] ;				//OY
           Mdk[1][2] = Fdk[1][0]*L_dk[1]  -   Fdk[1][1] * L_dk[0] ;				//OZ
       }
       if(i_dk==3)
       {
           Mdk[2][0] = Fdk[2][1] * L_dk[2] - Fdk[2][2] * L_dk[0] ;		//OX
           Mdk[2][1] = Fdk[2][2] * L_dk[0]  - Fdk[2][0]*L_dk[2] ;				//OY
           Mdk[2][2] = Fdk[2][0]*L_dk[1]  -  Fdk[2][1] * L_dk[0] ;
       }
       if(i_dk==4)
       {
           Mdk[3][0] = Fdk[3][1] * L_dk[2] - Fdk[3][2] * L_dk[0] ;		//OX
           Mdk[3][1] = Fdk[3][2] * L_dk[0]  - Fdk[3][0]*L_dk[2] ;				//OY
           Mdk[3][2] = Fdk[3][0]*L_dk[1]  - Fdk[3][1] * L_dk[0] ;				//OZ
       }
       if(i_dk==5)
       {
           Mdk[4][0] = Fdk[4][1] * L_dk[2] - Fdk[4][2] * L_dk[0] ;		//OX
           Mdk[4][1] = Fdk[4][2] * L_dk[0]  - Fdk[4][0]*L_dk[2] ;				//OY
           Mdk[4][2] = Fdk[4][0]*L_dk[1]  - Fdk[4][1] * L_dk[0] ;				//OZ
       }
       if(i_dk==6)
       {
           Mdk[5][0] = Fdk[5][1] * L_dk[2] - Fdk[5][2] * L_dk[0] ;		//OX
           Mdk[5][1] = Fdk[5][2] * L_dk[0]  - Fdk[5][0]*L_dk[2] ;				//OY
           Mdk[5][2] = Fdk[5][0]*L_dk[1]  - Fdk[5][1] * L_dk[0] ;				//OZ
       }


}



void RIMX(void)
{
    dMas_dk_sum = dMas_dk_sum + (4.*Rk_dk[i_dk-1]-Rk_dk[i_dk-1]*del_tp1k/2.)/220.;

    Mas  = Mas0-dMas_dk_sum/1000.;
      //расчёт МИХ с учётом выработки топлива

        Ix= Ix +(Mas-Mpoln)/(Msux-Mpoln)*(Jx_sux - Ix);
        Iy= Iy +(Mas-Mpoln)/(Msux-Mpoln)*(Jy_sux - Iy);
        Iz= Iz +(Mas-Mpoln)/(Msux-Mpoln)*(Jz_sux - Iz);

}
