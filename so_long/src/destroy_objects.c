/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:55:59 by ilyas             #+#    #+#             */
/*   Updated: 2024/02/27 20:58:51 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void destroy_objects(t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx, mlx->img->player_up);
    mlx_destroy_image(mlx->mlx, mlx->img->player_left);
    mlx_destroy_image(mlx->mlx, mlx->img->player_right);
    mlx_destroy_image(mlx->mlx, mlx->img->player_down);
    mlx_destroy_image(mlx->mlx, mlx->img->background);
    mlx_destroy_image(mlx->mlx, mlx->img->salah);
    mlx_destroy_image(mlx->mlx, mlx->img->drhm);
    mlx_destroy_image(mlx->mlx, mlx->map->img);
    mlx_destroy_image(mlx->mlx, mlx->p_img);
}