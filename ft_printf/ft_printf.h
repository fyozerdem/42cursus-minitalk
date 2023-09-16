/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fozerdem <fozerdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:39:35 by fozerdem          #+#    #+#             */
/*   Updated: 2023/07/19 15:41:18 by fozerdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	check(char *c, va_list ap, int *result, ...);
int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_strlen(char *c);
int	ft_putnbr(int n);
int	ft_putnbr_hex(unsigned int nbr, char *base);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_printf(const char *c, ...);

#endif
