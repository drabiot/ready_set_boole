/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_truth_table.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:56:07 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 13:56:15 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

// Time complexity:  O(n^3)
// Space complexity: O(n)
void	print_truth_table(const str &formula) {
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
