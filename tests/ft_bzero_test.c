/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:11:08 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 17:08:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <signal.h>
#include <strings.h>


Test(ft_bzero, length_is_one)
{
	char ft_src[] = "abcdefghijklmnopqrstuvwxyz";
	char std_src[] = "abcdefghijklmnopqrstuvwxyz";
	char expected[] = "\0bcdefghijklmnopqrstuvwxyz";
	size_t n = 1;

	ft_bzero(ft_src, n);
	bzero(std_src,n);
	cr_assert(eq(chr[27], ft_src, expected));
	cr_assert(eq(chr[27], ft_src, std_src));
}

Test(ft_bzero, length_is_zero)
{
	char ft_src[] = "abcdefghijklmnopqrstuvwxyz";
	char std_src[] = "abcdefghijklmnopqrstuvwxyz";
	char expected[] = "abcdefghijklmnopqrstuvwxyz";
	size_t n = 0;

	ft_bzero(ft_src, n);
	bzero(std_src,n);
	cr_assert(eq(chr[27], ft_src, expected));
	cr_assert(eq(chr[27], ft_src, std_src));
}

Test(ft_bzero, length_is_10)
{
	char ft_src[] = "abcdefghijklmnopqrstuvwxyz";
	char std_src[] = "abcdefghijklmnopqrstuvwxyz";
	char expected[] = "\0\0\0\0\0\0\0\0\0\0klmnopqrstuvwxyz";
	size_t n = 10;

	ft_bzero(ft_src, n);
	bzero(std_src,n);
	cr_assert(eq(chr[27], ft_src, expected));
	cr_assert(eq(chr[27], ft_src, std_src));
}

Test(ft_bzero, ft_crash_null_str, .signal = SIGSEGV)
{
	char *src = NULL;
	size_t n = 1;

	ft_bzero(src, n);
	// bzero(src, n);
}

Test(ft_bzero, std_crash_null_str, .signal = SIGSEGV)
{
	char *src = NULL;
	size_t n = 1;

	// ft_bzero(src, n);
	bzero(src, n);
}