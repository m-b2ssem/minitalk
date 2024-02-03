/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:12:55 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/17 14:14:36 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	if (nmemb && SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, total);
	return (ptr);
}

/*#include<stdio.h>
#include<stdlib.h>

int main() {

    int* a = (int*) ft_calloc(5, sizeof(int));
	printf("The array is : %d", a);
    return 0;
}*/