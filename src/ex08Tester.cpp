/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/08 17:32:37 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	print_vector(std::vector<std::vector<int>> vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		PRINT RED "[" BASE_COLOR;
		for (size_t j = 0; j < vec[i].size(); ++j) {
			PRINT MAGENTA AND vec[i][j] AND BASE_COLOR;
			if (j + 1 < vec[i].size())
				PRINT RED "," BASE_COLOR;
		}
		PRINT RED "]" BASE_COLOR;
		NLINE;
	}
}

void	powersetTester() {
	NLINE;
	PRINT RED "POWERSET TESTER" CENDL;
	NLINE;

	std::vector<int>	tester1 = {1,2,3};
	std::vector<int>	tester2 = {1,2,3,4};

	PRINT CYAN "Vector: 1, 2, 3    : " CENDL;
	print_vector(powerset(tester1));
	PRINT CYAN "Vector: 1, 2, 3, 4 : " CENDL;
	print_vector(powerset(tester2));
}
