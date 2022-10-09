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

#include "../../so_long/inc/so_long.h"
#include "../unity/src/unity.h"

void test_rectangle(void)
{
	t_data	data1;
	t_data	data2;
	t_data	data3;
	t_data	data4;

	data1.map = read_map_file("../so_long/map/map1.ber");
	data2.map = read_map_file("./map/no_rectangle.ber");
	data3.map = read_map_file("./map/no_rectangle1.ber");
	data4.map = read_map_file("./map/one_wall.ber");

	get_map_size(&data1);
	get_map_size(&data2);
	get_map_size(&data3);
	get_map_size(&data4);

	TEST_ASSERT_EQUAL(1, ck_rectangle(data1));
	TEST_ASSERT_EQUAL(0, ck_rectangle(data2));
	TEST_ASSERT_EQUAL(0, ck_rectangle(data3));
	TEST_ASSERT_EQUAL(0, ck_rectangle(data4));
}
