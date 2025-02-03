/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsen <emsen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:11:11 by emsen             #+#    #+#             */
/*   Updated: 2024/04/28 14:31:31 by emsen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	render_map(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("mlx cannot be initialized");
		free_map(game);
		exit(0);
	}
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, " S O _ L O N G ");
	if (!game->win)
	{
		ft_printf("win cannot be initialized");
		free_map(game);
		exit(0);
	}
	if (ft_init_images(game) != SUCCESS)
		free_map(game);
	ft_put_images(game);
}

static void	ft_put_img(t_game *game, char c, int x, int y)
{
	if (c == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.f, x, y);
	else if (c == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.w, x, y);
	else if (c == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.p, x, y);
	else if (c == ITEM)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.c, x, y);
	else if (c == EXIT)
	{
		if (game->player.x == game->exit.x && game->player.y == game->exit.y)
			mlx_put_image_to_window(game->mlx, game->win, game->imgs.l, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->imgs.e, x, y);
	}
}

void	ft_put_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			ft_put_img(game, game->map[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
	ft_write_score(game);
}

int	ft_init_images(t_game *game)
{
	int	x;
	int	y;

	game->imgs.p = mlx_xpm_file_to_image(game->mlx,
			"images/stitch.xpm", &x, &y);
	if (!game->imgs.p)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.e = mlx_xpm_file_to_image(game->mlx, "images/lilo.xpm", &x, &y);
	if (!game->imgs.e)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.c = mlx_xpm_file_to_image(game->mlx,
			"images/cookie.xpm", &x, &y);
	if (!game->imgs.c)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.f = mlx_xpm_file_to_image(game->mlx, "images/grass.xpm", &x, &y);
	if (!game->imgs.f)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.w = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &x, &y);
	if (!game->imgs.w)
		return (ft_printf("wall file cannot be found"), free_map(game), ERROR);
	game->imgs.l = mlx_xpm_file_to_image(game->mlx, "images/l-a-s.xpm", &x, &y);
	if (!game->imgs.l)
		return (ft_printf("wall file cannot be found"), free_map(game), ERROR);
	return (SUCCESS);
}
