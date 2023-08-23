#include "monty.h"

/**
 * count_words - counts the words in a string
 * @s: the string in hand
 * @c: the delimiter
 * Return: the number of words
*/

static int	count_words(const char *s, char c)
{
	int		counter;
	size_t	i;
	int		found;

	found = 0;
	counter = 0;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || s[i] == '\0') && found)
		{
			counter++;
			found = 0;
		}
		if (s[i] != c && !found)
			found = 1;
		i++;
	}
	return (counter);
}

/**
 * wordlen - count the number of letters in a word
 * @s: the string in hand
 * @c: the delimiter
 * Return: the size of the word
*/

static int	wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/**
 * split - split the string into words
 * @s: the string in hand
 * @c: the delimiter
 * Return: returns an array of strings
*/

char	**split(const char *s, char c)
{
	int			counter;
	char		**words;

	counter = 0;
	words = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			words[counter] = ft_substr(s, 0, wordlen(s, c));
			counter++;
			while (*s && *s != c)
				s++;
		}
	}
	words[counter] = 0;
	return (words);
}

/**
 * free_array - frees the two d array
 * @words: the 2d array to be freed
 * Rerurn: nothing
*/

void free_array(char **words)
{
	int i = 0;

	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}
