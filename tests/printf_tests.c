/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "my_printf.h"

Test (my_printf, simple_string, .init = cr_redirect_stdout) {
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, wrong_flag, .init = cr_redirect_stdout) {
    my_printf("%+-20kmp%Mopo");
    cr_assert_stdout_eq_str("%+-20kmp%Mopo");
}

Test (my_printf, flag_s, .init = cr_redirect_stdout) {
    char *str = "Amongus";
    my_printf("There's an impostor %s", str);
    cr_assert_stdout_eq_str("There's an impostor Amongus");
}

Test (my_printf, flag_s01, .init = cr_redirect_stdout) {
    char *str = "Amongus";
    my_printf("%10.4s", str);
    cr_assert_stdout_eq_str("      Amon");
}

Test (my_printf, flag_s02, .init = cr_redirect_stdout) {
    char *str = "Amongus";
    my_printf("%-12.6s", str);
    cr_assert_stdout_eq_str("Amongu      ");
}

Test (my_printf, flag_s03, .init = cr_redirect_stdout) {
    char *str = "Amongus";
    my_printf("%-12.sXD", str);
    cr_assert_stdout_eq_str("            XD");
}

Test (my_printf, flag_d, .init = cr_redirect_stdout) {
    my_printf("I have %d cats", 35);
    cr_assert_stdout_eq_str("I have 35 cats");
}

Test (my_printf, flag_d01, .init = cr_redirect_stdout) {
    my_printf("%-10.5dxd", -12);
    cr_assert_stdout_eq_str("-00012    xd");
}

Test (my_printf, flag_d02, .init = cr_redirect_stdout) {
    my_printf("%-08dxd", -11);
    cr_assert_stdout_eq_str("-0000011xd");
}

Test (my_printf, flag_d03, .init = cr_redirect_stdout) {
    my_printf("% 10.5d", -124);
    cr_assert_stdout_eq_str("    -00124");
}

Test (my_printf, flag_d04, .init = cr_redirect_stdout) {
    my_printf("% 10.5d", 124);
    cr_assert_stdout_eq_str("     00124");
}

Test (my_printf, flag_d05, .init = cr_redirect_stdout) {
    my_printf("%+10.5d", 124);
    cr_assert_stdout_eq_str("    +00124");
}

Test (my_printf, flag_d06, .init = cr_redirect_stdout) {
    my_printf("hi%+-10.7dbye", 6453);
    cr_assert_stdout_eq_str("hi+0006453  bye");
}

Test (my_printf, flag_d07, .init = cr_redirect_stdout) {
    my_printf("hi%+-10.7dbye", -6453);
    cr_assert_stdout_eq_str("hi-0006453  bye");
}

Test (my_printf, flag_d08, .init = cr_redirect_stdout) {
    my_printf("hi% -10.7dbye", 6453);
    cr_assert_stdout_eq_str("hi 0006453  bye");
}

Test (my_printf, flag_d09, .init = cr_redirect_stdout) {
    my_printf("hi% -10.7dbye", -6453);
    cr_assert_stdout_eq_str("hi-0006453  bye");
}

Test (my_printf, flag_d10, .init = cr_redirect_stdout) {
    my_printf("hi%010dbye", 6453);
    cr_assert_stdout_eq_str("hi0000006453bye");
}

Test (my_printf, flag_i, .init = cr_redirect_stdout) {
    int x = 12;
    my_printf("I want %i horses\n", x);
    cr_assert_stdout_eq_str("I want 12 horses\n");
}

Test (my_printf, flag_c, .init = cr_redirect_stdout) {
    my_printf("characte%c test", 'r');
    cr_assert_stdout_eq_str("character test");
}

Test (my_printf, flag_c01, .init = cr_redirect_stdout) {
    char c = 'v';
    my_printf("%6c", c);
    cr_assert_stdout_eq_str("     v");
}

Test (my_printf, flag_c02, .init = cr_redirect_stdout) {
    char c = 'T';
    my_printf("%-4cpose", c);
    cr_assert_stdout_eq_str("T   pose");
}

Test (my_printf, flag_prc, .init = cr_redirect_stdout) {
    my_printf("lol%% just %%yolo %%");
    cr_assert_stdout_eq_str("lol% just %yolo %");
}

Test (my_printf, flag_u, .init = cr_redirect_stdout) {
    my_printf("%u", -1);
    cr_assert_stdout_eq_str("4294967295");
}

Test (my_printf, flag_u01, .init = cr_redirect_stdout) {
    my_printf("%20.15uxd", 79);
    cr_assert_stdout_eq_str("     000000000000079xd");
}

Test (my_printf, flag_u02, .init = cr_redirect_stdout) {
    my_printf("%-18.12uxd", -625);
    cr_assert_stdout_eq_str("004294966671      xd");
}

Test (my_printf, flag_u03, .init = cr_redirect_stdout) {
    my_printf("%u", -3);
    cr_assert_stdout_eq_str("4294967293");
}

Test (my_printf, flag_u04, .init = cr_redirect_stdout) {
    my_printf("%023u", 0);
    cr_assert_stdout_eq_str("00000000000000000000000");
}

Test (my_printf, flag_S, .init = cr_redirect_stdout) {
    char str[5] = {'t', 6, 'o', 't', 'o'};
    my_printf("%S", str);
    cr_assert_stdout_eq_str("t\\006oto");
}

Test (my_printf, flag_S01, .init = cr_redirect_stdout) {
    char *str = "HI\n";
    my_printf("%10.4S", str);
    cr_assert_stdout_eq_str("      HI\\0");
}

Test (my_printf, flag_S02, .init = cr_redirect_stdout) {
    char *str = "HI\n";
    my_printf("%-10S", str);
    cr_assert_stdout_eq_str("HI\\012    ");
}

Test (my_printf, flag_x, .init = cr_redirect_stdout) {
    my_printf("%x", 93);
    cr_assert_stdout_eq_str("5d");
}

Test (my_printf, flag_x01, .init = cr_redirect_stdout) {
    my_printf("%20.10x", 54);
    cr_assert_stdout_eq_str("          0000000036xd");
}

Test (my_printf, flag_x02, .init = cr_redirect_stdout) {
    my_printf("%-18.13xxd", -32);
    cr_assert_stdout_eq_str("00000ffffffe0     xd");
}

Test (my_printf, flag_x03, .init = cr_redirect_stdout) {
    my_printf("%#-20.14xxd", 5371);
    cr_assert_stdout_eq_str("0x000000000014fb    xd");
}

Test (my_printf, flag_x04, .init = cr_redirect_stdout) {
    my_printf("%#20.14xxd", -2431);
    cr_assert_stdout_eq_str("    0x000000fffff681xd");
}

Test (my_printf, flag_xx, .init = cr_redirect_stdout) {
    my_printf("%X", 126);
    cr_assert_stdout_eq_str("7E");
}

Test (my_printf, flag_xx01, .init = cr_redirect_stdout) {
    my_printf("%20.10X", 54);
    cr_assert_stdout_eq_str("          0000000036xd");
}

Test (my_printf, flag_xx02, .init = cr_redirect_stdout) {
    my_printf("%-18.13X", -32);
    cr_assert_stdout_eq_str("00000FFFFFFE0     xd");
}

Test (my_printf, flag_xx03, .init = cr_redirect_stdout) {
    my_printf("%#-25.18Xxd", 54321234);
    cr_assert_stdout_eq_str("0X0000000000033CE052     xd");
}

Test (my_printf, flag_xx04, .init = cr_redirect_stdout) {
    my_printf("%#20.14Xxd", -2431);
    cr_assert_stdout_eq_str("    0X000000FFFFF681xd");
}

Test (my_printf, flag_b, .init = cr_redirect_stdout) {
    my_printf("%b", 5);
    cr_assert_stdout_eq_str("101");
}

Test (my_printf, flag_b01, .init = cr_redirect_stdout) {
    my_printf("%10.3b", 23);
    cr_assert_stdout_eq_str("       101");
}

Test (my_printf, flag_b02, .init = cr_redirect_stdout) {
    my_printf("%-8.12bXD", 23);
    cr_assert_stdout_eq_str("10111   XD");
}

Test (my_printf, flag_o, .init = cr_redirect_stdout) {
    my_printf("%o", 9);
    cr_assert_stdout_eq_str("11");
}

Test (my_printf, flag_o01, .init = cr_redirect_stdout) {
    my_printf("%-6.4oxd", 11);
    cr_assert_stdout_eq_str("0013  xd");
}

Test (my_printf, flag_o02, .init = cr_redirect_stdout) {
    my_printf("%4.1oxd", 10);
    cr_assert_stdout_eq_str("  12xd");
}

Test (my_printf, flag_o05, .init = cr_redirect_stdout) {
    my_printf("%#10o", 5);
    cr_assert_stdout_eq_str("        05");
}

Test (my_printf, flag_f, .init = cr_redirect_stdout) {
    double x = 12;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("12.000000");
}

Test (my_printf, flag_f01, .init = cr_redirect_stdout) {
    double x = 12.5001;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("12.500100");
}

Test (my_printf, flag_f02, .init = cr_redirect_stdout) {
    double x = 12.333333333333;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("12.333333");
}

Test (my_printf, flag_f03, .init = cr_redirect_stdout) {
    double x = 12.5237319;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("12.523732");
}

Test (my_printf, flag_f04, .init = cr_redirect_stdout) {
    double x = 543.999999999999;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("544.000000");
}

Test (my_printf, flag_f05, .init = cr_redirect_stdout) {
    double x = -35;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("-35.000000");
}

Test (my_printf, flag_f06, .init = cr_redirect_stdout) {
    double x = -12.4132565432;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("-12.413257");
}

Test (my_printf, flag_f07, .init = cr_redirect_stdout) {
    double x = -12.413232332;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("-12.413232");
}

Test (my_printf, flag_f08, .init = cr_redirect_stdout) {
    double x = -12.9999999999;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("-13.000000");
}

Test (my_printf, flag_f09, .init = cr_redirect_stdout) {
    double x = -12.09999999999;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("-12.100000");
}

Test (my_printf, flag_f10, .init = cr_redirect_stdout) {
    double x = 12.6996999999;
    my_printf("%f", x);
    cr_assert_stdout_eq_str("12.699700");
}

Test (my_printf, flag_f11, .init = cr_redirect_stdout) {
    double x = 12.1239;
    my_printf("%.f", x);
    cr_assert_stdout_eq_str("12");
}

Test (my_printf, flag_f12, .init = cr_redirect_stdout) {
    double x = 12.75439;
    my_printf("%.f", x);
    cr_assert_stdout_eq_str("13");
}

Test (my_printf, flag_f13, .init = cr_redirect_stdout) {
    double x = -12.1239;
    my_printf("%.f", x);
    cr_assert_stdout_eq_str("-12");
}

Test (my_printf, flag_f14, .init = cr_redirect_stdout) {
    double x = -12.75439;
    my_printf("%.f", x);
    cr_assert_stdout_eq_str("-13");
}

Test (my_printf, flag_f15, .init = cr_redirect_stdout) {
    double x = -12.75439;
    my_printf("%.0f", x);
    cr_assert_stdout_eq_str("-13");
}

Test (my_printf, flag_f16, .init = cr_redirect_stdout) {
    double x = 453.413253;
    my_printf("%16.10f", x);
    cr_assert_stdout_eq_str("  453.4132530000");
}

Test (my_printf, flag_f17, .init = cr_redirect_stdout) {
    double x = 453.413253;
    my_printf("%10.4f", x);
    cr_assert_stdout_eq_str("  453.4133");
}

Test (my_printf, flag_f18, .init = cr_redirect_stdout) {
    double x = -453.413253;
    my_printf("%5.8f", x);
    cr_assert_stdout_eq_str("-453.41325300");
}

Test (my_printf, flag_f19, .init = cr_redirect_stdout) {
    double x = 453.4132532543;
    my_printf("% 25.9f", x);
    cr_assert_stdout_eq_str("            453.413253254");
}

Test (my_printf, flag_f20, .init = cr_redirect_stdout) {
    double x = -453.4132532543;
    my_printf("% 25.9f", x);
    cr_assert_stdout_eq_str("           -453.413253254");
}

Test (my_printf, flag_f21, .init = cr_redirect_stdout) {
    double x = -453.4132532543;
    my_printf("% 25.9f", x);
    cr_assert_stdout_eq_str("           -453.413253254");
}

Test (my_printf, flag_f22, .init = cr_redirect_stdout) {
    double x = 453.4132532543;
    my_printf("% 025.9f", x);
    cr_assert_stdout_eq_str(" 00000000000453.413253254");
}

Test (my_printf, flag_f23, .init = cr_redirect_stdout) {
    double x = 453.4132532543;
    my_printf("% -25.9f", x);
    cr_assert_stdout_eq_str(" 453.413253254           ");
}

Test (my_printf, flag_f24, .init = cr_redirect_stdout) {
    double x = -453.4132532543;
    my_printf("% -25.9f", x);
    cr_assert_stdout_eq_str("-453.413253254           ");
}

Test (my_printf, flag_f25, .init = cr_redirect_stdout) {
    double x = 453.4132532543;
    my_printf("%+25.9f", x);
    cr_assert_stdout_eq_str("           +453.413253254");
}

Test (my_printf, flag_f26, .init = cr_redirect_stdout) {
    double x = -453.4132532543;
    my_printf("%+25.9f", x);
    cr_assert_stdout_eq_str("           -453.413253254");
}

Test (my_printf, flag_f27, .init = cr_redirect_stdout) {
    double x = 453.4132532543;
    my_printf("%+-25.9f", x);
    cr_assert_stdout_eq_str("+453.413253254           ");
}

Test (my_printf, flag_f28, .init = cr_redirect_stdout) {
    double x = -453.4132532543;
    my_printf("%+-25.9f", x);
    cr_assert_stdout_eq_str("-453.413253254           ");
}

Test (my_printf, flag_f29, .init = cr_redirect_stdout) {
    double x = -453.4132532543;
    my_printf("%+-#25.f", x);
    cr_assert_stdout_eq_str("-453.                    ");
}

Test (my_printf, flag_f30, .init = cr_redirect_stdout) {
    double x = 453.4132532543;
    my_printf("%+#25.f", x);
    cr_assert_stdout_eq_str("                    +453.");
}

Test (my_printf, flag_n, .init = cr_redirect_stdout) {
    int x = 0;
    my_printf("HOLA%-4.3sxd%dlol%x%S%n", "verga", 135, 76, "hi\n", &x);
    cr_assert_eq(x, 24);
    cr_assert_stdout_eq_str("HOLAver xd135lol4chi\\012");
}

Test (my_printf, mixsd_flags, .init = cr_redirect_stdout) {
    char *s = "Joel";
    int d = 19;
    int i = -12;
    char c = 'P';
    int b = 7;
    int u = 76;
    char *S = "HI\n";
    int x = 35;
    int o = 12;
    my_printf("%s %d %i %c %b %u %S %x %o", s, d, i, c, b, u, S, x, o);
    cr_assert_stdout_eq_str("Joel 19 -12 P 111 76 HI\\012 23 14");
}
