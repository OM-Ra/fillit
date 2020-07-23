/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:08:43 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/22 09:08:45 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_errorchar(char *line)
{
	char *str;

	str = line;
	while (*str)
	{
		if (!(*str == '#' || *str == '.' || *str == '\0'))
		{
			free(line);
			return (ft_puterror(1, NULL, 1));
		}
		str++;
	}
	return (0);
}

static int	ft_checkfile(int *num_blocks, int *num_points,
							int *num_line, char *line)
{
	(*num_line)++;
	*num_blocks += ft_count_char(line, '#');
	*num_points += ft_count_char(line, '.');
	if (*num_blocks > 4 || *num_points > 12 || *num_line > 4)
	{
		free(line);
		return (ft_puterror(1, NULL, 1));
	}
	return (0);
}

static int	ft_errorelem(char *line, int len)
{
	static int num_blocks;
	static int num_points;
	static int num_line;

	if (ft_errorchar(line))
		return (1);
	if (len > 0)
	{
		if (ft_checkfile(&num_blocks, &num_points, &num_line, line))
			return (1);
	}
	else if (!len)
		if (num_blocks != 0 && num_points != 0)
		{
			if (num_blocks == 4 && num_points == 12 && num_line == 4)
			{
				num_line = 0;
				num_blocks = 0;
				num_points = 0;
			}
			else
				return (ft_puterror(1, NULL, 1));
		}
	return (0);
}

static int	ft_errornewline(const int fd)
{
	char	*line;
	int		flag;
	int		num_newline;
	int		iter;

	num_newline = 0;
	iter = 0;
	while ((flag = get_next_line(fd, &line)) > 0)
	{
		iter++;
		flag = (int)ft_strlen(line);
		if (ft_errorelem(line, flag))
			return (1);
		if (!flag)
			num_newline++;
		else if (flag > 0)
			num_newline = 0;
		free(line);
		if (num_newline > 1 || (flag != 0 && flag != 4))
			return (ft_puterror(1, NULL, 1));
	}
	free(line);
	if (flag < 0 || iter < 4)
		return (ft_puterror(1, NULL, 1));
	return (0);
}

int			ft_errorfile(char **av)
{
	int fd;

	if ((fd = ft_fdopen_rdonly(av[1])) == -1)
		return (1);
	if (ft_errornewline(fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
