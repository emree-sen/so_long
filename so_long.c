/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsen <emsen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:07:41 by emsen             #+#    #+#             */
/*   Updated: 2024/04/28 11:07:43 by emsen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	ft_window(t_game *game)
{
	mlx_key_hook(game->win, ft_key_hook, game);
	mlx_hook(game->win, BTN_EXIT, 0, ft_exit_game, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		return (ft_printf("Check to parameters!\n"), ERROR);
	if (map(av[1], &game) != SUCCESS)
		return (ERROR);
	if (game->map_height > 20 || game->map_width > 40)
	{
		ft_printf("The map size is so big!");
		free_map(game);
	}
	render_map(game);
	ft_window(game);
	free_map(game);
	free(game);
	return (0);
}
