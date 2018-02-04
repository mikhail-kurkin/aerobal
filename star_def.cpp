#include "star_def.h"

/*
star_def::star_def()
{
}
*/
// Расчет космической величины
//
#include <math.h>


using namespace std;

float get_cos_fi(float n_s, float n_t, float n_v);				//Получение косинуса фазового угла
//float get_luks_sq();											//Освещенность участка поверхности объекта
float get_luks_dot(float cos_fi, const float I_u, float r, float delt_r, float costet);		//Освещенность точечного объекта
//float get_square();											//Площадь элементарного разбиения
//float get_K();												//Коэффициент отражения материала; содержит либо массив величин, либо ссылается на внешний файл
float ecleptic_lam(float eps, float L, float G);				//Получение положения объекта в эклиптической СК (lambda)
//float ecleptic_betta();										//Получение положения объекта в эклиптической СК (betta)
float ecleptic_eps(float T);									//Получение положения объекта в эклиптической СК (eps)
float ecleptic_Eps(float T);									//Получение положения объекта в эклиптической СК (Eps)
float rec_X(float r, float bet, float lam, float Eps);			//Переход к прямоугольной СК (X)
float rec_Y(float r, float bet, float lam, float Eps);			//Переход к прямоугольной СК (Y)
float rec_Z(float r, float bet, float lam, float Eps);			//Переход к прямоугольной СК (Z)
float direction(float x, float y, float z);						//Вычисление векторов направлений


float star_def(float n_t, float n_v, float delt_r, float costet)
{
    const float m_0 = 0;																			//Начальная космическая величина
    const float L_0 = 2.54*0.000001;																//Начальная величина освещенности
    //float I_u = 2.8 * (10 ^ (27));
    float I_u = 2800000000000000000000000000;
    //float r = 1.5 * (10 ^ (11));																	//Средний радиус орбиты Земли
    float r = 150000000000;
    const float k_0 = 1;																			//Упрощенное значение коэффициента отражения

    float lambda_s = 0, betta_s = 0, eps_s = 0, Eps_s = 0, X_s = 0, Y_s = 0, Z_s = 0, n_s = 0;		//Переменные Солнца
    float lambda_m = 0, betta_m = 0, eps_m = 0, Eps_m = 0, X_m = 0, Y_m = 0, Z_m = 0, n_m = 0;		//Переменные Луны

    //Константы для вычислений
    const float T_s = 1.15, r_s = 149.6 * 1000000, L_s = 278.833, G_s = 282.596;
    const float T_m = 1.15, r_m = 384000, L_m = 77.09, G_m = 99.51;

    //Вычисление в эклиптических координатах
    eps_s = ecleptic_eps(T_s);
    eps_m = ecleptic_eps(T_m);

    Eps_s = ecleptic_Eps(T_s);
    Eps_m = ecleptic_Eps(T_m);

    lambda_s = ecleptic_lam(eps_s, L_s, G_s);
    lambda_m = ecleptic_lam(eps_m, L_m, G_m);

    //Вычисление в прямоугольных координатах
    X_s = rec_X(r_s, betta_s, lambda_s, Eps_s);
    X_m = rec_X(r_m, betta_m, lambda_m, Eps_m);

    Y_s = rec_Y(r_s, betta_s, lambda_s, Eps_s);
    Y_m = rec_Y(r_m, betta_m, lambda_m, Eps_m);

    Z_s = rec_Z(r_s, betta_s, lambda_s, Eps_s);
    Z_m = rec_Z(r_m, betta_m, lambda_m, Eps_m);

    //Направляющие вектора
    n_s = direction(X_s, Y_s, Z_s);
    n_m = direction(X_m, Y_m, Z_m);

    //Получение косинуса нужного угла
    float cos_fi = get_cos_fi(n_s, n_t, n_v);						//Заход переменных из предыдущей программы (из Мишиной части)//nt-ка, nv-цель

    float L = get_luks_dot(cos_fi, I_u, r,delt_r,costet);

    //Получение звездной величины
     float m = m_0 - 2.5 * log10(L / L_0);
return m;
}

float get_cos_fi(float n_s, float n_t, float n_v)
{
    return ((n_s - n_v) * (n_t - n_v));
}

float get_luks_dot(float cos_fi, const float I_u, float r, float delt_r, float costet)
{
    float E = 0;
    float L =0;
    E = (I_u / (r * r)) * cos_fi;
    L=E/(delt_r*delt_r*costet*1000000);

    return L;
    //return cos_fi;
}

float ecleptic_lam(float eps, float L, float G)											//Получение положения объекта в эклиптической СК (lambda)
{
    return (L + 2 * eps * sin(L - G) + (5 / 4) * eps * eps *sin(2 * (L - G)));
}

//float ecleptic_betta();																//Получение положения объекта в эклиптической СК (betta)
float ecleptic_eps(float T)																//Получение положения объекта в эклиптической СК (eps)
{
    return (0.0167086342 - 4.203654 * 0.00001 * T - 1.2673 * 0.0000001 * T * T - 1.4 * 0.0000000001 * T * T * T);
}

float ecleptic_Eps(float T)																	//Получение положения объекта в эклиптической СК (Eps)
{
    return (23.45229444 - 0.013012500 * T - 0.16388889 * 0.00001 * T * T + 0.50277778 * 0.000001 * T * T* T);
}

float rec_X(float r, float bet, float lam, float Eps)																			//Переход к прямоугольной СК (X)
{
    return (r * cos(bet) * cos(lam));
}

float rec_Y(float r, float bet, float lam, float Eps)																			//Переход к прямоугольной СК (Y)
{
    return (r * cos(bet) * (sin(lam) * cos(Eps) - tan(bet) * sin(Eps)));
}

float rec_Z(float r, float bet, float lam, float Eps)																			//Переход к прямоугольной СК (Z)
{
    return (r * cos(bet) * (sin(lam) * sin(Eps) + tan(bet) * cos(Eps)));
}

float direction(float x, float y, float z)
{
    return (sqrt(x * x + y * y + z * z));
}
