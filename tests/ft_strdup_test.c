/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:31 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/07 22:07:09 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <bsd/string.h>
#include <signal.h>

Test(ft_strdup, src_is_not_null)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";

	char* ft_copy = ft_strdup(src);
	char* std_copy = strdup(src);

	cr_expect(eq(chr[27], ft_copy, src));
	cr_expect(eq(chr[27], std_copy, src));

	free(ft_copy);
	free(std_copy);
}

// Original strdup() crashes when src is NULL, ft_strdup should crash too
Test(ft_strdup, src_is_null, .signal = SIGSEGV)
{
	char *src = NULL;

	char* ft_copy = ft_strdup(src);

	if (ft_copy != NULL)
		free(ft_copy);
}
