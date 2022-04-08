/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:09:29 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/08 19:56:49 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_substr, copy_ends_before_s_end)
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	char expected[] = "cdefghijklmnopqrstuv";
	unsigned int start = 2;
	size_t len = 20;

	char *result = ft_substr(s, start, len);

	cr_expect(ne(ptr, result, NULL));
	cr_expect(eq(chr[21], result, expected));

	free(result);
}

Test(ft_substr, copy_ends_at_s_end)
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	char expected[] = "cdefghijklmnopqrstuvxyz";
	unsigned int start = 2;
	size_t len = 24;

	char *result = ft_substr(s, start, len);

	cr_expect(ne(ptr, result, NULL));
	cr_expect(eq(chr[21], result, expected));

	free(result);
}

Test(ft_substr, copy_ends_after_s_end)
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	char expected[] = "cdefghijklmnopqrstuvxyz";
	unsigned int start = 2;
	size_t len = 30;

	char *result = ft_substr(s, start, len);

	cr_expect(ne(ptr, result, NULL));
	cr_expect(eq(chr[21], result, expected));

	free(result);
}

Test(ft_substr, copy_starts_after_s_end)
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	unsigned int start = 30;
	size_t len = 10;

	char *result = ft_substr(s, start, len);

	cr_expect(eq(ptr, result, NULL));

	free(result);
}

Test(ft_substr, s_is_null)
{
	char *s = NULL;
	unsigned int start = 2;
	size_t len = 10;

	char *result = ft_substr(s, start, len);

	cr_expect(eq(ptr, result, NULL));

	free(result);
}
