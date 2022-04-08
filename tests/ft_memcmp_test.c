/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:07:36 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/07 21:43:56 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <signal.h>

Test(ft_memcmp, compare_all_different)
{
	char s1[] = "01234";
	char s2[] = "98765";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = memcmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_memcmp, compare_first_different)
{
	char s1[] = "01234";
	char s2[] = "91234";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = memcmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_memcmp, compare_last_different)
{
	char s1[] = "01234";
	char s2[] = "01235";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = memcmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_memcmp, compare_equal)
{
	char s1[] = "01234";
	char s2[] = "01234";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = memcmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_memcmp, compare_n_equal_zero)
{
	char s1[] = "01234";
	char s2[] = "01235";
	int n = 0;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = memcmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

// memcmp() crashes on null pointers, ft_memcmp() should crash too

Test(ft_memcmp, compare_s1_null, .signal = SIGSEGV)
{
	char *s1 = NULL;
	char s2[] = "01235";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = 0;
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_memcmp, compare_s2_null, .signal = SIGSEGV)
{
	char s1[] = "01234";
	char *s2 = NULL;
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = 0;
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_memcmp, compare_both_null, .signal = SIGSEGV)
{
	char *s1 = NULL;
	char *s2 = NULL;
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_memcmp(s1, s2, i);
		int std_result = 0;
		cr_assert(eq(int, ft_result, std_result));
	}
}
