/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:59:44 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 17:44:18 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*mini_word(const char *str, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_all(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	word_export(const char *str, char c, char **res)
{
	int	i;
	int	len;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (str[len] && str[len] != c)
				len++;
			res[i] = mini_word(str, len);
			if (!res[i])
			{
				ft_free_all(res);
				return (0);
			}
			str += len;
			i++;
		}
		else
			str++;
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	if (!word_export(s, c, res))
		return (NULL);
	return (res);
}

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char	**res;
// 	int		i;

// 	s = "__Macbook__ipad___iphone";
// 	c = "_";
// 	res = ft_split(s, c);
// 	i = 0;
// 	while (res && res[i])
// 	{
// 		printf("%s\n", res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }
