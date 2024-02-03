/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:57:13 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/15 17:20:15 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cur;
	unsigned char	*d1;
	unsigned char	*d2;

	if (n == 0)
		return (0);
	cur = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (n--)
	{
		if (d1[cur] != d2[cur])
			return (d1[cur] - d2[cur]);
		cur++;
	}
	return (0);
}

/* 
#include <stdio.h>
#include <string.h>

int main () {
   char *str1[15] = "Hello word";
   char *str2[15] = "hello word";
   int ret;


   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);

	//if Return value < 0 then it indicates str1 is less than str2.
	//if Return value > 0 then it indicates str2 is less than str1.
	//if Return value = 0 then it indicates str1 is equal to str2.
}*/