/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:36:56 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:36:57 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		*ft_free(char **str, int size)
{
	int	i;

	i = 0;
	while (size > i)
		free(str[i++]);
	free(str);
	return (0);
}

static size_t	ft_countw(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (count);
}

static size_t	ft_lenw(const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str;

	i = 0;
	k = 0;
	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_countw(s, c) + 1))))
		return (NULL);
	while (i < ft_countw(s, c))
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (ft_lenw(&s[k], c) + 1))))
		{
			ft_free(str, k);
			return (NULL);
		}
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			str[i][j++] = s[k++];
		str[i++][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}
