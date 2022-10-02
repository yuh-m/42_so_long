/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:49:03 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/09/11 19:36:51 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_string(char *chr)
{
	int		bytes;

	bytes = 0;
	if (chr == NULL)
		chr = "(null)";
	while (*chr)
	{
		bytes += ft_print_char(*chr);
		chr++;
	}
	return (bytes);
}
