/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:15:14 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/04/18 21:20:59 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_word_count(char *str, int c)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	count = 1;
	word = 1;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			word = 1;
		else if (word == 1)
		{
			count += 1;
			word = 0;
		}
		i++;
	}
	return (count);
}
