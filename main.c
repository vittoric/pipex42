/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:48 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/14 20:20:24 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**direction;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	if (argc == 5)
	{
		direction = ft_calloc(sizeof(char *), 2);
		cmd1 = ft_split(argv[2], ' ');
		cmd2 = ft_split(argv[3], ' ');
		path = ft_split(find_path(envp), ':');
		direction[0] = ckeck_path(path, cmd1[0]);
		direction[1] = ckeck_path(path, cmd2[0]);
		pipex(argv, envp, direction);
		free(direction[0]);
		free(direction[1]);
		free(direction);
		free_main(cmd1, cmd2, path);
	}
	else
	{
		//ft_putstr_fd("Error. Bad arguments\n", 2);
		ft_putstr_fd("Use -> ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 1);
		exit (1);
	}
	return (0);
}
