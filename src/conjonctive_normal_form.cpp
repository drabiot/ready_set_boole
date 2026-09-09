/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conjonctive_normal_form.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:57:02 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 14:02:42 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

static void	split_rpn_binary(const str& expr, str& left, str& right) {
	if (expr.empty())
		return;
		
	int		operands = 0;
	size_t	split_idx = expr.size();
		
	for (size_t i = expr.size() - 1; i > 0; --i) {
		size_t	idx = i - 1;
		char	c = expr[idx];
		
		if (c >= 'A' && c <= 'Z')
			operands++;
		else if (c == '&' || c == '|')
			operands--;
		if (operands == 1) {
			split_idx = idx;
			break;
		}
	}

	left = expr.substr(0, split_idx);
	right = expr.substr(split_idx, expr.size() - 1 - split_idx);
}

static str	distribute_or(const str& left, const str& right) {
	if (!left.empty() && left.back() == '&') {
		str	a1;
		str	a2;

		split_rpn_binary(left, a1, a2);
		return (distribute_or(a1, right) + distribute_or(a2, right) + "&");
	}

	if (!right.empty() && right.back() == '&') {
		str	b1;
		str	b2;
		
		split_rpn_binary(right, b1, b2);
		return (distribute_or(left, b1) + distribute_or(left, b2) + "&");
	}

	return (left + right + "|");
}

// Time complexity:  O(n)
// Space complexity: O(n)
str conjonctive_normal_form(const str& formula) {
	str	nnf = negation_normal_form(formula);
	if (nnf.empty())
		return ("");

	std::vector<str>	stack;

	for (char c : nnf) {
		if (c >= 'A' && c <= 'Z')
			stack.push_back(str(1, c));
		else if (c == '!') {
			if (stack.empty())
				throw std::invalid_argument("invalid RPN");
			stack.back() += "!";
		}
		else if (c == '&' || c == '|') {
			if (stack.size() < 2)
				throw std::invalid_argument("invalid RPN");

			str	right = stack.back(); stack.pop_back();
			str	left  = stack.back(); stack.pop_back();

			if (c == '&')
				stack.push_back(left + right + "&");
			else
				stack.push_back(distribute_or(left, right));
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("invalid RPN");

	return (stack.back());
}
