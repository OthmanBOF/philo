/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:44:07 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/16 16:49:07 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = 0;
    if (start < end)
        len = (end - start) + 1;
    else if (start > end)
        len = (start - end) + 1;
    int *str = (int *)malloc(sizeof(int) * len);
    while ( i < len)
    {
        if (start < end)
            str[i] = end--;
        else
            str[i] = end++;
        i++;
    }
    return (str);
}

int main ()
{
    int *str = ft_range(1, 5);
    if (str)
    {
    int len  = (5 - 1) + 1;
    for(int i = 0; i < len ; i++)
        printf("%d; ", str[i]);
    }
}