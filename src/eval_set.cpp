/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:58:52 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 14:03:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"

static bool contains(const std::vector<int> &v, int value) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == value) {
            return (true);
        }
    }
    return (false);
}

static std::vector<int> set_and(const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int>	result;
	
	for (size_t i = 0; i < a.size(); i++) {
		if (contains(b, a[i])) {
			result.push_back(a[i]);
		}
	}
	return (result);
}

static std::vector<int> set_or(const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int>	result = a;
	
	for (size_t i = 0; i < b.size(); i++) {
		if (!contains(result, b[i])) {
			result.push_back(b[i]);
		}
	}
	return (result);
}

static std::vector<int> set_not(const std::vector<int> &universe, const std::vector<int> &a) {
	std::vector<int>	result;
	
	for (size_t i = 0; i < universe.size(); i++) {
		if (!contains(a, universe[i])) {
			result.push_back(universe[i]);
		}
	}
	return (result);
}

static std::vector<int> set_xor(const std::vector<int> &a, const std::vector<int> &b) {
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

static std::vector<int> set_implies(const std::vector<int> &universe, const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int> notA = set_not(universe, a);
	return set_or(notA, b);
}

static std::vector<int> set_equiv(const std::vector<int> &universe, const std::vector<int> &a, const std::vector<int> &b) {
	std::vector<int>	aImpliesB = set_implies(universe, a, b);
	std::vector<int>	bImpliesA = set_implies(universe, b, a);
	
	return (set_and(aImpliesB, bImpliesA));
}

// Time complexity:  O(n^2)
// Space complexity: O(n)
std::vector<int>	eval_set(const str &formula, std::vector<std::vector<int>> sets) {
	std::vector<int>				uni;
	std::vector<std::vector<int>>	stack;

	for (size_t i = 0; i < sets.size(); ++i)
		std::sort(sets[i].begin(), sets[i].end());
	for (size_t i = 0; i < sets.size(); ++i) {
		std::vector<int>	tmp;

		std::set_union(uni.begin(), uni.end(), sets[i].begin(), sets[i].end(), std::back_inserter(tmp));
		uni = tmp;
	}
	for (char c : formula) {
		if (c >= 'A' && c <= 'Z') {
			int	index = c - 'A';

			if (index < 0 || (size_t)index >= sets.size())
				throw std::invalid_argument("Set");
			stack.push_back(sets[index]);
		} else if (c == '!') {
			if (stack.empty())
				throw std::invalid_argument("Invalid expression");
			
			std::vector<int>	a = stack.back(); stack.pop_back();

			stack.push_back(set_not(uni, a));
		} else if (c == '&' || c == '|' || c == '^' || c == '>' || c == '=') {
			if (stack.size() < 2)
				throw std::invalid_argument("Invalid operator");
			
			std::vector<int>	b = stack.back();
			stack.pop_back();
			std::vector<int>	a = stack.back();
			stack.pop_back();

			if (c == '&')
				stack.push_back(set_and(a, b));
			else if (c == '|')
				stack.push_back(set_or(a, b));
			else if (c == '^')
				stack.push_back(set_xor(a, b));
			else if (c == '>')
				stack.push_back(set_implies(uni, a, b));
			else
				stack.push_back(set_equiv(uni, a, b));
		} else
			throw std::invalid_argument("Wrong formula");
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Wrong formula");

	return (stack.back());
}
