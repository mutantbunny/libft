/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:07:36 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/07 11:45:44 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <signal.h>

Test(ft_strrchr, char_is_present)
{
	char s1[] = "0123454321";

	for (char c = '0'; c < '5'; c++)
	{
		char *ft_result = ft_strrchr(s1, c);
		char *std_result = strrchr(s1, c);
		cr_assert(eq(ptr, ft_result, std_result), "Looking for %c", c);
	}
}

Test(ft_strrchr, char_is_not_present)
{
	char s1[] = "0123454321";
	char c = '5';

	char *ft_result = ft_strrchr(s1, c);
	char *std_result = strrchr(s1, c);
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strrchr, char_is_negative)
{
	char s1[] = "0123454321";
	int c = -1;

	char *ft_result = ft_strrchr(s1, c);
	char *std_result = strrchr(s1, c);
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strrchr, char_is_not_ascii)
{
	char s1[] = "0123454321";
	int c = 255;

	char *ft_result = ft_strrchr(s1, c);
	char *std_result = strrchr(s1, c);
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strrchr, char_is_too_big)
{
	char s1[] = "0123454321";
	int c = 256;

	char *ft_result = ft_strrchr(s1, c);
	char *std_result = strrchr(s1, c);
	cr_assert(eq(ptr, ft_result, std_result), "Char: %d, ft_result: %p, std_result: %p.", c, ft_result, std_result);
}

Test(ft_strrchr, char_is_zero)
{
	char s1[] = "0123454321";
	int c = 0;

	char *ft_result = ft_strrchr(s1, c);
	char *std_result = strrchr(s1, c);
	cr_assert(eq(ptr, ft_result, std_result), "Char: %d, ft_result: %p, std_result: %p.", c, ft_result, std_result);
}

Test(ft_strrchr, ft_crashes_string_is_null, .signal = SIGSEGV)
{
	char *s1 = NULL;
	char c = '2';

	char *ft_result = ft_strrchr(s1, c);
	char *std_result = NULL;
	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strrchr, std_crashes_string_is_null, .signal = SIGSEGV)
{
	char *s1 = NULL;
	char c = '2';

	char *ft_result = NULL;
	char *std_result = strrchr(s1, c);
	cr_assert(eq(ptr, ft_result, std_result));
}
