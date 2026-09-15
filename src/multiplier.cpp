/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:50:09 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/15 12:59:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

// Time complexity:  O(1)
// Space complexity: O(1)
unsigned int	multiplier(unsigned int a, unsigned int b) {
	unsigned int	res = 0;
	
	for (int i = 0; i < 32; i++) {
		if (b & 1) {
			res = adder(res, a);
		}
		a = a << 1;
		b = b >> 1;
	}
	return (res);
}
