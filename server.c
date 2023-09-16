/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fozerdem <fozerdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:44:34 by fozerdem          #+#    #+#             */
/*   Updated: 2023/09/16 11:05:33 by fozerdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sigusr_mng(int signal)
{
	static char	c = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		c = c | 1;
	bit++;
	if (bit == 8)
	{
		if (c >= 0 && c <= 127)
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("Server's PID = %d\n", getpid());
	signal(SIGUSR1, ft_sigusr_mng);
	signal(SIGUSR2, ft_sigusr_mng);
	while (1)
		pause();
	return (0);
}
