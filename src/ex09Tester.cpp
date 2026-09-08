/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/08 18:36:33 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	print_vector(std::vector<int> vec) {
	PRINT RED "[" BASE_COLOR;
	for (size_t i = 0; i < vec.size(); ++i) {
			PRINT MAGENTA AND vec[i] AND BASE_COLOR;
			if (i + 1 < vec.size())
				PRINT RED "," BASE_COLOR;
		}
	PRINT RED "]" BASE_COLOR;
	NLINE;
}

void	evalSetTester() {
	NLINE;
	PRINT RED "EVALUATION SET TESTER" CENDL;
	NLINE;

	std::vector<std::vector<int>> sets1 = {
		{0, 1, 2},
		{0, 3, 4},
	};
	std::vector<int> res1 = eval_set("AB&", sets1);
	print_vector(res1);

	std::vector<std::vector<int>> sets2 = {
		{0, 1, 2},
		{3, 4, 5},
	};
	std::vector<int> res2 = eval_set("AB|", sets2);
	print_vector(res2);

	std::vector<std::vector<int>> sets3 = {
		{0, 1, 2},
	};
	std::vector<int> res3 = eval_set("A!", sets3);
	print_vector(res3);

}
