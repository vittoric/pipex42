/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:33:18 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/14 20:16:30 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 3) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (0);
}

int	ckeck_cmd(char **correct, const char *cmd, char **envp)
{
	char	**path_list;
	char	*file_path;
	int		ret;
	int		i;

	file_path = NULL;
	ret = -1;
	i = 0;
	if (!correct || !cmd || !envp)
		return (-1);
	path_list = ft_split(find_path(envp), ':');
	if (!path_list)
		return (-1);
	while (path_list[i] && ret == -1)
	{
		file_path = ft_strjoin(path_list[i], "/");
		file_path = ft_strjoin(file_path, cmd);
		ret = access(file_path, X_OK);
		i++;
	}
	if (ret == -1)
	{
		free(file_path);
		file_path = NULL;
	}
	free(path_list);
	*correct = file_path;
	return (ret);
}

int	add_path(char **full_path, char *path, char *cmd)
{
	char	*temp;
	int		acs;

	acs = access(cmd, X_OK);
	if (acs == 0)
	{
		*full_path = ft_strdup(cmd);
		return (0);
	}
	temp = ft_strjoin (path, "/");
	*full_path = ft_strjoin(temp, cmd);
	acs = access (*full_path, X_OK);
	free (temp);
	if (acs == 0)
		return (0);
	else
		return (1);
}

char	*ckeck_path(char **path, char *cmd)
{
	char	*full_path;
	int		i;

	full_path = NULL;
	i = 0;
	while (path[i] != NULL)
	{
		if (add_path(&full_path, path[i], cmd) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	full_path = 0;
	return (full_path);
}
