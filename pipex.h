/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:26:31 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/07 13:34:15 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H
# include <string.h>
# include <stdio.h>
# include <sys/stat.h>
# include <stdarg.h>
# include <fcntl.h>
//# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

int	            main(int argc, char **argv, char **envp);
int             ckeck_cmd (char **correct, const char *cmd, char **envp);
char            **find_path(char **envp);
char     **cut_path(char *envp);


#endif
