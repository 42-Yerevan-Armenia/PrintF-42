/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:38:38 by arakhurs          #+#    #+#             */
/*   Updated: 2022/04/22 19:38:52 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_while(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int n)
{
	int				i;
	int				j;
	unsigned int	num;
	char			*c;

	i = 0;
	j = 0;
	if (n == 0)
		return (write(1, "0", 1));
	num = n;
	i = my_while(n);
	c = (char *)malloc(i + 1);
	if (!c)
		return (0);
	while (num != 0)
	{
		c[i - j - 1] = num % 10 + 48;
		num = num / 10;
		j++;
	}
	c[i] = '\0';
	ft_putstr(c);
	free(c);
	return (i);
}

int	ft_print_pointer(unsigned long long l)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_print_hex(l, 16, 87);
	return (i);
}

int	ft_print_hex(unsigned long long num, unsigned int b, int a)
{
	int	i;

	i = 0;
	if (num > b - 1)
		i += ft_print_hex(num / b, b, a);
	if (num % b < 10)
		i += ft_putchar(num % b + 48);
	else if (num % b >= 10 && a == 87)
		i += ft_putchar(num % b + 87);
	else if (num % b >= 10 && a == 55)
		i += ft_putchar(num % b + 55);
	return (i);
}
