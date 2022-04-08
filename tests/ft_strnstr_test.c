/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:07:36 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 09:54:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <signal.h>
#include <bsd/string.h>

Test(ft_strnstr, all_chars_not_in_haystack)
{
	char haystack[] = "0123456789";
	char needle[] = "abc";
	int n = 10;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, last_char_not_in_haystack)
{
	char haystack[] = "0123456789";
	char needle[] = "013";
	int n = 10;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, needle_in_haystack)
{
	char haystack[] = "0123456789";
	char needle[] = "012";
	int n = 10;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, needle_same_size_as_haystack)
{
	char haystack[] = "0123456789";
	char needle[] = "0123456789";
	int n = 10;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, needle_longer_than_haystack)
{
	char haystack[] = "0123456789";
	char needle[] = "012345678901234567890";
	int n = 10;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, n_longer_than_haystack)
{
	char haystack[] = "0123456789";
	char needle[] = "0123";
	int n = 11;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, n_is_zero)
{
	char haystack[] = "0123456789";
	char needle[] = "0123";
	int n = 0;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, null_haystack, .signal = SIGSEGV)
{
	char *haystack = NULL;
	char needle[] = "012345678901234567890";
	int n = 10;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(ft_strnstr, null_needle, .signal = SIGSEGV)
{
	char haystack[] = "012345678901234567890";
	char *needle = NULL;
	int n = 10;

	char *ft_result = ft_strnstr(haystack, needle, n);
	char *std_result = strnstr(haystack, needle, n);

	cr_assert(eq(ptr, ft_result, std_result));
}

Test(strnstr, simple_needle_in_haystack) {
	char haystack_str[] = "haystack$cash?haystack";
	char *expected = strnstr(haystack_str, "$cash?", ft_strlen(haystack_str));
	char *actual = ft_strnstr(haystack_str, "$cash?", ft_strlen(haystack_str));
	cr_assert(actual == expected);
}

Test(strnstr, simple_needle_in_haystack_size) {
	char haystack_str[] = "haystack$cash?haystack#";
	char *expected = strnstr(haystack_str, "stack#", ft_strlen(haystack_str) - 1);
	char *actual = ft_strnstr(haystack_str, "stack#", ft_strlen(haystack_str) - 1);
	cr_assert(actual == expected);
}

// Marlon

Test(strnstr, entire_needle_is_haystack) {
	char haystack_str[] = "#";
	char haystack_str2[] = "xasfhewuofuihwioeufhowiuehfoiuwheoi8736198765978678561afshdfgh";
	char *expected = strnstr(haystack_str, haystack_str, ft_strlen(haystack_str));
	char *actual = ft_strnstr(haystack_str, haystack_str, ft_strlen(haystack_str));
	cr_assert(actual == expected);
	char *expected2 = strnstr(haystack_str, haystack_str2, ft_strlen(haystack_str2));
	char *actual2 = ft_strnstr(haystack_str, haystack_str2, ft_strlen(haystack_str2));
	cr_assert(actual2 == expected2);
}

Test(strnstr, complex_needle_in_haystack0) {
	char haystack_str[] = "fffffffffffffffasaafff?af?";
	char needle_str[] = "af?";
	char *expected = strnstr(haystack_str, needle_str, ft_strlen(haystack_str));
	char *actual = ft_strnstr(haystack_str, needle_str, ft_strlen(haystack_str));
	cr_assert(actual == expected);
}

Test(strnstr, complex_needle_in_haystack1) {
	char haystack_str[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhaaaaahh?";
	char needle_str[] = "h?";
	char *expected = strnstr(haystack_str, needle_str, ft_strlen(haystack_str));
	char *actual = ft_strnstr(haystack_str, needle_str, ft_strlen(haystack_str));
	cr_assert(actual == expected);
}

Test(strnstr, complex_needle_in_haystack2) {
	char haystack_str[] = "12121213";
	char needle_str[] = "121213";
	char *expected = strnstr(haystack_str, needle_str, ft_strlen(haystack_str));
	char *actual = ft_strnstr(haystack_str, needle_str, ft_strlen(haystack_str));
	cr_assert(actual == expected);
}