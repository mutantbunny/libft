/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:09:31 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/05 01:14:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_isalnum, a_is_alnum)
{
	int result = ft_isalnum('a');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'a', but got zero.");
}

Test(ft_isalnum, z_is_alnum)
{
	int result = ft_isalnum('z');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'z', but got zero.");
}

Test(ft_isalnum, A_is_alnum)
{
	int result = ft_isalnum('A');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'A', but got zero.");
}

Test(ft_isalnum, Z_is_alnum)
{
	int result = ft_isalnum('Z');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'Z', but got zero.");
}

Test(ft_isalnum, zero_is_alnum)
{
	int result = ft_isalnum('0');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'A', but got zero.");
}

Test(ft_isalnum, nine_is_alnum)
{
	int result = ft_isalnum('9');
	cr_assert(ne(int, result, 0), "Expected nonzero result for 'Z', but got zero.");
}

Test(ft_isalnum, space_is_not_alnum)
{
	int result = ft_isalnum(' ');
	cr_assert(eq(int, result, 0), "Expected zero result for ' ', but got nonzero.");
}

Test(ft_isalnum, EOF_is_not_alnum)
{
	int result = ft_isalnum(-1);
	cr_assert(eq(int, result, 0), "Expected zero result for EOF, but got nonzero.");
}
