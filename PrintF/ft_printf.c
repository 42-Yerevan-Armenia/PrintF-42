/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:13:11 by arakhurs          #+#    #+#             */
/*   Updated: 2022/04/15 16:21:27 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;
	char	*j;

	i = 0;
	j = ft_itoa(n);
	i = ft_putstr(j);
	free(j);
	return (i);
}

int	ft_formats(va_list args, char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), 16, 55);
	else if (format == 'x')
		print_len += ft_print_hex(va_arg(args, unsigned int), 16, 87);
	else if (format == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		n;
	va_list	ap;//argument pointer
	i = 0;
	n = 0;
	if (!s)
		return (0);
	va_start(ap, s);//read ap after s
	while (s[i])
	{
		if (s[i] == '%')
		{
			n += ft_formats(ap, s[i + 1]);//checking char after %
			i++;
		}
		else
			n += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (n);
}
