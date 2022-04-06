#include "libft_test.h"

#include <criterion/parameterized.h>
#include <criterion/new/assert.h>
// #include <ctype.h>


/* Multiple parameters must be coalesced in a single parameter */

struct	parameter_tuple {
	int argument;
	int expected;
};

ParameterizedTestParameters(ft_isdigit, parameterized)
{
	static struct parameter_tuple params[] = {
		{'0', 1},		// first valid digit
		{'9', 1},		// last valid digit
		{'0' - 1, 0},	// char just before first valid digit
		{'9' + 1, 0},	// char just after last valid digit
		{0, 0},			// zero
		{-1, 0}			// EOF
	};

	return cr_make_param_array(struct parameter_tuple, params, 
		sizeof (params) / sizeof (struct parameter_tuple));
}

ParameterizedTest(struct parameter_tuple *tup, ft_isdigit, parameterized)
{
	int result = ft_isdigit(tup->argument);
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