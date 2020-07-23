/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:16:07 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/23 15:16:10 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_freemas(char **mas_line)
{
	size_t i;

	i = 0;
	while (mas_line[i] && mas_line[i][0])
	{
		free(mas_line[i]);
		i++;
	}
	free(mas_line[i]);
	free(mas_line);
	return (NULL);
}
