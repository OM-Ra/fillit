/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:38:39 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/23 15:38:43 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sqrmap(int abs, char **mas_line)
{
	int i;

	i = 0;
	while (mas_line[i][0])
		i++;
	i *= 4;
	while (i > (abs * abs))
		abs++;
	return (abs);
}

static char	*ft_newmap(int abs)
{
	char	*newmap;
	size_t	i;
	int		len;
	size_t	num;

	i = 0;
	len = 0;
	num = (size_t)(abs * abs + abs + 1);
	if (!(newmap = ft_strnew(sizeof(char) * num)))
		return ((char *)ft_str_puterror(1, NULL));
	while (i < (num - 1))
	{
		if (len == abs)
		{
			len = 0;
			newmap[i] = '\n';
		}
		else
		{
			len++;
			newmap[i] = '.';
		}
		i++;
	}
	return (newmap);
}

char		*ft_map(int *abs, char **mas_line)
{
	*abs = ft_sqrmap(*abs, mas_line);
	return (ft_newmap(*abs));
}
