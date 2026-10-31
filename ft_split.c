/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosio <mcosio@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:20:00 by mcosio          #+#    #+#             */
/*   Updated: 2026/10/28 17:34:37 by mcosio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static void	free_array(char **strs, int word_count)
{
	while (word_count > 0)
	{
		word_count--;
		free(strs[word_count]);
	}
	free(strs);
}

static int	allocate_words(char **strs, const char *s, char c, int words)
{
	int		word_idx;
	size_t	word_len;

	word_idx = 0;
	while (word_idx < words)
	{
		while (*s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		strs[word_idx] = ft_substr(s, 0, word_len);
		if (!strs[word_idx])
		{
			free_array(strs, word_idx);
			return (0);
		}
		s += word_len;
		word_idx++;
	}
	strs[word_idx] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result_array;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result_array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result_array)
		return (NULL);
	if (!allocate_words(result_array, s, c, words))
		return (NULL);
	return (result_array);
}
