/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:50:09 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 13:50:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

// Time complexity:  O(1)
// Space complexity: O(1)
int	multiplier(int a, int b) {
	int	res = 0;
	while (b > 0) {
		if (b & 1) {
			res = adder(res, a);
		}
		a = a << 1;
		b = b >> 1;
	}
	return (res);
}
