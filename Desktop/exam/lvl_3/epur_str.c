/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:56:54 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/16 18:06:35 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdlib.h>

int main (int ac, char **av)
{
    int i = 0;
    // int j = 0;
    if (ac == 2)
    {   
        while (av[1][i] == 32)
            i++;
        while (av[1][i])
        {
            if (av[1][i] && av[1][i] != 32)
                write(1, &av[1][i], 1);
            else if (av[1][i] == 32 && av[1][i + 1] == 32)
                i++;
            else if (av[1][i] && av[1][i + 1] != 32 && av[1][i + 1])
                write(1, " ", 1);
            else if (!av[1][i])
                exit(1);
            i++;
        }
    }
    write(1, "\n", 1);
}



/*db ana khassni nctchi kolla klma o nskippi spaces o ndir 7daha lklma tanya ila akhir string */