#include "tests.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dst = (char *)malloc(sizeof(char) * strlen(s1) + strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (i < strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < strlen(s2))
	{
		dst[i + strlen(s1)] = s2[i];
		i++;
	}
	dst[i + strlen(s1)] = '\0';
	return (dst);
}
