/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:50:01 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/07 20:50:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_atoi, str_is_zero_with_spaces)
{
	char *num = "   0";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_is_zero_without_spaces)
{
	char *num = "   0";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_is_minus_one_with_spaces)
{
	char *num = "   -1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_is_plus_one_with_spaces)
{
	char *num = "   +1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}


Test(ft_atoi, str_is_INT_MIN_with_spaces)
{
	char *num = "   -2147483648";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_is_INT_MAX_with_spaces)
{
	char *num = "   2147483647";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_is_plus_INT_MAX_with_spaces)
{
	char *num = "   +2147483647";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_plus_minus)
{
	char *num = "   +-1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_minus_plus)
{
	char *num = "   -+1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_plus_space)
{
	char *num = "   + 1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}
Test(ft_atoi, str_minus_space)
{
	char *num = "   - 1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_plus_a)
{
	char *num = "   +a1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_minus_a)
{
	char *num = "   -a1";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_INT_MIN_letters)
{
	char *num = "   -2147483648aaaa";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}

Test(ft_atoi, str_is_null)
{
	char *num = "   -2147483648aaaa";

	int ft_result = ft_atoi(num);
	int std_result = atoi(num);

	cr_assert(eq(int, ft_result, std_result));
}