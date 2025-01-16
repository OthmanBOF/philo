/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:30:38 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/14 15:06:20 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/



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
            str[i] = start++;
        else
            str[i] = start--;
        i++;
    }
    return (str);
}

int main ()
{
    int *str = ft_range(0, -3);
    if (str)
    {
    int len  = (0 - -3) + 1;
    for(int i = 0; i < len ; i++)
        printf("%d; ", str[i]);
    }
}