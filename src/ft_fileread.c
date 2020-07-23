/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:07:29 by mdelphia          #+#    #+#             */
/*   Updated: 2019/06/02 16:04:54 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_tieblocks(char **mas_line, size_t i, size_t j)
{
	int tie;

	tie = 0;
	if (j > 3)
		tie += (mas_line[i][j - 5] == '#');
	if (j > 0)
		tie += (mas_line[i][j - 1] == '#');
	if (j < 15)
		tie += (mas_line[i][j + 5] == '#');
	tie += (mas_line[i][j + 1] == '#');
	return (tie);
}

static int	ft_validblocks(char **mas_line)
{
	size_t	i;
	size_t	j;
	int		tie;

	i = 0;
	j = 0;
	while (mas_line[i][j])
	{
		tie = 0;
		while (mas_line[i][j])
		{
			if (mas_line[i][j] == '#')
				tie += ft_tieblocks(mas_line, i, j);
			j++;
		}
		if (tie < 6 || i > 25)
			return (ft_puterror(1, NULL, 1));
		i++;
		j = 0;
	}
	return (0);
}

static int	ft_read(int fd, char *mas, int *flag, char **newline)
{
	if ((*flag = read(fd, mas, 20)) < 0)
		return (ft_puterror(1, NULL, 1));
	if (*flag < 20)
		return (ft_puterror(1, NULL, 1));
	if (!(*newline = ft_strnew(20)))
		return (ft_puterror(1, NULL, 1));
	return (0);
}

static int	ft_maswrite(int fd, char **mas_line)
{
	int		flag;
	size_t	i;
	char	mas[21];
	char	*newline;

	flag = 0;
	i = 0;
	mas[20] = '\0';
	while (1)
	{
		if (ft_read(fd, mas, &flag, &newline))
			return (1);
		mas_line[i] = ft_strcpy(newline, mas);
		i++;
		if ((flag = read(fd, mas, 1)) < 0)
			return (ft_puterror(1, NULL, 1));
		if (flag == 0)
			break ;
	}
	if (!(mas_line[i] = ft_strnew(1)))
		return (1);
	if (i > 27)
		return (ft_puterror(1, NULL, 1));
	return (0);
}

char		**ft_fileread(char **av)
{
	char	**mas_line;
	int		fd;

	if (!(mas_line = (char **)malloc(sizeof(char *) * 27)))
		return ((char **)ft_str_puterror(1, NULL));
	if ((fd = ft_fdopen_rdonly(av[1])) < 0)
		return (NULL);
	if (ft_maswrite(fd, mas_line))
		return (ft_freemas(mas_line));
	if (ft_validblocks(mas_line))
		return (ft_freemas(mas_line));
	close(fd);
	return (mas_line);
}
