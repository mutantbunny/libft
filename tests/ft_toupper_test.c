/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:09:31 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/05 02:05:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_toupper, a_should_be_uppercase)
{
	int result = ft_toupper('a');
	cr_assert(eq(int, result, 'A'), "Expected 'A', got %d.", result);
}

Test(ft_toupper, z_should_be_uppercase)
{
	int result = ft_toupper('z');
	cr_assert(eq(int, result, 'Z'), "Expected 'Z', got %d.", result);
}

Test(ft_toupper, zero_should_be_equal)
{
	int result = ft_toupper('0');
	cr_assert(eq(int, result, '0'), "Expected '0', got %d.", result);
}

Test(ft_toupper, nine_should_be_equal)
{
	int result = ft_toupper('9');
	cr_assert(eq(int, result, '9'), "Expected '9', got %d.", result);
}
Test(ft_toupper, space_should_be_equal)
{
	int result = ft_toupper(' ');
	cr_assert(eq(int, result, ' '), "Expected ' ', got %d.", result);
}

Test(ft_toupper, A_should_be_equal)
{
	int result = ft_toupper('A');
	cr_assert(eq(int, result, 'A'), "Expected 'A', got %d.", result);
}

Test(ft_toupper, Z_should_be_equal)
{
	int result = ft_toupper('Z');
	cr_assert(eq(int, result, 'Z'), "Expected 'Z', got %d.", result);
}

Test(ft_toupper, EOF_should_be_equal)
{
	int result = ft_toupper(-1);
	cr_assert(eq(int, result, -1), "Expected EOF, got %d.", result);
}
