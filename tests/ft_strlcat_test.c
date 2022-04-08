/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:42:47 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 22:25:31 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <bsd/string.h>
#include <signal.h>

Test(ft_strlcat, size_less_than_src_length)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "0123456789\0""1234567890123456789012345678";
	char std_dst[] = "0123456789\0""1234567890123456789012345678";
	char expected[] = "0123456789\0""1234567890123456789012345678";
	size_t sz = 10;

	size_t ft_should_copy = ft_strlcat(ft_dst, src, sz);
	size_t std_should_copy = strlcat(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 36));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
	cr_assert(eq(chr[40], ft_dst, expected));
	cr_assert(eq(chr[40], std_dst, expected));
}

Test(ft_strlcat, size_greater_than_src_length)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "0123456789\0""1234567890123456789012345678";
	char std_dst[] = "0123456789\0""1234567890123456789012345678";
	char expected[] = "0123456789abcdefghijklmnopqrstuvwxyz\0""78";
	size_t sz = 50;

	size_t ft_should_copy = ft_strlcat(ft_dst, src, sz);
	size_t std_should_copy = strlcat(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 36));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
	cr_assert(eq(chr[40], ft_dst, expected));
	cr_assert(eq(chr[40], std_dst, expected));
}

Test(ft_strlcat, size_zero)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "0123456789\0""1234567890123456789012345678";
	char std_dst[] = "0123456789\0""1234567890123456789012345678";
	char expected[] = "0123456789\0""1234567890123456789012345678";
	size_t sz = 0;

	size_t ft_should_copy = ft_strlcat(ft_dst, src, sz);
	size_t std_should_copy = strlcat(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 26));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
	cr_assert(eq(chr[40], ft_dst, expected));
	cr_assert(eq(chr[40], std_dst, expected));
}

Test(ft_strlcat, null_src, .signal = SIGSEGV)
{
	char *src = NULL;
	char ft_dst[] = "01234567890123456789012345678";
	char std_dst[] = "01234567890123456789012345678";
	size_t sz = 40;

	size_t ft_should_copy = ft_strlcat(ft_dst, src, sz);
	size_t std_should_copy = strlcat(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 36));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
}

Test(ft_strlcat, null_ft_dst, .signal = SIGSEGV)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char *ft_dst = NULL;
	char std_dst[] = "01234567890123456789012345678";
	size_t sz = 40;

	size_t ft_should_copy = ft_strlcat(ft_dst, src, sz);
	size_t std_should_copy = strlcat(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 36));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
}

Test(ft_strlcat, null_std_dst, .signal = SIGSEGV)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char ft_dst[] = "01234567890123456789012345678";
	char *std_dst = NULL;
	size_t sz = 40;

	size_t ft_should_copy = ft_strlcat(ft_dst, src, sz);
	size_t std_should_copy = strlcat(std_dst, src, sz);

	cr_assert(eq(u64, ft_should_copy, 36));
	cr_assert(eq(u64, ft_should_copy, std_should_copy));
}
