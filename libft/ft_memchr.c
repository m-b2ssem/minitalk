/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:10:13 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/15 16:54:10 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*src;

	uc = c;
	src = s;
	while (n > 0)
	{
		if (*src == uc)
		{
			return ((void *)src);
		}
		src++;
		n--;
	}
	return (0);
}

/*#include <stdio.h>

int main () {
   const char str[] = "Hello Word";
   const char ch = 'W';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after is %s\n", ret);

   return(0);
}*/