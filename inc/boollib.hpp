/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boollib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:01:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/20 18:58:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOLLIB_HPP
# define BOOLLIB_HPP

# include "utils.hpp"

// Time complexity:  O(1)
// Space complexity: O(1)
inline int	adder(int a, int b) {
	while (b != 0) {
		int carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return (a);
}

// Time complexity:  O(1)
// Space complexity: O(1)
inline int	multiplier(int a, int b) {
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
inline int	gray_code(int n) {
	return (n ^ (n >> 1));
}

// Time complexity:  O(1)
// Space complexity: O(1)
inline bool	eval_formula(const str &formula) {
	std::stack<bool>	stack;
	const str			sign("!&|^>=");

	if (formula.find_first_not_of("01!&|^>=") != formula.npos)
		throw std::invalid_argument("Input invalid");

	for (size_t i = 0; i < formula.length(); ++i) {
		char	c = formula.at(i);

		if (c == '0' || c == '1')
			stack.push(c == '1');

		else if (c == '!') {
			if (stack.empty())
				throw std::invalid_argument("Too few arguments for '!'");
			bool	operand = stack.top();
			stack.pop();
			stack.push(!operand);
		}
		else if (!iswspace(c)) {
			if (stack.size() < 2)
				throw std::invalid_argument("Too few arguments for binary operator");

			float rhs = stack.top();
			stack.pop();
			float lhs = stack.top();
			stack.pop();

			switch (c) {
				case '&': {
					stack.push(lhs && rhs);
					break;
				}
				case '|': {
					stack.push(lhs || rhs);
					break;
				}
				case '^': {
					stack.push(lhs != rhs);
					break;
				}
				case '>': {
					stack.push(!lhs || rhs);
					break;
				}
				case '=': {
					stack.push(lhs == rhs);
					break;
				}
				default: {}
			}
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Invalid operation sequence");

	return (stack.top());
}

#endif //BOOLLIB_HPP
