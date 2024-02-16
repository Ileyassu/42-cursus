/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:09:45 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 20:10:27 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_free_arr(char **tiles, int height)
{
	int	i;

	i = height;
	while (i--)
		free(tiles[i]);
	free(tiles);
	return (NULL);
}
