/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:09:00 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/14 11:00:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strings_match(const char *big, const char *little, size_t remaining)
{
	while (*little != '\0')
	{
		if (*big == '\0' || *big != *little || remaining == 0)
			return (FALSE);
		big++;
		little++;
		remaining--;
	}
	return (TRUE);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int little_hash;
	unsigned int big_hash;
	size_t little_length;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	little_length = get_needle_hash(&little_hash);
	if (get_initial_hash(big++, &big_hash, little_length))
		return (NULL);
	if (little_hash == big_hash)
		return (big);
	while (get_rolling_hash(big++, &big_hash, little_length))
	{
		if (little_hash == big_hash)
			return (big);
		big++;
	}
	return (NULL);
}
