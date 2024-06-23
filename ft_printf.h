/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:04:04 by arakhurs          #+#    #+#             */
/*   Updated: 2022/04/21 14:04:47 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_print_unsigned(unsigned int n);
int	ft_print_pointer(unsigned long long l);
int	ft_print_hex(unsigned long long num, unsigned int b, int a);

#endif