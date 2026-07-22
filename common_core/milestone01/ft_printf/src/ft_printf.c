/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:02:05 by hegoncal          #+#    #+#             */
/*   Updated: 2026/07/22 14:24:15 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	va_start(args, format);
	printed_chars = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			printed_chars += ft_print_conversion(format[i + 1], &args);
			i++;
		}
		else
			printed_chars += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (printed_chars);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	ft;
// 	int	og_result1;
// 	int	og_result2;
// 	int	og_result3;
// 	int	my_result1;
// 	int	my_result2;
// 	int	my_result3;
// 	int	my_result4;

// 	ft = 42;
// 	printf("OG_PRINTF:\n");
// 	og_result1 = printf("%%c: %c\n%%s: %s\n%%d+: %d\n%%d-: %d\n", 'A', "str",
// 			11, -11);
// 	og_result2 = printf("%%i: %i\n%%u+: %u\n%%u-: %u\n", 67, 42, -42);
// 	og_result3 = printf("%%x+: %x\n%%x-: %x\n%%p+: %p\n%%p-: %p\n", 7777, -7777,
// 			&ft, NULL);
// 	printf("\nOG_RESULT: %i\n\n", og_result1 + og_result2 + og_result3);
// 	ft_printf("-  -  -  -  -  -  -\n\nMY_PRINTF:\n");
// 	my_result1 = ft_printf("%%c: %c\n%%s: %s\n%%d+: %d\n%%d-: %d\n", 'A', "str",
// 			11, -11);
// 	my_result2 = ft_printf("%%i: %i\n%%u+: %u\n%%u-: %u\n", 67, 42, -42);
// 	my_result3 = ft_printf("%%x+: %x\n%%x-: %x\n%%p+: %p\n%%p-: %p\n", 7777,
// 			-7777, &ft, NULL);
// 	my_result4 = ft_printf(" NULL %s NULL ", NULL);
// 	printf("\nMY_RESULT: %i\n", my_result1 + my_result2 + my_result3
// 			+ my_result4);
// }
