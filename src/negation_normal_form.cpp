/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negation_normal_form.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:56:36 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 14:02:10 by tchartie         ###   ########.fr       */
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

static str	apply_negation(const str& expr) {
	if (expr.empty())
		return ("");
	if (expr.size() == 1 && expr[0] >= 'A' && expr[0] <= 'Z')
		return (expr + "!");
	if (expr.size() == 2 && expr[0] >= 'A' && expr[0] <= 'Z' && expr[1] == '!')
		return (expr.substr(0, 1));
		
	char	op = expr.back();
	if (op == '!')
		return (expr.substr(0, expr.size() - 1));
		
	str		left;
	str		right;
	char	new_op = (op == '&') ? '|' : '&';
	
	split_rpn_binary(expr, left, right);
		
	return (apply_negation(left) + apply_negation(right) + new_op);
}

// Time complexity:  O(n)
// Space complexity: O(n)
str negation_normal_form(const str& formula) {
	if (formula.empty())
		return ("");

	std::vector<str>	stack;

	for (char c : formula) {
		if (c >= 'A' && c <= 'Z')
			stack.push_back(str(1, c));
		else if (c == '!') {
			if (stack.empty())
				throw std::invalid_argument("invalid RPN");
			str	top = stack.back();
			stack.pop_back();
			stack.push_back(apply_negation(top));
		}
		else if (c == '&' || c == '|' || c == '>' || c == '=' || c == '^') {
			if (stack.size() < 2)
				throw std::invalid_argument("invalid RPN");

			str	right = stack.back();
			stack.pop_back();
			str	left  = stack.back();
			stack.pop_back();

			if (c == '&' || c == '|')
				stack.push_back(left + right + c);
			else if (c == '>')
				stack.push_back(apply_negation(left) + right + "|");
			else if (c == '^') {
				str	t1 = left + apply_negation(right) + "&";
				str	t2 = apply_negation(left) + right + "&";

				stack.push_back(t1 + t2 + "|");
			}
			else if (c == '=') {
				str	t1 = left + right + "&";
				str	t2 = apply_negation(left) + apply_negation(right) + "&";
				
				stack.push_back(t1 + t2 + "|");
			}
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("invalid RPN");

	return (stack.back());
}
