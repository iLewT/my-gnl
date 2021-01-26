#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *src)
{
	while (*src && !(*src == '\n'))
		src++;
	return ((*src == '\n') ? src : NULL);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
		i++;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	src[0] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

void	ft_memmove(void *dest, void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (src < dest)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	else
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
}
