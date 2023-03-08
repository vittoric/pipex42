/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:48 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/08 18:16:25 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*envr serch for PATH, split :*/

int	main(int argc, char **argv, char **envp)
{
	char	*direction;
	int		ret;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	
	if (argc != 5)
	{
		printf("Error argv\n");
		return (-1);
	}
	else{
		direction = ft_calloc(sizeof(char *), 2);
		cmd1 = ft_split(argv[2], ' ');
		cmd2 = ft_split(argv[3], ' ');
		path = ft_split(*find_path(envp), ':');
		printf("path %s ----- cmd1 %s\n\n", path[2], *cmd1);		
		
		//verifica si el en el argv ya se ha pasado un PATH
		
		ret = access(cmd1[0], X_OK);
		if (ret == 0)
		{
			execve(cmd1[0], cmd1, envp);
			return (0);
		}
		
		if (ckeck_cmd(&direction, *cmd1, envp) == -1)
			printf("Error\n");
		else
			printf("Command found\n");
		execve(direction, cmd1, envp);
	
	}
	return (0);
}

