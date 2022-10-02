/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:28:20 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/02 19:08:29 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot_size;
	void	*result;

	tot_size = nmemb * size;
	if (tot_size)
	{
		if ((tot_size / nmemb) != size)
			return (NULL);
		result = malloc(tot_size);
		if (!result)
			return (NULL);
		ft_bzero(result, tot_size);
	}
	else
		result = malloc(0);
	return (result);
}
