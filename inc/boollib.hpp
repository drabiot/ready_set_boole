/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boollib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:01:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/20 17:36:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOLLIB_HPP
# define BOOLLIB_HPP

# include "utils.hpp"

// Time complexity:  O(1)
// Space complexity: O(1)
inline int adder(int a, int b) {
	while (b != 0) {
		int carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return (a);
}

// Time complexity:  O(1)
// Space complexity: O(1)
inline int multiplier(int a, int b) {
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

// Time complexity:  O(1)
// Space complexity: O(1)
inline int gray_code(int n) {
	return (n ^ (n >> 1));
}

#endif //BOOLLIB_HPP
