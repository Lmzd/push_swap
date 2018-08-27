/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:10:46 by pblouin           #+#    #+#             */
/*   Updated: 2018/04/23 13:58:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_del(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void		ft_fill(char **split, char *s, char c, char lc)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (*s)
	{
		len = 0;
		if (lc == c && *s != c)
		{
			len = ft_strlen_del(s, c);
			j = 0;
			if (!(split[i] = (char *)malloc(sizeof(char) * (len + 1))))
				return ;
			while (*s != c && *s)
				split[i][j++] = *s++;
			split[i++][j] = '\0';
			lc = *s;
		}
		else
			lc = *s++;
	}
	split[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		wc;

	if (!s || !c)
		return (NULL);
	wc = ft_word_count((char *)s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	ft_fill(arr, (char *)s, c, c);
	return (arr);
}
