/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:48 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/13 18:56:37 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
int main (int argc, char **argv, char **envp)
{
	char	**firs_cmd;
	char	**second_cmd;
	int i = argc;
	char **path  = ft_split(*find_path(envp), ':');
	

	firs_cmd = ft_split(argv[1], ' ');
	second_cmd = ft_split(argv[2], ' ');
	access(*firs_cmd, X_OK);

    printf("%i\n", i);
	printf("%s\n", *path);
    printf("%s\n", *firs_cmd);
	printf("%s\n", *second_cmd);
	int ret = access(firs_cmd[0], X_OK);
	 printf("%i\n", ret);
		if (ret == 0)
		{
			execve(*path, firs_cmd, envp);
			return (0);
		}
	
}
*/

/*envr serch for PATH, split :*/


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
		path = ft_split(*find_path(envp), ':');
		direction[0] = ckeck_path(path, cmd1[0]);
		direction[1] = ckeck_path(path, cmd2[0]);
		//pipex(argv, envp, direction);
		
		//printf("path %s ----- cmd1 %s\n\n", path[2], *cmd1);		
		//printf("Direction %s \n", direction[0]);
		//printf("Direction %s \n", direction[1]);
		pipex(argv, envp, direction);
		//system("leaks pipex");
	}
		
		//verifica si el en el argv ya se ha pasado un PATH
		
	/*
		if (ckeck_cmd(direction, *cmd1, envp) == -1)
		{
			ft_putstr_fd("Error: command not found\n", 2);
			exit (1);
		}
		else
			printf("Command found\n");
			execve(direction[1], cmd2, envp);
		execve(*direction, cmd1, envp);
		printf("segundo comando\n");
		
		
	}*/
	else
	{
		ft_putstr_fd("Error. Bad arguments\n", 2);
		ft_putstr_fd("Use -> ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 1);
		//exit (1);
	}
	return (0);

}

