/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/20 20:49:53 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	truthTableTester() {
	NLINE;
	PRINT RED "TRUTH TABLE TESTER" CENDL;
	NLINE;
	PRINT MAGENTA "   (A ∧ B) ∨ C" CENDL;
	print_truth_table("AB&C|");
	NLINE;
	PRINT MAGENTA " (A ∧ B) ∨ A" CENDL;
	print_truth_table("AB&A|");
}

void	badTruthTableTester() {
	NLINE;
	PRINT RED "TRUTH TABLE TESTER" CENDL;
	NLINE;
	print_truth_table("10&1|");
}
