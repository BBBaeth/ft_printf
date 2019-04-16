/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:18:12 by ceugene           #+#    #+#             */
/*   Updated: 2019/04/16 17:38:19 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/libftprintf.h"

int		ft_start_printing(const char *format, ...)
{
	int		start;
	int		select;
	int		len;

	start = 0;
	select = -1;
	len = ft_strlen(format);
	while (++select < len && format[select])
	{
		while (format[select] && format[select] != '%')
			select++;
		write(1, format + start, select - start);
		start += select - start;
		if (format[select] == '%')
		{
			select += ft_jump_arg();
			ft_display_arg();
		}
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	int		lenght;
	va_list	args;

	lenght = 0;
	if (format)
	{
		va_start(args, format);
		lenght = ft_start_printing(format, args);
		va_end(args);
	}
	return (lenght);
}
