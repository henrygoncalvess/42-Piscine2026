/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 21:23:05 by hegoncal          #+#    #+#             */
/*   Updated: 2026/07/22 14:23:32 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s);

int	ft_print_str(char *s)
{
	int	i;
	int	printed_chars;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	printed_chars = 0;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		printed_chars++;
		i++;
	}
	return (printed_chars);
}
