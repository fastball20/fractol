/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:24:15 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/04 14:56:14 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	init(t_screen *screen, int flag)
{
	if (flag != 1)
	{
		screen->mlx = mlx_init();
		screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "fractol");
		init_image(screen);
	}
	screen->scale = 1;
	screen->offset_x = 0;
	screen->offset_y = 0;
	screen->iteration = 10;
}

void	display_error(int cond, char *str)
{
	if (cond)
	{
		ft_putendl(str);
		exit(0);
	}
}

static	void	display_fractals_name()
{
	ft_putstr("usage : fractol [flactals]\n  fractals : \n"
			" --> mandelbrot\n --> julia\n --> mandelbrot\n"
			" --> tricorn\n --> sierpinski\n --> barnsley\n"
			 " --> sun\n");
}

int		main(int argc, char **argv)
{
	t_screen  *screen;

	screen = (t_screen *)ft_memalloc(sizeof(t_screen));
	init(screen, 0);
	display_error(argc != 2, "arguments error");
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		screen->id = 0;
		julia(screen);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		screen->id = 1;
		mandelbrot(screen);
	}
	else if (ft_strcmp(argv[1], "tricorn") == 0)
	{
		screen->id = 2;
		tricorn(screen);	
	}
	else if (ft_strcmp(argv[1], "burning-ship") == 0)
	{
		screen->id = 3;
		burning_ship(screen);
	}
	else if (ft_strcmp(argv[1], "sierpinski") == 0)
	{
		screen->id = 4;
		sierpinski(screen);
	} 
	else if (ft_strcmp(argv[1], "barnsley") == 0)
	{
		screen->id = 5;
		barnsley(screen);
	}
	else if (ft_strcmp(argv[1], "sun") == 0)
	{
		screen->id = 6;
		sunflower(screen);
	}
	else
	{
		display_fractals_name();
		exit(0);
	}
	mlx_hook(screen->win, 2, 0, key_press, screen);
	mlx_mouse_hook(screen->win, mouse_move, screen);
	mlx_loop(screen->mlx);
	return (0);
}

