#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t index;

	if (src == dest || src == NULL || dest == NULL || n == 0)
		return (dest);
	index = n;
	while (index-- != 0)
		((char *)dest)[index] = ((char *)src)[index];
	return (dest);
}
