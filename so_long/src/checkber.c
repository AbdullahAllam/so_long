/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:34 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:18:36 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	checkber(char *name)
{
	int	length;

	length = ft_strlen(name);
	if (*name == '\0' || name == 0 || length <= 4
		|| ft_strcmp(".ber", &name[length - 4]) != 0)
		return (0);
	return (1);
}
