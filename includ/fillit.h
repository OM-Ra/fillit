/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:26:12 by mdelphia          #+#    #+#             */
/*   Updated: 2019/06/02 15:26:18 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include "get_next_line.h"
# include "libft.h"

int		main(int ac, char **av);
int		ft_errorfile(char **av);
int		ft_fdopen_rdonly(char *av);
char	**ft_fileread(char **av);
char	**ft_freemas(char **mas_line);
char	*ft_map(int *abs, char **mas_line);
char	*ft_tetris(char **mas_line);
int		ft_count_abs(char *map);

#endif
