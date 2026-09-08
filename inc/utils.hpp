/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:07:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/08 18:36:02 by tchartie         ###   ########.fr       */
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

inline bool contains(const std::vector<int> &v, int value) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == value) {
            return (true);
        }
    }
    return (false);
}

inline std::vector<int> set_and(const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int>	result;
	
	for (size_t i = 0; i < a.size(); i++) {
		if (contains(b, a[i])) {
			result.push_back(a[i]);
		}
	}
	return (result);
}

inline std::vector<int> set_or(const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int>	result = a;
	
	for (size_t i = 0; i < b.size(); i++) {
		if (!contains(result, b[i])) {
			result.push_back(b[i]);
		}
	}
	return (result);
}

inline std::vector<int> set_not(const std::vector<int> &universe, const std::vector<int> &a) {
	std::vector<int>	result;
	
	for (size_t i = 0; i < universe.size(); i++) {
		if (!contains(a, universe[i])) {
			result.push_back(universe[i]);
		}
	}
	return (result);
}

inline std::vector<int> set_xor(const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int>	unionAB = set_or(a, b);
	std::vector<int>	interAB = set_and(a, b);
	std::vector<int>	result;
	
	for (size_t i = 0; i < unionAB.size(); i++) {
		if (!contains(interAB, unionAB[i])) {
			result.push_back(unionAB[i]);
		}
	}
	return (result);
}

inline std::vector<int> set_implies(const std::vector<int> &universe, const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int> notA = set_not(universe, a);
	return set_or(notA, b);
}

inline std::vector<int> set_equiv(const std::vector<int> &universe, const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int>	aImpliesB = set_implies(universe, a, b);
	std::vector<int>	bImpliesA = set_implies(universe, b, a);
	
	return (set_and(aImpliesB, bImpliesA));
}

#endif //UTILS_HPP
