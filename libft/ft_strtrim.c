/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchabala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:04:27 by kchabala          #+#    #+#             */
/*   Updated: 2018/06/25 09:08:34 by kchabala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i++;
	j = ft_strlen(s);
	j--;
	while (j > i && ((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t')))
		j--;
	j++;
	str = ft_strsub(s, i, j - i);
	if (str)
		return (str);
	return (NULL);
}
