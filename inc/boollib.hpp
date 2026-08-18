/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boollib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:01:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/18 18:43:24 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOLLIB_HPP
# define BOOLLIB_HPP

# include "utils.hpp"

inline int adder(int a, int b) {
	while (b != 0) {
		int carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return (a);
}

#endif //BOOLLIB_HPP
