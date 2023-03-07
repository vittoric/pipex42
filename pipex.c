/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:48 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/07 12:14:51 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*envr serch for PATH, split :*/

int	main(int argc, char **argv, char **envp)
{
	char	**mycmds;
	char	*correct_path;

	correct_path = 0;
	if (argc > 1 && argv)
		printf("There are args\n");
	mycmds = ft_split(argv[1], ' ');
	printf("Comands: %s   %s\n", mycmds[0], mycmds[1]);
	if(envp)
		printf("Hola\n");
	return (0);
}

