/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:59:39 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 14:03:46 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"
static	uint32_t interleaveZeros(uint32_t x) {
	x = (x | (x << 8)) & 0x00FF00FF;
	x = (x | (x << 4)) & 0x0F0F0F0F;
	x = (x | (x << 2)) & 0x33333333;
	x = (x | (x << 1)) & 0x55555555;
	return (x);
}

// Time complexity:  O(1)
// Space complexity: O(1)
double	map(uint16_t x, uint16_t y) {
	uint32_t	z = (interleaveZeros(static_cast<uint32_t>(y)) << 1) | interleaveZeros(static_cast<uint32_t>(x));

	return (static_cast<double>(z) / MAX_VALUE);
}
