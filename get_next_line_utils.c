#include "monty.h"

/**
 * ft_strlen - counts the letters in a string
 * @s: the string in hand
 * Return: number of characters
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * ft_strchr - search for a character in a string
 * @s: the string in hand
 * @c: the character to find
 * Return: the address of the first occurence of the char
*/

char	*ft_strchr(const char *s, int c)
{
	char	*i;

	i = (char *) s;
	while (*i)
	{
		if (*i == (char) c)
			return (i);
		i++;
	}
	if (*i == (char) c)
		return (i);
	return (NULL);
}

/**
 * ft_memcpy - copies a string from src to dest
 * @dst: the destination string
 * @src: the source string
 * @n: the number of char to copy
 * Return: returns the dest
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src || dst)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/**
 * ft_strjoin - joins two string together
 * @s1: the first string
 * @s2: the second string
 * Return: a combination of the two strings
*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;

	if (!s1)
		s1 = ft_strdup("");
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = '\0';
	free(s1);
	return (str);
}

/**
 * ft_strdup - creating a copy of a string
 * @s1: the string in hand
 * Return: the copy of the string
*/

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		size;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + 1;
	copy = malloc(sizeof(char) * size);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
