/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:03:25 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/02 19:08:29 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	srclen;
	size_t	destlen;
	size_t	cnt;

	srclen = ft_strlen(src);
	destlen = 0;
	while (dest[destlen] && destlen < n)
		destlen++;
	cnt = 0;
	if (destlen < n)
	{
		while ((cnt + destlen) < (n - 1) && src[cnt])
		{
			dest[cnt + destlen] = src[cnt];
			cnt++;
		}
		dest[cnt + destlen] = '\0';
	}
	return (destlen + srclen);
}
