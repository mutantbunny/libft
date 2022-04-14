/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:09:00 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/13 20:15:13 by gmachado         ###   ########.fr       */
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
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (len-- != 0 && *big != '\0')
	{
		if (*big == *little && strings_match(big, little, len + 1))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
