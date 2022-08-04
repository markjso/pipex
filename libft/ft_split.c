/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:48:01 by jmarks            #+#    #+#             */
/*   Updated: 2022/07/05 11:10:37 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *str, char c)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
				str++;
		if (*str)
				count++;
		while (*str != c && *str)
					str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	word_len;
	char	**split;

	split = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	split[i] = NULL;
	return (split);
}
