/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_solong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 04:27:13 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/04 04:37:07 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_solong.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_validate_extension);
	RUN_TEST(test_rectangle);
	RUN_TEST(test_border);
	RUN_TEST(test_elements);
	return UNITY_END();
}
