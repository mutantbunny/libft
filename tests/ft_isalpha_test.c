/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:06:51 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/04 18:54:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

#include <criterion/parameterized.h>
#include <criterion/new/assert.h>
// #include <ctype.h>


/* Multiple parameters must be coalesced in a single parameter */

struct	parameter_tuple {
	int argument;
	int expected;
};

ParameterizedTestParameters(ft_isalpha, parameterized)
{
	static struct parameter_tuple params[] = {
		{'a', 1},		// first valid lowercase letter
		{'z', 1},		// last valid lowercase letter
		{'A', 1},		// first valid uppercase letter
		{'Z', 1},		// last valid uppercase letter
		{'a' - 1, 0},	// char just before first valid lowercase letter
		{'z' + 1, 0},	// char just after last valid lowercase letter
		{'A' - 1, 0},	// char just before first valid uppercase letter
		{'Z' + 1, 0},	// char just after last valid uppercase letter
		{0, 0},			// zero
		{-1, 0}			// EOF
	};

	return cr_make_param_array(struct parameter_tuple, params, 
		sizeof (params) / sizeof (struct parameter_tuple));
}

ParameterizedTest(struct parameter_tuple *tup, ft_isalpha, parameterized)
{
	int result = ft_isalpha(tup->argument);
	// int standard = isdigit(tup->argument);
	if (tup->expected)
	{
		cr_assert(zero(int, !result), 
		"Expected nonzero result for %d, got %d.",
			tup->argument, result);
	}
	else
	{
		cr_assert(zero(int, result), 
		"Expected zero result for %d, got %d.",
			tup->argument, result);
		
	}
	// cr_expect(eq(int, result, standard), 
	// "ft_isdigit() result %d for %d is correct, but different from isdigit() result %d.", 
	// 	result, tup->argument, standard);
}