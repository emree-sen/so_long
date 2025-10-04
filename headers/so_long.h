/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsen <emsen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:11:48 by emsen             #+#    #+#             */
/*   Updated: 2025/10/04 17:51:14 by emsen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../headers/get_next_line.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"

# define BTN_EXIT 17
# define WALL '1'
# define PLAYER 'P'
# define FLOOR '0'
# define ITEM 'C'
# define EXIT 'E'
# define SUCCESS 0
# define ERROR 1
# define MAP 0
# define MAP_COPY 1


#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_W 119
#define KEY_R 114
#define KEY_ONE 49
#define KEY_TWO 50
#define KEY_THREE 51
#define KEY_FOUR 52
#define KEY_ESC 65307
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define KEY_UP 65362

# define DIR_LEFT 	4
# define DIR_RIGHT 	6
# define DIR_UP 	8
# define DIR_DOWN 	2

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

typedef struct s_imgs
{
	void	*c;
	void	*e;
	void	*f;
	void	*p;
	void	*w;
	void	*l;
}	t_imgs;

typedef struct s_game
{
	char		**map;
	char		**map_copy;
	int			map_height;
	int			map_width;
	int			moves;
	int			item;
	t_exit		exit;
	t_imgs		imgs;
	t_player	player;
	void		*mlx;
	void		*win;
}	t_game;

typedef struct s_count
{
	int	exit;
	int	i;
	int	j;
	int	player;
}	t_count;

int			character_checker(t_game *game);
int			check_character_count(t_game *game);
int			check_game(t_game *game);
int			check_map_extensions(char *file);
int			check_map_wall(t_game *game);
int			ft_exit_game(t_game *game);
int			ft_init_images(t_game *game);
int			ft_key_hook(int key, t_game *game);
int			get_map(char *file, t_game *game);
int			map(char *file, t_game **game);
int			player_location(t_game *game, t_count character);

void		free_map(t_game *game);
void		ft_fill_flood(int x, int y, t_game *game);
void		ft_put_images(t_game *game);
void		ft_write_score(t_game *game);
void		init_game(t_game *game);
void		render_map(t_game *game);

#endif
