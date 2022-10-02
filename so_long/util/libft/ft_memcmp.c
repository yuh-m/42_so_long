/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:40:58 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/02 19:08:29 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	if (n == 0)
		return (0);
	while (cnt < n)
	{
		if (((unsigned char *)s1)[cnt] == ((unsigned char *)s2)[cnt])
			cnt++;
		else
			return (((unsigned char *) s1)[cnt] - ((unsigned char *) s2)[cnt]);
	}
	return (0);
}
