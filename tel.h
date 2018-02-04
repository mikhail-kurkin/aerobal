#ifndef TEL_H
#define TEL_H
#include "stdio.h"
#include "conio.h"
#include "math.h"
#define const_pi 3.14159265358979323846
double M_tel[3];//x,y,z
class privod
{
public:
    struct
    {
        double L;//индуктивность обмотки
        double R;//сопротивление обмотки
        double Jr;//момент инерци ротора
        double Ke;//коэффциент противо-ЭДС
        double Km;//коэффициент момента двигателя
        double n;//номинальная скорость вращения двигателя об/мин
    }engine;//параметры ДПТ
    double e;//требуемая ошибка угл.мин
    double v_max;//максимальная скорость телескопа, рад/с
    double a_max;//максимальное ускорение телескопа, рад/с^2
    double Jt;//момент инерции телескопа
    double Jm;//момент инерции маховика
    double it;//редуктор телескопа
    double im;//редуктор маховика
    double ei;//погрешность редукторов, %
    double eJ;//погрушность моментов инерции, %
    double T;//период дискретизации (частота обращения 1сек)
    double task_angle;//желаемое угловое положение телескопа, рад
    double real_angle;//истинное угловое положение телескопа, рад
    double real_speed;//угловая скорость телескопа, рад/с
    double real_accel;//угловое ускорение телескопа, рад/с^2
    double real_moment;//момент сил действующий на спутник
    double num[5];//числитель разомкнутой передаточной функции(старший элемент при -4 степени Z)
    double den[5];//знаменатель разомкнутой передаточной функции(старший элемент при -4 степени Z)
    double in[5];//in[0]-новое значение ошибки, in[4]-самое старое значение ошибки рад
    double out[5];//out[0]-новое значение выхода, out[4]-самое старое значение выхода, рад
    void correction(void)//расчёт корректирующего устройства, устранением полюсов двигателя и добавлением двух своих полюсов и одного нуля. В раб.точке делается -2 наклон
    {
        double Ar,wr;//параметры рабочей точки, рад
        double kr;//коэф.усиления на раб. частоте, после устранения двух полюсов двигателя
        double u;//последовательный коэф.усиления
        double wkor1;//частота второго излома в -1 наклон
        double wkor2;//частота третьего излома в -3 наклон
        double k,a0,a1,a2;//коэф. передаточной функции двигателя
        double w1,w2;//частоты излома передаточной функции двигателя
        it=(engine.n*2*const_pi/60)/v_max;
        im=it*Jm/Jt;
        //расчёт коэффициент передаточной функции неизменяемой части, после последовательной коррекции
        k=1/(engine.Ke*it);
        a0=((engine.Jr+Jt/(it*it)+Jm/(im*im))*engine.L)/(engine.Ke*engine.Km);
        a1=((engine.Jr+Jt/(it*it)+Jm/(im*im))*engine.R)/(engine.Ke*engine.Km);
        a2=1;
        //определение частот излома
        if ((a1*a1-4*a0*a2)<=0)
        {
            w1=1/sqrt(a0);//дескрименант <=0
            w2=w1;
        }
        else
        {
            w1=-(-a1+sqrt(a1*a1-4*a0*a2))/(2*a0);
            w2=-(-a1-sqrt(a1*a1-4*a0*a2))/(2*a0);
        }
        //определение параметров рабочей точки
        Ar=pow(v_max,2)/a_max;
        wr=a_max/v_max;
        //определение последовательного коэф.усиления
        kr=k/wr;
        u= (Ar/(e/60*const_pi/180))/kr;
        if(20*log10(u*kr)>12)
        {
            //определение частоты 2-го излома в -1 наклон
            wkor1=pow(10,(20*log10(u*kr)-12)/40.0)*wr;
            //определение частоты 3-го излома в -3 наклон
            wkor2=wkor1*pow(10.0,24.0/20.0);
        }
        else
        {
            //определение частоты 1-го излома в -3 наклон
            wkor1=10e-7;
            wkor2=wr*pow(10.0,(20*log10(u*kr)-12)/20.0);
        }
        //определение коэф. разомкнутой перед. функции
        num[0]=k*u*wkor1*wr*pow(T,4)*pow(wkor2,2)+2*k*u*wr*pow(T,3)*pow(wkor2,2);//при 0 степени
        num[1]=4*k*u*wkor1*wr*pow(T,4)*pow(wkor2,2)+4*k*u*wr*pow(T,3)*pow(wkor2,2);
        num[2]=6*k*u*wkor1*wr*pow(T,4)*pow(wkor2,2);
        num[3]=4*k*u*wkor1*wr*pow(T,4)*pow(wkor2,2)-4*k*u*wr*pow(T,3)*pow(wkor2,2);
        num[4]=k*u*wkor1*wr*pow(T,4)*pow(wkor2,2)- 2*k*u*wr*pow(T,3)*pow(wkor2,2);//при -4 степени
        den[0]=2*wkor1*wr*pow(T,3)*pow(wkor2,2)+4*wkor1*pow(T,2)*pow(wkor2,2) + 8*wkor1*wr*pow(T,2)*wkor2 + 16*wkor1*T*wkor2 + 8*wkor1*wr*T + 16*wkor1;
        den[1]=4*wkor1*wr*pow(T,3)*pow(wkor2,2) - 32*wkor1*T*wkor2 - 16*wkor1*wr*T - 64*wkor1;
        den[2]=-8*wkor1*pow(T,2)*pow(wkor2,2)- 16*wkor1*wr*pow(T,2)*wkor2 + 96*wkor1;
        den[3]=-4*wkor1*wr*pow(T,3)*pow(wkor2,2) + 32*wkor1*T*wkor2 + 16*wkor1*wr*T - 64*wkor1;
        den[4]=- 2*wkor1*wr*pow(T,3)*pow(wkor2,2) + 4*wkor1*pow(T,2)*pow(wkor2,2) + 8*wkor1*wr*pow(T,2)*wkor2 - 16*wkor1*T*wkor2 - 8*wkor1*wr*T + 16*wkor1;
    }
    double position(double angle)//определение положения телескопа
    {
        int i;
        task_angle=angle;
        for (i=4;i>0;i--)
        {
            in[i]=in[i-1];
            out[i]=out[i-1];
        }
        in[0]=task_angle-real_angle;
        out[0]=(num[4]*in[4]+num[3]*in[3]+num[2]*in[2]+num[1]*in[1]+num[0]*in[0]-den[4]*out[4]-den[3]*out[3]-den[2]*out[2]-den[1]*out[1])/den[0];
        real_speed=(out[0]-out[1])/T;
        real_accel=(real_speed-(out[1]-out[2])/T)/T;
        real_angle=out[0];
        real_moment=Jt*(1+eJ)*real_accel-Jm*(1-eJ)*real_accel/it*im;
        return(real_angle);
    }
}Gdrive,Vdrive;//горизонтальный и вертикальный привод

void setFirstly () {
    M_tel[0]=0;
    M_tel[1]=0;
    M_tel[2]=0;
}

void set (double x,double y,double z, double T)//наведение телескопа
{
    int i;
    double a_vert;
    double a_gor;
    //расчёт угла цели по вертикали
    if (z>0) a_vert=atan(sqrt(y*y+x*x)/z);
    if (z==0) a_vert=const_pi/2;
    if (z<0) a_vert=const_pi-atan(-sqrt(y*y+x*x)/z);
    //расчёт угла цели по горизонтали
    if ((x==0)&&(y>0)) a_gor=const_pi/2;
    if ((x==0)&&(y<=0)) a_gor=-const_pi/2;
    if ((x>0)&&(y>0)) a_gor=atan(y/x);
    if ((x<0)&&(y>0)) a_gor=const_pi/2+atan(-y/x);
    if ((x<0)&&(y<0)) a_gor=-const_pi+atan(y/x);
    if ((x>0)&&(y<0)) a_gor=-atan(-y/x);

    for (i=0;i<T/Gdrive.T;i++)
    {
        Gdrive.position(a_gor);
        Vdrive.position(a_vert);
    }
    M_tel[0]=Gdrive.real_moment;
    M_tel[1]=Vdrive.real_moment*cos(a_gor);
    M_tel[2]=Vdrive.real_moment*sin(a_gor);
}

void conf (void)//настройка параметров объектов
{
    Gdrive.engine.L=0.00030;
    Gdrive.engine.R=0.150;
    Gdrive.engine.Jr=0.00050;
    Gdrive.engine.Ke=0.07540;
    Gdrive.engine.Km=0.0560;
    Gdrive.engine.n=5080;
    Gdrive.Jt=147;
    Gdrive.Jm=1;
    Gdrive.v_max=0.52;
    Gdrive.a_max=0.52;
    Gdrive.e=6;
    Gdrive.T=0.001;
    //Gdrive.T=1;
    Gdrive.ei=5;
    Gdrive.eJ=5;
    Gdrive.correction();

    Vdrive.engine.L=0.00030;
    Vdrive.engine.R=0.150;
    Vdrive.engine.Jr=0.00050;
    Vdrive.engine.Ke=0.07540;
    Vdrive.engine.Km=0.0560;
    Vdrive.engine.n=5080;
    Vdrive.Jt=147;
    Vdrive.Jm=1;
    Vdrive.v_max=0.52;
    Vdrive.a_max=0.52;
    Vdrive.e=6;
    Vdrive.ei=5;
    Vdrive.eJ=5;
    Vdrive.T=0.001;
    //Vdrive.T=1;
    Vdrive.correction();
}

#endif // TEL_H
