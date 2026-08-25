/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boollib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:01:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 18:45:45 by tchartie         ###   ########.fr       */
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

// Time complexity:  O(n)
// Space complexity: O(n)
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

// Time complexity:  O(2^n)
// Space complexity: O(n)
inline void	print_truth_table(const str &formula) {
	if (formula.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXY!&|^>=") != formula.npos)
		throw std::invalid_argument("Input invalid");
	
	std::vector<char> vars;
	for (char c : formula)
		if (c >= 'A' && c <= 'Z') 
			if (std::find(vars.begin(), vars.end(), c) == vars.end())
				vars.push_back(c);

	size_t	num_vars = vars.size();
	size_t	num_rows = 1 << num_vars;

	for (size_t i = 0; i < num_vars; ++i)
		PRINT CYAN "|" MAGENTA " " AND vars[i] AND " " BASE_COLOR;
	PRINT CYAN "|" RED " = " CYAN "|" CENDL;
	for (size_t i = 0; i < num_vars + 1; ++i)
		PRINT CYAN "|---" BASE_COLOR;
	PRINT CYAN "|" CENDL;

	for (size_t row = 0; row < num_rows; ++row) {
		str	binary_formula = formula;

		for (size_t i = 0; i < num_vars; ++i) {
			char	bit_val = ((row >> (num_vars - 1 - i)) & 1) ? '1' : '0';

			PRINT CYAN "| " BLUE AND bit_val AND " " AND BASE_COLOR;
			std::replace(binary_formula.begin(), binary_formula.end(), vars[i], bit_val);
		}
		
		PRINT CYAN "| " MAGENTA AND eval_formula(binary_formula) AND CYAN " |" CENDL;
	}
}

// Time complexity:  O(N)
// Space complexity: O(N)
inline str negation_normal_form(const str& formula) {
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

// Time complexity:  O(2^N)
// Space complexity: O(2^N)
inline str conjonctive_normal_form(const str& formula) {
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

#endif //BOOLLIB_HPP
