#include "./srcs/libftprintf.h"

int		ft_start_printing(int fd, const char *format, ...)
{
	int		select;
	int		len;

	select = -1;
	len = ft_strlen(format);
	while (++select < len && format[select])
	{
		while (format[select] && format[select] != '%')
		{
			ft_putchar(format[select]);
			select++;
		}
		if (format[select] == '%')
			break ;
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
		lenght = ft_start_printing(1, format, args);
		va_end(args);
	}
	return (lenght);
}
