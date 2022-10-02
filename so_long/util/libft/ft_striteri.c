/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 00:53:22 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/02 19:08:29 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	cnt;

	cnt = 0;
	if (!s || !f)
		return ;
	while (s[cnt])
	{
		f(cnt, s + cnt);
		cnt++;
	}
	return ;
}
