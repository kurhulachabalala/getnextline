/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchabala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:24:29 by kchabala          #+#    #+#             */
/*   Updated: 2018/06/06 09:04:23 by kchabala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_words(char const *s, char d)
{
	size_t	num_words;
	size_t	i;

	i = 0;
	num_words = 0;
	if (s[i] && (s[i] != d) && (s[i + 1] != d) && (s[i + 1] != 0))
		num_words++;
	while (s[i])
	{
		if ((s[i] == d) && (s[i + 1] != d) && (s[i + 1] != 0))
			num_words++;
		i++;
	}
	return (num_words);
}

static int	ft_splitstr(char **arr, const char *s, char d, size_t len)
{
	size_t	count;
	size_t	wordlen;
	size_t	i;

	count = 0;
	i = 0;
	while (count < len)
	{
		wordlen = 0;
		while (s[i] == d && s[i])
			i++;
		while (s[i] != d && s[i])
		{
			wordlen++;
			i++;
		}
		if ((arr[count] = ft_strsub(&s[i - wordlen], 0, wordlen)) == NULL)
			return (0);
		count++;
	}
	arr[count] = 0;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		len;

	if (!s)
		return (NULL);
	len = ft_num_words(s, c);
	if ((arr = ((char **)ft_memalloc(sizeof(char *) * len + 1))) == NULL)
		return (NULL);
	if (ft_splitstr(arr, s, c, len))
		return (arr);
	else
		ft_memdel((void **)arr);
	return (arr);
}
