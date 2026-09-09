/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:59:56 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 14:00:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

// Time complexity:  O(n)
// Space complexity: O(1)
std::pair<uint16_t, uint16_t>	reverse_map(double n) {
    uint32_t	z = static_cast<uint32_t>(n * MAX_VALUE + 0.5);
    uint16_t	x = 0;
    uint16_t	y = 0;

    for (int i = 0; i < 16; ++i) {
        x |= ((z >> (2 * i)) & 1) << i;
        y |= ((z >> (2 * i + 1)) & 1) << i;
    }

    return {x, y};
}
