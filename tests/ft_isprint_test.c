/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:09:31 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/05 01:38:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_isprint, a_is_print)
{
	int result = ft_isprint('a');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'a', but got zero.");
}

Test(ft_isprint, z_is_print)
{
	int result = ft_isprint('z');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'z', but got zero.");
}

Test(ft_isprint, A_is_print)
{
	int result = ft_isprint('A');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'A', but got zero.");
}

Test(ft_isprint, Z_is_print)
{
	int result = ft_isprint('Z');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'Z', but got zero.");
}

Test(ft_isprint, zero_is_print)
{
	int result = ft_isprint('0');
	cr_assert(ne(int, result, 0), "Expected nonzero result for '0', but got zero.");
}

Test(ft_isprint, nine_is_print)
{
	int result = ft_isprint('9');
	cr_assert(ne(int, result, 0), "Expected nonzero result for '9', but got zero.");
}

Test(ft_isprint, space_is_print)
{
	int result = ft_isprint(' ');
	cr_assert(ne(int, result, 0), "Expected nonzero result for ' ', but got zero.");
}

Test(ft_isprint, tilde_is_print)
{
	int result = ft_isprint('~');
	cr_assert(ne(int, result, 0), "Expected nonzero result for '~', but got zero.");
}

Test(ft_isprint, EOF_is_not_print)
{
	int result = ft_isprint(-1);
	cr_assert(eq(int, result, 0), "Expected zero result for EOF, but got nonzero.");
}

Test(ft_isprint, int_127_is_not_print)
{
	int result = ft_isprint(127);
	cr_assert(eq(int, result, 0), "Expected zero result for 127, but got nonzero.");
}


Test(ft_isprint, int_31_is_not_print)
{
	int result = ft_isprint(31);
	cr_assert(eq(int, result, 0), "Expected zero result for 31, but got nonzero.");
}
