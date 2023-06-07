/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_ee
*/

#include "my.h"
#include "my_printf.h"

void status4(int times, int prec, long double b, long double decimal)
{
    for (int b = 0; b < prec; decimal *= 10,
        decimal = e_round_dec(decimal, prec, b), my_put_nbr((int)decimal % 10),
        decimal = pos_n_double(decimal - (int)decimal), b++);
    if ((int)b != 0)
        my_putstr("e+");
    else
        my_putstr("e-");
    if (times > 9)
        my_put_nbr(times);
    else {
        my_put_nbr(0);
        my_put_nbr(times);
    }
}

int status3(int times, int prec, double *a, long double b)
{
    long double decimal;
    int x = 0;
    if (prec != 0 && (int)b == 0) {
        my_put_nbr(*a);
        my_putchar('.');
        x = 1;
    }
    if (prec != 0 && (int)b != 0) {
        for (int b = 0; b < times; *a /= 10, b++);
        my_put_nbr(*a);
        my_putchar('.');
    } else if (x == 0)
        my_put_nbr(*a);
    decimal = pos_n_double(*a - (int)*a);
    status4(times, prec, b, decimal);
    return (*a);
}

int fl_ee(va_list list, flags_t flags, int *len)
{
    double a = va_arg(list, double), *p_a = &a, hh = a;
    int prec = flags.prec, times = my_nbrlen(a) - 1;

    if ((int)*p_a == 0)
        for (times = 0; (int)*p_a == 0; *p_a *= 10, times++);
    if (flags.p == 0)
        prec = 6;
    if (flags.p == 1 && prec == 0) {
        *p_a = e_round(a);
    }
    status3(times, prec, p_a, hh);
    return (*len);
}
