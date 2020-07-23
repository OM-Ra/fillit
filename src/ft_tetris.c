/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:30:51 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/23 15:30:54 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_checkwrite(int abs, size_t i_line, size_t flag)
{
	size_t i_map;

	i_map = 0;
	i_map += (abs - 1) * (i_line - flag == 3);
	i_map += (abs) * (i_line - flag == 4);
	i_map += (abs + 1) * (i_line - flag == 5);
	i_map += (i_line - flag == 1);
	return (i_map);
}

static int		ft_writeinmap(char *mas_line, char *map, size_t i_map, char sim)
{
	size_t	i_line;
	size_t	flag;
	int		abs;

	i_line = 0;
	abs = ft_count_abs(map);
	while (mas_line[i_line] != '#')
		i_line++;
	flag = i_line;
	while (mas_line[i_line])
	{
		if (mas_line[i_line] == '#')
		{
			i_map += ft_checkwrite(abs, i_line, flag);
			if (map[i_map] == '.')
			{
				flag = i_line;
				map[i_map] = sim;
			}
			else
				return (0);
		}
		i_line++;
	}
	return (1);
}

static void		ft_remap(char *map, char sim)
{
	size_t i_map;

	i_map = 0;
	while (map[i_map])
	{
		if (map[i_map] == sim)
			map[i_map] = '.';
		i_map++;
	}
}

static char		*ft_maprec(char **mas_line, char *map, size_t i_line, char sim)
{
	size_t i_map;

	i_map = 0;
	if (!mas_line[i_line][0])
		return (map);
	while (map[i_map])
	{
		if (ft_writeinmap(mas_line[i_line], map, i_map, sim))
		{
			if (ft_maprec(mas_line, map, (i_line + 1), (sim + 1)))
				return (map);
			else
				ft_remap(map, sim);
		}
		else
			ft_remap(map, sim);
		i_map++;
	}
	return (NULL);
}

char			*ft_tetris(char **mas_line)
{
	int		abs;
	char	*map;
	char	*buff;
	char	sim;
	size_t	i_line;

	abs = 2;
	sim = 'A';
	i_line = 0;
	if (!(map = ft_map(&abs, mas_line)))
		return (NULL);
	buff = map;
	while (!(map = ft_maprec(mas_line, map, i_line, sim)))
	{
		free(buff);
		abs++;
		if (!(map = ft_map(&abs, mas_line)))
			return ((char *)ft_freemas(mas_line));
		buff = map;
	}
	return (map);
}
