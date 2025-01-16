/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:20:14 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/13 16:57:51 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
char    *ft_strrev(char *str)
{
    char tmp;
    int i = 0;
    int j = 0;
    while (str[j])
        j++;
    while (i < j - 1)
    {
        tmp = str[i];
        str[i] = str[j - 1];
        str[j - 1] = tmp;
        i++;
        j--;
    }
    return (str);
}
int main ()
{
    char str[] = "dazai";
    printf("%s\n", ft_strrev(str));
}