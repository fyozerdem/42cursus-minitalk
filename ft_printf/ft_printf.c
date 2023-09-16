/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fozerdem <fozerdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:33:45 by fozerdem          #+#    #+#             */
/*   Updated: 2023/07/20 12:32:07 by fozerdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	int		result;

	result = 0;
	if (nbr > 15)
	{
		result += ft_putnbr_hex(nbr / 16, base);
		result += ft_putnbr_hex(nbr % 16, base);
	}
	else
		result += ft_putchar(base[nbr]);
	return (result);
}

int	ft_adress(unsigned long long nbr, char *base)
{
	int		result;

	result = 0;
	if (nbr >= 16)
	{
		result += ft_adress(nbr / 16, base);
		result += ft_adress(nbr % 16, base);
	}
	else
		result += ft_putchar(base[nbr]);
	return (result);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int		r;
	int					result;

	result = 0;
	r = nb;
	if (nb >= 10)
	{
		result += ft_putnbr(nb / 10);
		result += ft_putchar((nb % 10) + '0');
	}
	else
		result += ft_putchar(nb + '0');
	return (result);
}

int	check(char *c, va_list ap, int *result, ...)
{
	if (*c == 'c')
		*result += ft_putchar(va_arg(ap, int));
	else if (*c == 's')
		*result += ft_putstr(va_arg(ap, char *));
	else if (*c == '%')
		*result += ft_putchar('%');
	else if (*c == 'd' || *c == 'i')
		*result += ft_putnbr(va_arg(ap, int));
	else if (*c == 'x')
		*result += ft_putnbr_hex(va_arg(ap, unsigned long long),
				"0123456789abcdef");
	else if (*c == 'X')
		*result += ft_putnbr_hex(va_arg(ap, unsigned long long),
				"0123456789ABCDEF");
	else if (*c == 'u')
		*result += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (*c == 'p')
	{
		*result += ft_putstr("0x");
		*result += ft_adress(va_arg(ap, unsigned long long),
				"0123456789abcdef");
	}
	return (*result);
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		i;
	int		result;
	int		num_args;
	char	*p;

	result = 0;
	i = 0;
	p = (char *)c;
	num_args = ft_strlen(p);
	va_start(ap, c);
	while (i < num_args)
	{
		if (p[i] == '%')
		{
			i++;
			result = check(&p[i], ap, &result);
		}
		else
			result += ft_putchar(p[i]);
		i++;
	}
	va_end(ap);
	return (result);
}
