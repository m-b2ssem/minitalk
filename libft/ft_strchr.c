/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:11:23 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/14 21:03:00 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char) c == 0)
	{
		return ((char *)s);
	}
	return (NULL);
}

/*
#include <stdio.h>

int main () {
   const char str[] = "Hello word";
   const char ch = 'o';
   char *ret;

   ret = ft_strchr(str, ch);

   printf("String after is \n", ret);
   
   return(0);
}*/