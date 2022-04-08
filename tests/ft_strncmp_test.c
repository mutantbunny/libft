/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:07:36 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 09:54:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <signal.h>

Test(ft_strncmp, compare_all_different)
{
	char s1[] = "01234";
	char s2[] = "98765";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = strncmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_first_different)
{
	char s1[] = "01234";
	char s2[] = "91234";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = strncmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_last_different)
{
	char s1[] = "01234";
	char s2[] = "01235";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = strncmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_equal)
{
	char s1[] = "01234";
	char s2[] = "01234";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = strncmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_n_equal_length_plus_1)
{
	char s1[] = "01234";
	char s2[] = "01234";
	int n = 5;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = strncmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_n_greater_than_length)
{
	char s1[] = "01234";
	char s2[] = "01234";
	int n = 6;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = strncmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_n_equal_zero)
{
	char s1[] = "01234";
	char s2[] = "01235";
	int n = 0;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = strncmp(s1, s2, i);
		cr_assert(eq(int, ft_result, std_result));
	}
}

// strncmp() crashes on null pointers, ft_strncmp() should crash too

Test(ft_strncmp, compare_s1_null, .signal = SIGSEGV)
{
	char *s1 = NULL;
	char s2[] = "01235";
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = 0;
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_s2_null, .signal = SIGSEGV)
{
	char s1[] = "01234";
	char *s2 = NULL;
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = 0;
		cr_assert(eq(int, ft_result, std_result));
	}
}

Test(ft_strncmp, compare_both_null, .signal = SIGSEGV)
{
	char s1[] = "01234";
	char *s2 = NULL;
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		int ft_result = ft_strncmp(s1, s2, i);
		int std_result = 0;
		cr_assert(eq(int, ft_result, std_result));
	}
}
