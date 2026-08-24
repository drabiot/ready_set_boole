/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boollib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:01:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/24 20:53:38 by tchartie         ###   ########.fr       */
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

inline str	negation_normal_form(const str &formula) {
	str		nnf = formula;

	for (int i = (int)nnf.size() - 1; i >= 0; --i) {
		if (nnf.at(i) == '!')
			nnf.erase(nnf.begin() + i);
		else if (nnf.at(i) == '&')
			nnf.replace(i, 1, "|");
		else if (nnf.at(i) == '|')
			nnf.replace(i, 1, "&");
		else if (nnf.at(i) >= 'A' && nnf.at(i) <= 'Z')
			nnf.insert(i + 1, "!");
		else if (nnf.at(i) == '>') {
			str	lhs = str(1, static_cast<char>(nnf.at(i - 2))); 
			str	rhs = str(1, static_cast<char>(nnf.at(i - 1)));

			nnf.replace(i - 2, 3, lhs + "!" + rhs + "|");
			i -= 2;
		}
		else if (nnf.at(i) == '=')
			;
		else if (nnf.at(i) == '^')
			;
		else
			throw std::invalid_argument("Input invalid");
	}

	// AB&! = 4
	// AB&	= 3
	// AB|	= 2
	// AB!|	= 1
	// 

	return (nnf);
}

#endif //BOOLLIB_HPP
