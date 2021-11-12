#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_str;
	char	*src_str;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	dst_str = (char *) dst;
	src_str = (char *) src;
	i = 0;
	if (dst_str > src_str)
	{
		while (len-- > 0)
			dst_str[len] = src_str[len];
		return (dst_str);
	}
	while (i++ < len)
		dst_str[i - 1] = src_str[i - 1];
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char            *dst;
    unsigned int    i;
    unsigned int    len1;
    unsigned int    len2;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    i = 0;
    dst = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!dst)
        return (NULL);
    ft_memmove(dst, (char *)s1, len1);
    ft_memmove(dst + len1, (char *)s2, len2);
    dst[len1 + len2] = '\0';
    return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	char	*str;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	ptr = str;
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			size;

	if (!s)
		return (NULL);
	if (start >= (unsigned)ft_strlen(s))
		return (str = ft_strdup(""));
	if ((unsigned)ft_strlen(s) <= len)
		size = (unsigned)ft_strlen(s) - start;
	else
		size = len;
	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = (char)s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
