/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 17:50:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	negationNormalFormTester() {
	NLINE;
	PRINT RED "NEGATION NORMAL FORM TESTER" CENDL;
	NLINE;
	PRINT CYAN "RPN: AB&    = NNF: " MAGENTA AND negation_normal_form("AB&") CENDL;
	PRINT CYAN "RPN: AB&!   = NNF: " MAGENTA AND negation_normal_form("AB&!") CENDL;
	PRINT CYAN "RPN: AB|    = NNF: " MAGENTA AND negation_normal_form("AB|") CENDL;
	PRINT CYAN "RPN: AB|!   = NNF: " MAGENTA AND negation_normal_form("AB|!") CENDL;
	PRINT CYAN "RPN: AB>    = NNF: " MAGENTA AND negation_normal_form("AB>") CENDL;
	PRINT CYAN "RPN: AB>!   = NNF: " MAGENTA AND negation_normal_form("AB>!") CENDL;
	PRINT CYAN "RPN: AB=    = NNF: " MAGENTA AND negation_normal_form("AB=") CENDL;
	PRINT CYAN "RPN: AB|C&! = NNF: " MAGENTA AND negation_normal_form("AB|C&!") CENDL;
}
