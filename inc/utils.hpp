/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:07:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 17:52:44 by tchartie         ###   ########.fr       */
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

inline str	apply_negation(const str& expr) {
    if (expr.empty())
		return ("");
    
    if (expr.size() == 1 && expr[0] >= 'A' && expr[0] <= 'Z') {
        return (expr + "!");
    }
    if (expr.size() == 2 && expr[0] >= 'A' && expr[0] <= 'Z' && expr[1] == '!') {
        return (expr.substr(0, 1));
    }
    char	op = expr.back();
    int		depth = 1;
    size_t	split_idx = expr.size() - 1;
    
    for (size_t i = expr.size() - 1; i > 0; --i) {
        size_t	idx = i - 1;
        char	c = expr[idx];

        if (c >= 'A' && c <= 'Z')
            depth--;
		else if (c == '&' || c == '|')
            depth++;
        if (depth == 0) {
            split_idx = idx;
            break;
        }
    }
    str		left = expr.substr(0, split_idx);
    str		right = expr.substr(split_idx, expr.size() - 1 - split_idx);
    char	new_op = (op == '&') ? '|' : '&';

    return (apply_negation(left) + apply_negation(right) + new_op);
}

#endif //UTILS_HPP
