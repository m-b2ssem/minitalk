/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:48:26 by bmahdi            #+#    #+#             */
/*   Updated: 2024/01/16 13:00:17 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numwords(char const *s, char c)
{
	int	cur;
	int	word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			word_num++;
		cur++;
	}
	return (word_num);
}

//s_c is the start_cur
//e_c is the end_cur
static int	split_words(char **result, char const *s, char c, int word)
{
	int	s_c;
	int	e_c;

	e_c = 0;
	s_c = 0;
	while (s[e_c])
	{
		if ((s[e_c] != c && e_c == 0) || (s[e_c] != c && s[e_c - 1] == c))
			s_c = e_c;
		if (s[e_c] != c && (s[e_c + 1] == c || s[e_c + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (e_c - s_c + 2));
			if (!result[word])
			{
				while (word--)
					free(result[word]);
				return (0);
			}
			ft_strlcpy(result[word], (s + s_c), e_c - s_c + 2);
			word++;
		}
		e_c++;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!result)
		return (0);
	if (!split_words(result, s, c, 0))
		return (0);
	return (result);
}

/*#include <stdio.h>
int main()
{
    char *to_split = "hello word";
    char spilt = ' ';

    char **r = ft_split(to_split,spilt);
    if (r)
    {
        int i = 0;
        while (r[i])
        {
            printf("%s\n", r[i]);
            free(r[i]);
            i++;
        }
        free(r);
    }
    return (0);
}*/
