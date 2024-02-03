/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 07:57:35 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/17 14:14:45 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	int			s;
	int			i;
	long int	r;

	s = 1;
	r = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s *= -1;
	while (ft_isdigit(str[i]))
	{
		if (r > INT_MAX / 10 ||
		(r == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return (s == 1 ? -1 : 0);
		r = (r * 10) + (str[i++] - '0');
	}
	return (r * s);
}

/* #include <stdio.h>
 
int main()
{
    int val;
    char strn1[] = "12546";
 
    val = ft_atoi(strn1);
    printf("String value = %s", strn1);
    printf("Integer value = %d", val);
 
    char strn2[] = "Hello Word";
    val = atoi(strn2);
    printf("String value = %s", strn2);
    printf("Integer value = %d", val);
 
    return (0);
}*/