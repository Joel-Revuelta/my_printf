/*
** EPITECH PROJECT, 2022
** sr_c
** File description:
** fl_e
*/

#include "my.h"
#include "my_printf.h"

long double e_round(double a)
{
    int par = 0;
    int times = my_nbrlen(a) - 1;

    if (a < 0) {
        my_putchar('-');
        a = pos_n(a);
    }
    for (int b = 0; b < times; a /= 10, b++);
    if ((int)a % 10 == 0)
        par = 1;
    if (par == 0 || (int)a == a) {
        if ((long long int)(a * 100) % 10 > 4)
            a += 1;
    }
    return (a);
}

long double e_round_dec(double a, int prec, long double b)
{
    int par = 0;
    int much = 0;
    int size = my_nbrlen(b);
    long double times = 1;
    long long int pow = (my_compute_power_rec(10, pos_n((size - prec)))) * 10;

    if ((int)b % 10 == 0)
        par = 1;
    if (par == 1) {
        for (much = 0; much < prec - 1; times /= 10, much++);
        if (size != prec && much == prec - 1 &&
        ((long long int)(a * pow) % 10) > 4)
            a += times;
    }
    return (a);
}

int status2(int times, int prec, long double b, long double decimal)
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

int status(int times, int prec, long double *a, long double b)
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
    status2(times, prec, b, decimal);
    return (*a);
}

int fl_e(va_list list, flags_t flags, int *len)
{
    long double a = va_arg(list, double), *p_a = &a, hh = a;
    long double decimal;
    int b, prec = flags.prec, times = my_nbrlen(a) - 1;

    if ((int)*p_a == 0)
        for (times = 0; (int)*p_a == 0; *p_a *= 10, times++);
    if (flags.p == 0)
        prec = 6;
    if (flags.p == 1 && prec == 0) {
        *p_a = e_round(a);
    }
    status(times, prec, p_a, hh);
    return (*len);
}
