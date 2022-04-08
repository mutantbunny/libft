/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:31 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 21:17:41 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <bsd/string.h>
#include <signal.h>

Test(ft_strlcpy, size_less_than_src_length)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "01234567890123456789012345678";
	char std_dst[] = "01234567890123456789012345678";
	char expected[] = "abcdefghi\0""0123456789012345678";
	size_t sz = 10;

	size_t ft_should_copy = ft_strlcpy(ft_dst, src, sz);
	size_t std_should_copy = strlcpy(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 26));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
	cr_assert(eq(chr[27], ft_dst, expected));
	cr_assert(eq(chr[27], std_dst, expected));
	cr_assert(eq(u64, 26, std_should_copy));
}

Test(ft_strlcpy, size_greater_than_src_length)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "01234567890123456789012345678";
	char std_dst[] = "01234567890123456789012345678";
	char expected[] = "abcdefghijklmnopqrstuvwxyz\0""78";
	size_t sz = 40;

	size_t ft_should_copy = ft_strlcpy(ft_dst, src, sz);
	size_t std_should_copy = strlcpy(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 26));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
	cr_assert(eq(chr[27], ft_dst, expected));
	cr_assert(eq(chr[27], std_dst, expected));
}

Test(ft_strlcpy, size_zero)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "01234567890123456789012345678";
	char std_dst[] = "01234567890123456789012345678";
	char expected[] = "01234567890123456789012345678";
	size_t sz = 0;

	size_t ft_should_copy = ft_strlcpy(ft_dst, src, sz);
	size_t std_should_copy = strlcpy(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 26));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
	cr_assert(eq(chr[27], ft_dst, expected));
	cr_assert(eq(chr[27], std_dst, expected));
}

Test(ft_strlcpy, null_src, .signal = SIGSEGV)
{
	char *src = NULL;
	char ft_dst[] = "01234567890123456789012345678";
	char std_dst[] = "01234567890123456789012345678";
	size_t sz = 40;

	size_t ft_should_copy = ft_strlcpy(ft_dst, src, sz);
	size_t std_should_copy = strlcpy(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 26));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
}

Test(ft_strlcpy, null_ft_dst, .signal = SIGSEGV)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char *ft_dst = NULL;
	char std_dst[] = "01234567890123456789012345678";
	size_t sz = 40;

	size_t ft_should_copy = ft_strlcpy(ft_dst, src, sz);
	size_t std_should_copy = strlcpy(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 26));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
}

Test(ft_strlcpy, null_std_dst, .signal = SIGSEGV)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "01234567890123456789012345678";
	char *std_dst = NULL;
	size_t sz = 40;

	size_t ft_should_copy = ft_strlcpy(ft_dst, src, sz);
	size_t std_should_copy = strlcpy(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 26));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
}

Test(ft_strlcpy, truncate_test) {
	char src[] = "hello\r\t\f";
	char dst_legacy[] = "123";
	char dst_actual[] = "123";
	size_t res_legacy, res_actual;

	res_legacy = strlcpy(dst_legacy, src, sizeof(dst_legacy));
	res_actual = ft_strlcpy(dst_actual, src, sizeof(dst_actual));
	cr_assert(eq(str, dst_actual, dst_legacy));
	cr_assert(eq(int, res_actual, res_legacy));
	// Here follows the check for truncation
	cr_assert(ge(int, res_legacy, sizeof(dst_legacy)));
	cr_assert(ge(int, res_actual, sizeof(dst_actual)));
}