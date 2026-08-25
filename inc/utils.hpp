/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:07:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 18:43:14 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <cstring>
# include <iomanip>
# include <sstream>
# include <stack>
# include <vector>
# include <algorithm>

# include "color.hpp"	

# define AND	<<
# define PRINT	std::cout AND
# define ERROR	std::cerr AND
# define NLINE	PRINT std::endl
# define ENDL	AND std::endl
# define CENDL	AND BASE_COLOR ENDL
# define TAB	"\t"

typedef std::string str;

# define cref(type) const type &
# define ref(type) type &

inline void	split_rpn_binary(const str& expr, str& left, str& right) {
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

inline str	apply_negation(const str& expr) {
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

inline str	distribute_or(const str& left, const str& right) {
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

#endif //UTILS_HPP
