/*
** EPITECH PROJECT, 2022
** CPool_0
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
