/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:08:00 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/13 23:01:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define MAX_CHARS 11
#define MAX_DIVIDER 1000000000

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[MAX_CHARS];
	int		position;
	int		divider;

	divider = MAX_DIVIDER;
	position = 0;
	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		buffer[position++] = '-';
		divider = -divider;
	}
	while (divider != 0 && n / divider == 0)
		divider /= 10;
	while (divider != 0)
	{
		buffer[position++] = '0' + (char)(n / divider);
		n %= divider;
		divider /= 10;
	}
	write(fd, buffer, position);
}
