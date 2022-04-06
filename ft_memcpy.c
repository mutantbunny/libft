/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:41:31 by coelho            #+#    #+#             */
/*   Updated: 2022/04/06 02:43:44 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (src == dest || src == NULL || dest == NULL || n == 0)
		return (dest);
	index = n;
	while (index-- != 0)
		((char *)dest)[index] = ((char *)src)[index];
	return (dest);
}
