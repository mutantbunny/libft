/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:29:11 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/14 19:22:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{

	// if (c > 255 || c < 0 || n == 0)
	// 	return ((unsigned char *)s);
	while (n-- != 0)
		((unsigned char *)s)[n] = (unsigned char)c;
	return ((unsigned char *)s);
}
