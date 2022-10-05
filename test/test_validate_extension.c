/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:23:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/05 02:30:38 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./unity/src/unity.h"
#include "../so_long/inc/so_long.h"

void test_validate_extension(void)
{
	TEST_ASSERT_EQUAL(1, validate_extension("map1.ber"));
	TEST_ASSERT_EQUAL(1, validate_extension(".ber"));
	TEST_ASSERT_EQUAL(0, validate_extension(""));
	TEST_ASSERT_EQUAL(0, validate_extension(".xyaber"));
	TEST_ASSERT_EQUAL(0, validate_extension("ber.xyaber"));
}se
