/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:43:28 by pahenriq          #+#    #+#             */
/*   Updated: 2026/09/09 22:50:09 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ps(t_ps *ps)
{
	stack_clear(&ps->a);
	stack_clear(&ps->b);
}

void	init_ps(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->disorder = 0.0;
	ps->strategy = 0;
	ps->adap_strategy = 0;
	ps->bench_mode = 0;
	ps->operations.sa = 0;
	ps->operations.sb = 0;
	ps->operations.ss = 0;
	ps->operations.pa = 0;
	ps->operations.pb = 0;
	ps->operations.ra = 0;
	ps->operations.rb = 0;
	ps->operations.rr = 0;
	ps->operations.rra = 0;
	ps->operations.rrb = 0;
	ps->operations.rrr = 0;
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc == 1)
		return (0);
	init_ps(&ps);
	ps.strategy = ADAPTIVE;
	if (!parse_args(argc, argv, &ps))
	{
		free_ps(&ps);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	dispatch_strategy(&ps);
	if (ps.bench_mode)
		print_bench(&ps);
	free_ps(&ps);
	return (0);
}
