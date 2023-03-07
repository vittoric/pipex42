/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:49:06 by vcodrean          #+#    #+#             */
/*   Updated: 2022/10/01 10:06:09 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* test any char for an alphabetic char */

int	ft_isalpha(int v)
{
	if ((v >= 'A' && v <= 'Z') || (v >= 'a' && v <= 'z'))
		return (1);
	return (0);
}