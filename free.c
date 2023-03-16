/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:30:16 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/14 16:49:51 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_cmd(char **cmd_p)
{
int     i;

i = 0;
while (cmd_p[i] != 0)
{
	free(cmd_p[i]);
	i++;
}
free(cmd_p);
}

void	free_main(char **cmd1, char **cmd2, char **path)
{
	int i = 0;
	while (cmd1[i] != 0)
	{
	    free(cmd1[i]);
		i++;
	}
		free(cmd1);
		i = 0;
	while (cmd2[i] != 0)
	{
		free(cmd2[i]);
		i++;
	}
	free(cmd2);
	i = 0;
	while (path[i] != 0)
	{
		free(path[i]);
		i++;
	}
    free(path);
}
