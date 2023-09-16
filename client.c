/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fozerdem <fozerdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:29:10 by fozerdem          #+#    #+#             */
/*   Updated: 2023/09/15 14:35:14 by fozerdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	ft_sendserver(int pid, char *str)
{
	int		bit;
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		bit = 8;
		c = str[i];
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_sendserver(ft_atoi(argv[1]), argv[2]);
	else
	{
		ft_printf("Missing or too many parameters entered");
		return (1);
	}
	return (0);
}
