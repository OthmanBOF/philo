/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:08:37 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/12 17:18:38 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    char *tmp;

    while (src[i])
        i++;
    tmp = malloc(i + 1);
    if (!tmp)
        return (NULL);
    i = 0;
    while (src[i])
    {
        tmp[i] = src[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

#include <stdio.h>

int main ()
{
    printf("%s\n%s", ft_strdup("dazai"), "dazai");
}
// int main()
// {
// 	char	*a;
// 	a = "Hello World";
// 	printf("%s\n", ft_strdup(a));
// }