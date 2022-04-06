/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:09:31 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/05 02:05:25 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_tolower, a_should_be_equal)
{
	int result = ft_tolower('a');
	cr_assert(eq(int, result, 'a'), "Expected 'a', got %d.", result);
}

Test(ft_tolower, z_should_be_equal)
{
	int result = ft_tolower('z');
	cr_assert(eq(int, result, 'z'), "Expected 'z', got %d.", result);
}

Test(ft_tolower, zero_should_be_equal)
{
	int result = ft_tolower('0');
	cr_assert(eq(int, result, '0'), "Expected '0', got %d.", result);
}

Test(ft_tolower, nine_should_be_equal)
{
	int result = ft_tolower('9');
	cr_assert(eq(int, result, '9'), "Expected '9', got %d.", result);
}
Test(ft_tolower, space_should_be_equal)
{
	int result = ft_tolower(' ');
	cr_assert(eq(int, result, ' '), "Expected ' ', got %d.", result);
}

Test(ft_tolower, A_should_be_lowercase)
{
	int result = ft_tolower('A');
	cr_assert(eq(int, result, 'a'), "Expected 'a', got %d.", result);
}

Test(ft_tolower, Z_should_be_lowercase)
{
	int result = ft_tolower('Z');
	cr_assert(eq(int, result, 'z'), "Expected 'z', got %d.", result);
}

Test(ft_tolower, EOF_should_be_equal)
{
	int result = ft_tolower(-1);
	cr_assert(eq(int, result, -1), "Expected EOF, got %d.", result);
}
