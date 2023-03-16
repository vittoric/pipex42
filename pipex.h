/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:26:31 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/16 16:45:51 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
# include "libft/libft.h"

int		main(int argc, char **argv, char **envp);
char	*find_path(char **envp);
char	*ckeck_path(char **path, char *cmd);
int		add_path(char **full_path, char *path, char *cmd);
int		pipex(char **argv, char **envp, char **direction);
void	parent_process(char **argv, char **envp, int *fd, char *direction);
void	child_process(char **argv, char **envp, int *fd, char *direction);
void	free_cmd(char **cmd_p);
void	free_main(char **cmd1, char **cmd2, char **path);
void	ft_fd_error(char *str);
void	cmd_not_fd(char *cmd);


#endif