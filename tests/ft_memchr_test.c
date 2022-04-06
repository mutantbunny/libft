/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:07:36 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 11:31:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <signal.h>

Test(ft_memchr, char_is_present)
{
	char s1[] = "01234";
	int n = 5;
	for (char c = '0'; c < '5'; c++)
	{
		char *ft_result = ft_memchr(s1, c, n);
		char *std_result = memchr(s1, c, n);
		cr_assert(eq(ptr, ft_result, std_result));
	}
}

Test(ft_memchr, char_is_not_present)
{
	char s1[] = "01234";
	char c = '5';
	int n = 5;

	char *ft_result = ft_memchr(s1, c, n);
	char *std_result = memchr(s1, c, n);
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_memchr, char_is_negative)
{
	char s1[] = "01234";
	int c = -1;
	int n = 5;

	char *ft_result = ft_memchr(s1, c, n);
	char *std_result = memchr(s1, c, n);
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_memchr, char_is_too_big)
{
	char s1[] = "01234";
	int c = 256;
	int n = 5;

	char *ft_result = ft_memchr(s1, c, n);
	char *std_result = memchr(s1, c, n);
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_memchr, ft_crashes_string_is_null, .signal = SIGSEGV)
{
	char *s1 = NULL;
	char c = '2';
	int n = 5;

	char *ft_result = ft_memchr(s1, c, n);
	char *std_result = NULL;
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_memchr, length_is_zero)
{
	char s1[] = "01234";
	char c = '2';
	int n = 0;

	char *ft_result = ft_memchr(s1, c, n);
	char *std_result = memchr(s1, c, n);
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_memchr, std_crashes_string_is_null, .signal = SIGSEGV)
{
	char *s1 = NULL;
	char c = '2';
	int n = 5;

	char *ft_result = NULL;
	char *std_result = memchr(s1, c, n);
	cr_assert(eq(ptr, ft_result, std_result));
}
