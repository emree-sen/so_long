/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsen <emsen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:10:47 by emsen             #+#    #+#             */
/*   Updated: 2024/04/28 11:10:49 by emsen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_fill_flood(int x, int y, t_game *game)
{
	if (x < 0 || x > game->map_width - 1 || y < 0 || y > game->map_height - 1)
		return ;
	if (game->map_copy[y][x] != '1' && game->map_copy[y][x] != 'F')
	{
		game->map_copy[y][x] = 'F';
		ft_fill_flood(x, y - 1, game);
		ft_fill_flood(x, y + 1, game);
		ft_fill_flood(x - 1, y, game);
		ft_fill_flood(x + 1, y, game);
	}
}

int	check_game(t_game *game)
{
	int	i;
	int	j;

	ft_fill_flood(game->player.x, game->player.y, game);
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (i != '\0')
			{
				if (game->map_copy[i][j] != WALL &&
					game->map_copy[i][j] != 'F' &&
					game->map_copy[i][j] != FLOOR)
					return (ft_printf("The map layout is not OK for playing."),
						free_map(game), ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	return (0);
}

void	init_game(t_game *game)
{
	game->item = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->map = NULL;
}
