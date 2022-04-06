#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t index;

	if (src == dest || src == NULL || dest == NULL || n == 0)
		return (dest);
	if (src > dest)
	{
		index = 0;
		while (index < n)
		{
			((char *)dest)[index] = ((char *)src)[index];
			index++;
		}
	}
	else
	{
		index = n;
		while (index-- > 0)
			((char *)dest)[index] = ((char *)src)[index];
	}
	return (dest);
}
