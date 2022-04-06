/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:12:24 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/05 02:22:21 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

Test(ft_strlen, empty_string)
{
	int result = ft_strlen("");
	cr_assert(zero(result), "Length of empty string should be 0, got %d.", result);
}

Test(ft_strlen, len_one_string)
{
	int result = ft_strlen("0");
	cr_assert(eq(result, 1), "Length of empty string should be 1, got %d.", result);
}

Test(ft_strlen, len_10_string)
{
	int result = ft_strlen("0123456789");
	cr_assert(eq(result, 10), "Length of empty string should be 10, got %d.", result);
}
