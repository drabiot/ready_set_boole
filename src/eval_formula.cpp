/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_formula.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:55:33 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 13:55:46 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

// Time complexity:  O(n)
// Space complexity: O(n)
bool	eval_formula(const str &formula) {
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
