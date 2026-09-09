/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:58:13 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 13:58:26 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

// Time complexity:  O(n^2)
// Space complexity: O(n^2)
std::vector<std::vector<int>>	powerset(std::vector<int> set) {
	size_t							subset = 1 << set.size();
	std::vector<std::vector<int>>	ret_set;

	for (size_t val = 0; val < subset; ++val) {
		std::vector<int>	list;

		for (size_t i = 0; i < set.size(); ++i) {
			if (val & (1 << i))
				list.push_back(set[i]);
		}
		ret_set.push_back(list);
	}
	return (ret_set);
}
