/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fozerdem <fozerdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:03:36 by fozerdem          #+#    #+#             */
/*   Updated: 2023/09/15 11:50:28 by fozerdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *c)
{
	int		i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_putstr(char *c)
{
	int		res;

	res = 0;
	if (c != NULL)
	{
		write(1, c, ft_strlen(c));
		res = ft_strlen(c);
	}
	else
	{
		write(1, "(null)", 6);
		res = 6;
	}
	return (res);
}

int	ft_putnbr(int n)
{
	int		result;

	result = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n >= 10)
	{
		result += ft_putnbr(n / 10);
		result += ft_putchar((n % 10) + '0');
	}
	else if (n < 0)
	{
		result += ft_putchar('-');
		result += ft_putnbr(-n);
	}
	else
		result += ft_putchar(n + '0');
	return (result);
}
