/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:45:04 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/16 17:28:06 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd, char *direction)
{
	int		infile;
	char	**cmd_c;

	cmd_c = ft_split(argv[2], ' ');
	close(fd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_fd_error(argv[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve (direction, cmd_c, envp) < 0)
		exit(errno);
}

void	parent_process(char **argv, char **envp, int *fd, char *direction)
{
	int		outfile;
	char	**cmd_p;
	pid_t	pid;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		perror("Error");
	cmd_p = ft_split(argv[3], ' ');
	pid = fork();
	close(fd[1]);
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
		if (execve (direction, cmd_p, envp) < 0)
			exit(errno);
	}
	else if (pid == -1)
		perror("Error");
	else
		close(fd[0]);
	free_cmd(cmd_p);
}

int	pipex(char **argv, char **envp, char **direction)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		perror("Error");
	else if (pid == 0)
		child_process(argv, envp, fd, direction[0]);
	else
		parent_process(argv, envp, fd, direction[1]);
	waitpid(pid, &status, WNOHANG);
	waitpid(pid, &status, WNOHANG);
	return (status);
}
