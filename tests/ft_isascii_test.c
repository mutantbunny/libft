/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:09:31 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/05 01:34:20 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_isascii, a_is_ascii)
{
	int result = ft_isascii('a');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'a', but got zero.");
}

Test(ft_isascii, z_is_ascii)
{
	int result = ft_isascii('z');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'z', but got zero.");
}

Test(ft_isascii, A_is_ascii)
{
	int result = ft_isascii('A');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'A', but got zero.");
}

Test(ft_isascii, Z_is_ascii)
{
	int result = ft_isascii('Z');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'Z', but got zero.");
}

Test(ft_isascii, zero_is_ascii)
{
	int result = ft_isascii('0');
	cr_assert(ne(int, result, 0), "Expected nonzero result for '0', but got zero.");
}

Test(ft_isascii, nine_is_ascii)
{
	int result = ft_isascii('9');
	cr_assert(ne(int, result, 0), "Expected nonzero result for '9', but got zero.");
}

Test(ft_isascii, space_is_ascii)
{
	int result = ft_isascii(' ');
	cr_assert(ne(int, result, 0), "Expected nonzero result for ' ', but got zero.");
}

Test(ft_isascii, EOF_is_not_ascii)
{
	int result = ft_isascii(-1);
	cr_assert(eq(int, result, 0), "Expected zero result for EOF, but got nonzero.");
}

Test(ft_isascii, int_128_is_not_ascii)
{
	int result = ft_isascii(128);
	cr_assert(eq(int, result, 0), "Expected zero result for 128, but got nonzero.");
}
