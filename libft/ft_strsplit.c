/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:33:35 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/24 16:30:33 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		number_of_words(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			n++;
		s++;
	}
	return (n);
}

static size_t		length_of_word(char const *from, char c)
{
	size_t n;

	n = 0;
	while (*from && *from != c)
	{
		from++;
		n++;
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	array_length;
	char	**array;
	size_t	i;
	size_t	word_length;

	if (!s || !c)
		return (NULL);
	array_length = number_of_words(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (array_length + 1))))
		return (NULL);
	array[array_length] = 0;
	i = 0;
	while (i < array_length)
	{
		while (*s && *s == c)
			s++;
		word_length = length_of_word(s, c);
		array[i] = ft_strsub(s, 0, word_length);
		while (*s && *s != c)
			s++;
		i++;
	}
	return (array);
}
