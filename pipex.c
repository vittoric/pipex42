/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:48 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/07 16:04:28 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*envr serch for PATH, split :*/

int	main(int argc, char **argv, char **envp)
{
	char	**mycmds;
	char	*correct_path;
	int		ret;

	correct_path = 0;
	if (argc > 1 && argv)
		printf("There are args\n");
	mycmds = ft_split(argv[1], ' ');
	//verifica si el en el argv ya se ha pasado un PATH
	ret = access(mycmds[0], X_OK);
     if (ret == 0)
    {
        correct_path = mycmds[0];
		execve(correct_path, mycmds, envp);
        return (0);
    }
	if (ckeck_cmd(&correct_path, *mycmds, envp) == -1)
		printf("Error\n");
	else
		printf("Command found\n");
	printf("Comands: %s   %s\n", mycmds[0], mycmds[1]);
	execve(correct_path, mycmds, envp);
	return (0);
}

