/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boollib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:01:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/09 13:59:54 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOLLIB_HPP
# define BOOLLIB_HPP

# include "utils.hpp"

int								adder(int a, int b);
int								multiplier(int a, int b);
int								gray_code(int n);
bool							eval_formula(const str &formula);
void							print_truth_table(const str &formula);
str 							negation_normal_form(const str& formula);
str 							conjonctive_normal_form(const str& formula);
bool							sat(const str &formula);
std::vector<std::vector<int>>	powerset(std::vector<int> set);
std::vector<int>				eval_set(const str &formula, std::vector<std::vector<int>> sets);

double							map(uint16_t x, uint16_t y);
std::pair<uint16_t, uint16_t>	reverse_map(double n);

#endif //BOOLLIB_HPP
