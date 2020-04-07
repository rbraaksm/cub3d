/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_res_color.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:00:25 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/06 16:58:47 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    data_ceiling(t_flags *d, char *str)
{
    int i;

    i = 0;
    ERROR = "CEILING COLOR ISN'T CORRECT\n";
    CRED = ft_atoi(&str[i]);
    while (str[i] == ' ')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != ',' || CRED < 0 || CRED > 255)
        return ;
    i++;
    CGREEN = ft_atoi(&str[i]);
    while (str[i] == ' ')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != ',' || CGREEN < 0 || CGREEN > 255)
        return ;
    i++;
    CBLUE = ft_atoi(&str[i]);
    if (CBLUE < 0 || CBLUE > 255)
        return ;
    CHECK += 2000000;
    ERROR = "";
}

void    data_floor(t_flags *d, char *str)
{
    int i;

    i = 0;
    ERROR = "FLOOR COLOR ISN'T CORRECT\n";
    FRED = ft_atoi(&str[i]);
    while (str[i] == ' ')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != ',' || FRED < 0 || FRED > 255)
        return ;
    i++;
    FGREEN = ft_atoi(&str[i]);
    while (str[i] == ' ')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != ',' || FGREEN < 0 || FGREEN > 255)
        return ;
    i++;
    FBLUE = ft_atoi(&str[i]);
    if (FBLUE < 0 || FBLUE > 255)
        return ;
    CHECK += 400000;
    ERROR = "";
}

void    resolution(t_flags *d, char *str)
{
    int i;

    i = 0;
    ERROR = "RESOLUTION IS NOT CORRECT\n";
    RESX = ft_atoi(str);
    if (RESX < 0 || RESX > 100000)
        return ;
    while (str[i] == ' ')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    RESY = ft_atoi(&str[i]);
    if (RESY < 0 || RESY > 100000)
        return ;
    CHECK += 40000000;
    ERROR = "";
}