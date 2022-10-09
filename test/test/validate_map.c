/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:23:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/10 01:55:48 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long/inc/so_long.h"
#include "../unity/src/unity.h"

void test_validate_map(void)
{
	t_data  data1;
	t_data  data2;
	t_data  data3;
	t_data  data4;
	t_data  data5;
	t_data  data6;
	t_data  data7;
	t_data  data8;
	t_data  data9;
	t_data  data10;
	t_data  data11;
	t_data  data12;
	t_data  data13;
	t_data  data14;
	t_data  data15;
	t_data  data16;
	t_data  data17;

	data1.map = read_map_file("./map/border_other_char1.ber");
	data2.map = read_map_file("./map/border_other_char2.ber");
	data3.map = read_map_file("./map/border_other_char3.ber");
	data4.map = read_map_file("./map/border_other_char.ber");
	data5.map = read_map_file("../so_long/map/map1.ber");
	data6.map = read_map_file("./map/other_char.ber");
	//data7.map = read_map_file("./map/emptymap.ber");
	data8.map = read_map_file("./map/no_collectibles.ber");
	data9.map = read_map_file("./map/no_end.ber");
	data10.map = read_map_file("./map/no_path.ber");
	data11.map = read_map_file("./map/no_rectangle1.ber");
	data12.map = read_map_file("./map/no_rectangle.ber");
	data13.map = read_map_file("./map/no_start.ber");
	data14.map = read_map_file("./map/one_wall1.ber");
	data15.map = read_map_file("./map/one_wall.ber");
	data16.map = read_map_file("./map/two_exit.ber");
	data17.map = read_map_file("./map/two_starting_point.ber");

	init_data(&data1);
	init_data(&data2);
	init_data(&data3);
	init_data(&data4);
	init_data(&data5);
	init_data(&data6);
	//init_data(&data7);
	init_data(&data8);
	init_data(&data9);
	init_data(&data10);
	init_data(&data11);
	init_data(&data12);
	init_data(&data13);
	init_data(&data14);
	init_data(&data15);
	init_data(&data16);
	init_data(&data17);


	TEST_ASSERT_EQUAL(0, validate_map(data1));
	TEST_ASSERT_EQUAL(0, validate_map(data2));
	TEST_ASSERT_EQUAL(0, validate_map(data3));
	TEST_ASSERT_EQUAL(0, validate_map(data4));
	TEST_ASSERT_EQUAL(1, validate_map(data5));
	TEST_ASSERT_EQUAL(0, validate_map(data6));
	//TEST_ASSERT_EQUAL(0, validate_map(data7));
	TEST_ASSERT_EQUAL(0, validate_map(data8));
	TEST_ASSERT_EQUAL(0, validate_map(data9));
	TEST_ASSERT_EQUAL(0, validate_map(data10));
	TEST_ASSERT_EQUAL(0, validate_map(data11));
	TEST_ASSERT_EQUAL(0, validate_map(data12));
	TEST_ASSERT_EQUAL(0, validate_map(data13));
	TEST_ASSERT_EQUAL(0, validate_map(data14));
	TEST_ASSERT_EQUAL(0, validate_map(data15));
	TEST_ASSERT_EQUAL(0, validate_map(data16));
	TEST_ASSERT_EQUAL(0, validate_map(data17));
}
