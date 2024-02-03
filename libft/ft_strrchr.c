/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:56:18 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/14 23:15:58 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = 0;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			last_occurrence = (char *)s;
		}
		s++;
	}
	if ((char) c == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last_occurrence);
}

/*
#include <stdio.h>

int main () {
   const char str[] = "Hello word";
   const char ch = 'o';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after is \n", ret);
   
   return(0);
}*/