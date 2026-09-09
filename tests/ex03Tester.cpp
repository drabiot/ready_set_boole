/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/20 19:05:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	booleanEvaluationTester() {
	NLINE;
	PRINT RED "BOOLEAN EVALUATION TESTER" CENDL;
	NLINE;
	PRINT CYAN "     10& : " MAGENTA AND eval_formula("10&") CENDL;
	PRINT CYAN "     10| : " MAGENTA AND eval_formula("10|") CENDL;
	PRINT CYAN "     11> : " MAGENTA AND eval_formula("11>") CENDL;
	PRINT CYAN "     10= : " MAGENTA AND eval_formula("10=") CENDL;
	PRINT CYAN " 1011||= : " MAGENTA AND eval_formula("1011||=") CENDL;
	PRINT CYAN "      1! : " MAGENTA AND eval_formula("1!") CENDL;
	PRINT CYAN "1011||=! : " MAGENTA AND eval_formula("1011||=!") CENDL;
}

void	badBooleanEvaluationTester() {
	NLINE;
	PRINT RED "BOOLEAN EVALUATION TESTER" CENDL;
	NLINE;
	PRINT CYAN "10   : " MAGENTA AND eval_formula("10") CENDL;
	PRINT CYAN "10|| : " MAGENTA AND eval_formula("10||") CENDL;
	PRINT CYAN "!    : " MAGENTA AND eval_formula("!") CENDL;
	PRINT CYAN "64+  : " MAGENTA AND eval_formula("64+") CENDL;
	PRINT CYAN ":-D  : " MAGENTA AND eval_formula(":-D") CENDL;
}
