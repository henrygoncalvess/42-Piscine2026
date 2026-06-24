/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-23 17:51:13 by hegoncal          #+#    #+#             */
/*   Updated: 2026-06-23 17:51:13 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_print_conversion(char c, va_list *args);
int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);

int	ft_uputnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_base(long nbr, char *base);
int	ft_print_memory(void *ptr, char *base);

#endif
