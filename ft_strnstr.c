/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:09:00 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/18 19:32:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define HASH_PRIME 1000000009LL
#define HASH_BASE 31LL

static long long	get_power(size_t length)
{
	long long	power;

	power = 1LL;
	while (--length > 0)
		power = (power * HASH_BASE);
	return (power);
}

static long long	get_hash(const char *s, long long length)
{
	long long	hash;
	long long	power;

	hash = 0LL;
	power = 1LL;
	while (length-- != 0)
	{
		hash = hash + (long long)(unsigned char)s[length] * power;
		power = (power * HASH_BASE);
	}
	return (hash % HASH_PRIME);
}

static long long	get_rolling_hash(long long prev_hash,
	const char old_char, const char new_char, long long power)
{
	prev_hash -= ((long long)(unsigned char)old_char) * power;
	prev_hash %= HASH_PRIME;
	if (prev_hash < 0)
		prev_hash += HASH_PRIME;
	prev_hash *= HASH_BASE;
	prev_hash %= HASH_PRIME;
	prev_hash += (long long)(unsigned char)new_char;
	prev_hash %= HASH_PRIME;
	return (prev_hash);
}

static char	*rabin_karp_compare(const char *needle, size_t needle_size,
	const char*haystack, size_t haystack_size)
{
	long long	needle_hash;
	long long	haystack_hash;
	long long	power;
	size_t		index;

	index = 0;
	power = get_power(needle_size);
	needle_hash = get_hash(needle, needle_size);
	haystack_hash = get_hash(haystack, needle_size);
	if (haystack_hash == needle_hash
		&& !ft_strncmp(needle, haystack, needle_size))
		return ((char *) haystack);
	while (index + needle_size < haystack_size)
	{
		haystack_hash = get_rolling_hash(haystack_hash, haystack[index],
				haystack[index + needle_size], power);
		if (haystack_hash == needle_hash
			&& !ft_strncmp(needle, &haystack[index + 1], needle_size))
			return ((char *) &haystack[index + 1]);
		index++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_length;
	size_t	big_length;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	little_length = ft_strlen(little);
	big_length = ft_strlen(big);
	if (len > big_length)
		len = big_length;
	if (little_length > len)
		return (NULL);
	return (rabin_karp_compare(little, little_length, big, len));
}
