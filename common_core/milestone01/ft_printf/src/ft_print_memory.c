/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-13 14:34:04 by hegoncal          #+#    #+#             */
/*   Updated: 2026-07-13 14:34:04 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(void *ptr, char *base);
int	ft_print_hex(unsigned long nbr, char *base);

int	ft_print_memory(void *ptr, char *base)
{
	unsigned long	addr;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	return (ft_print_hex(addr, base) + 2);
}

int	ft_print_hex(unsigned long nbr, char *base)
{
	unsigned long	printed_chars;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	printed_chars = 0;
	if (nbr >= base_len)
		printed_chars += ft_print_hex(nbr / base_len, base);
	write(1, &base[nbr % base_len], 1);
	printed_chars++;
	return (printed_chars);
}
