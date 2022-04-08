/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:09:57 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/08 19:43:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (NULL);
	if (len_s - start < len)
		len = len_s - start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	sub_str[len] = '\0';
	while (len-- > 0)
		sub_str[len] = s[start + len];
	return sub_str;
}
