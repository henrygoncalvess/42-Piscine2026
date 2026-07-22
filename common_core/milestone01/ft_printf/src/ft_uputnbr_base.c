/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:02:48 by hegoncal          #+#    #+#             */
/*   Updated: 2026/07/22 14:02:50 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr_base(unsigned int nbr, char *base);

int	ft_uputnbr_base(unsigned int nbr, char *base)
{
	int				printed_chars;
	unsigned int	base_len;
	unsigned int	unbr;

	printed_chars = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		printed_chars++;
		unbr = -(unsigned long)nbr;
	}
	else
		unbr = (unsigned long)nbr;
	if (unbr >= base_len)
		printed_chars += ft_putnbr_base(unbr / base_len, base);
	write(1, &base[unbr % base_len], 1);
	printed_chars++;
	return (printed_chars);
}
