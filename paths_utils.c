/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:33:18 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/07 13:37:21 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Encontrat PATH con memcmp y cortar a partir de PATH y hacer slip de ':' 
*/

char    **cut_path(char *envp)
{
    char    **path;

    path = ft_split(envp, ' ');
    return (path);
}

char    **find_path(char **envp)
{
    char    *path;
    int     ctr;

    path = 0;
    ctr = 0;
    while (envp[ctr])
    {
        if (ft_memcmp(envp[ctr], "PATH=/", 6) == 0)
        {
            path = ft_strdup(envp[ctr]);
            path+= 5;
            break;
        }
        ctr++;
    }
    return (cut_path(path));
}

int ckeck_cmd (char **correct, const char *cmd, char **envp)
{
    char    *path_env;
    char    **path_list;
    char    *file_path;
    int     ret;
    int     i;
    
    file_path = NULL;
    ret = -1;
    i = 0;
    if (!correct || !cmd || !envp)
        return (-1);
     // Obtener las rutas de $PATH
    path_env = *find_path(envp);
    if (!path_env)
        return (-1);
    path_list = ft_split(path_env, ':');
    if (!path_list)
        return (-1);
     // Verificar si el archivo existe y es ejecutable
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
     // Asignar el valor de file_path a correct y retorna
    *correct = file_path;
    return (ret);    
}