/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 19:04:13 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	truthTableTester() {
	NLINE;
	PRINT RED "TRUTH TABLE TESTER" CENDL;
	NLINE;
	PRINT MAGENTA "   (A ∧ B) ∨ C" CENDL;
	PRINT YELLOW "       RPN" CENDL;
	print_truth_table("AB&C|");
	PRINT YELLOW "       NNF" CENDL;
	print_truth_table(negation_normal_form("AB&C|"));
	PRINT YELLOW "       CNN" CENDL;
	print_truth_table(conjonctive_normal_form("AB&C|"));
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
