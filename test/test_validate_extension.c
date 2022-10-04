/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:23:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/04 03:49:41 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "../so_long/inc/so_long.h"

Test(input, validate_extension)
{

	cr_assert(validate_extension("map.ber") == 1)
	cr_assert(validate_extension("map.ber") == 1)
}
