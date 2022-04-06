/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:21:15 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 01:34:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"


Test(ft_memcpy, no_overlap)
{
	char src[] = "oeg7CyQVnCtebrBU7BphovszFFeYKnZ9H6BHhynDnci3PzNs1ptOatPotwdSEPjy0iKeahzz9rV6V9sTBqw8qGDLvaNgsqbntcVEaJIgdKibyJF9pM06Moq";
	char expected[] = "oeg7CyQVnCtebrBU7BphovszFFeYKnZ9H6BHhynDnci3PzNs1ptOatPotwdSEPjy0iKeahzz9rV6V9sTBqw8qGDLvaNgsqbntcVEaJIgdKibyJF9pM06Moq";
	char dest[] = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";
	char *result = ft_memcpy(dest, src, 120);

	cr_assert(eq(chr[120], dest, expected), "Expected destination to be equal to %s. Got %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memcpy, dest_equal_to_src)
{
	char expected[] = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";
	char dest[] = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";
	char *src = dest;
	char *result = ft_memcpy(dest, src, 20);

	cr_assert(eq(chr[120], dest, expected), "Expected destination to be equal to: %s. Got %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memcpy, null_dest)
{
	char src[] = "oeg7CyQVnCtebrBU7BphovszFFeYKnZ9H6BHhynDnci3PzNs1ptOatPotwdSEPjy0iKeahzz9rV6V9sTBqw8qGDLvaNgsqbntcVEaJIgdKibyJF9pM06Moq";
	char *dest = NULL;
	char *result = ft_memcpy(dest, src, 120);

	cr_assert(eq(ptr, NULL, result), "Expected return value to be NULL. Expected: %p, got %p.", dest, result);
}

Test(ft_memcpy, null_src)
{
	char *src = NULL;
	char expected[] = "oeg7CyQVnCtebrBU7BphovszFFeYKnZ9H6BHhynDnci3PzNs1ptOatPotwdSEPjy0iKeahzz9rV6V9sTBqw8qGDLvaNgsqbntcVEaJIgdKibyJF9pM06Moq";
	char dest[] = "oeg7CyQVnCtebrBU7BphovszFFeYKnZ9H6BHhynDnci3PzNs1ptOatPotwdSEPjy0iKeahzz9rV6V9sTBqw8qGDLvaNgsqbntcVEaJIgdKibyJF9pM06Moq";
	char *result = ft_memcpy(dest, src, 120);

	cr_assert(eq(chr[120], dest, expected), "Expected destination to be unchanged. Original: %s. After memcpy(): %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memcpy, zero_length)
{
	char src[] = "oeg7CyQVnCtebrBU7BphovszFFeYKnZ9H6BHhynDnci3PzNs1ptOatPotwdSEPjy0iKeahzz9rV6V9sTBqw8qGDLvaNgsqbntcVEaJIgdKibyJF9pM06Moq";
	char expected[] = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";
	char dest[] = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";
	char *result = ft_memcpy(dest, src, 0);

	cr_assert(eq(chr[120], dest, expected), "Expected destination to be unchanged. Original: %s. After memcpy(): %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}