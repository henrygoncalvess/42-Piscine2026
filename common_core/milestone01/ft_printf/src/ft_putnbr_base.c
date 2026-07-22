/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-13 12:25:36 by hegoncal          #+#    #+#             */
/*   Updated: 2026-07-13 12:25:36 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long nbr, char *base);

int	ft_putnbr_base(long nbr, char *base)
{
	int		printed_chars;
	size_t	base_len;
	size_t	unbr;

	printed_chars = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		printed_chars++;
		unbr = -(size_t)nbr;
	}
	else
		unbr = (size_t)nbr;
	if (unbr >= base_len)
		printed_chars += ft_putnbr_base(unbr / base_len, base);
	write(1, &base[unbr % base_len], 1);
	printed_chars++;
	return (printed_chars);
}
