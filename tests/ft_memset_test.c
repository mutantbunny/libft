/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:21:15 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 05:04:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_memset, source_is_a)
{
	int src = 'a';
	char dest[] = "oeg7CyQVnCc";
	char expected[] = "aaaaaaaaaa";
	char *result = ft_memset(dest, src, 10);

	cr_assert(eq(chr[10], dest, expected), "Expected destination to be equal to %s. Got %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memset, source_is_0)
{
	int src = 0;
	char dest[] = "oeg7CyQVnCc";
	char expected[] = "\0\0\0\0\0\0\0\0\0\0";
	char *result = ft_memset(dest, src, 10);

	cr_assert(eq(chr[10], dest, expected), "Expected destination to be equal to %s. Got %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memset, source_is_255)
{
	int src = 255;
	char dest[] = "oeg7CyQVnC";
	char expected[] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0};
	char *result = ft_memset(dest, src, 10);

	cr_assert(eq(chr[10], dest, expected), "Expected destination to be equal to %s. Got %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memset, source_is_1024)
{
	int src = 1024;
	char dest[] = "oeg7CyQVnCc";
	char expected[] = "oeg7CyQVnCc";
	char *result = ft_memset(dest, src, 10);

	cr_assert(eq(chr[10], dest, expected), "Expected destination to be unchanged. Original: %s. After memset(): %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memset, source_is_minus_1024)
{
	int src = -1024;
	char dest[] = "oeg7CyQVnCc";
	char expected[] = "oeg7CyQVnCc";
	char *result = ft_memset(dest, src, 10);

	cr_assert(eq(chr[10], dest, expected), "Expected destination to be unchanged. Original: %s. After memset(): %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}

Test(ft_memset, null_dest)
{
	int src = 'a';
	char *dest = NULL;
	char *result = ft_memset(dest, src, 10);

	cr_assert(eq(ptr, NULL, result), "Expected return value to be NULL. Expected: %p, got %p.", dest, result);
}

Test(ft_memset, zero_length)
{
	int src = 'a';
	char dest[] = "oeg7CyQVnCc";
	char expected[] = "oeg7CyQVnCc";
	char *result = ft_memset(dest, src, 0);

	cr_assert(eq(chr[10], dest, expected), "Expected destination to be unchanged. Original: %s. After memset(): %s.", expected, dest);
	cr_assert(eq(ptr, dest, result), "Expected return value to point to destination. Expected: %p, got %p.", dest, result);
}
