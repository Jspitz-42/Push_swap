/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:22 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/06 10:55:55 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strdup_split(char const *s, char c )
{
	char	*dest;
	int		siz;
	int		i;

	i = 0;
	siz = word_len(s, c);
	dest = ft_calloc(siz + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < siz)
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}

static void	ft_free(char **new)
{
	unsigned int	i;

	i = -1;
	while (new[++i])
		free(new[i]);
	free(new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		word_count;
	int		word;

	if (!s)
		return (NULL);
	word_count = word_counter(s, c);
	new = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!new)
		return (NULL);
	word = 0;
	i = -1;
	while (word < word_count)
	{
		if (s[++i] != c)
		{
			new[word++] = ft_strdup_split(&s[i], c);
			if (!new[word - 1])
				return (ft_free(new), NULL);
			i += word_len(&s[i], c);
		}
	}
	return (new[word] = 0, new);
}
