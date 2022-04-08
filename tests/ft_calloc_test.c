/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:53:49 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/07 21:44:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_calloc, allocate_ten_elements)
{
	size_t size = sizeof(char);
	size_t nelem = 10;
	char valid[] = "\0\0\0\0\0\0\0\0\0";

	char *ft_result = ft_calloc(nelem, size);
	char *std_result = calloc(nelem, size);

	cr_expect(ne(ptr, ft_result, NULL));
	cr_expect(ne(ptr, std_result, NULL));
	cr_expect(eq(chr[10], ft_result, valid));
	cr_expect(eq(chr[10], ft_result, valid));

	free(ft_result);
	free(std_result);
}

Test(ft_calloc, allocate_zero_element)
{
	size_t size = sizeof(char);
	size_t nelem = 0;

	char *ft_result = ft_calloc(nelem, size);
	char *std_result = calloc(nelem, size);

	cr_expect(all(ne(ptr, ft_result, NULL), ne(ptr, std_result, NULL)));

	if (ft_result != NULL)
		free(ft_result);
	if (std_result != NULL)
		free(std_result);
}
