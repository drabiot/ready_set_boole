/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/15 13:24:13 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	conjunctiveNormalFormTester() {
	NLINE;
	PRINT RED "CONJUNCTIVE NORMAL FORM TESTER" CENDL;
	NLINE;
	PRINT CYAN "RPN: AB&     = CNF: " MAGENTA AND conjunctive_normal_form("AB&") CENDL;
	PRINT CYAN "RPN: AB&!    = CNF: " MAGENTA AND conjunctive_normal_form("AB&!") CENDL;
	PRINT CYAN "RPN: AB|     = CNF: " MAGENTA AND conjunctive_normal_form("AB|") CENDL;
	PRINT CYAN "RPN: AB|!    = CNF: " MAGENTA AND conjunctive_normal_form("AB|!") CENDL;
	PRINT CYAN "RPN: AB|C&   = CNF: " MAGENTA AND conjunctive_normal_form("AB|C&") CENDL;
	PRINT CYAN "RPN: AB|C|D| = CNF: " MAGENTA AND conjunctive_normal_form("AB|C|D|") CENDL;
	PRINT CYAN "RPN: AB&C&D& = CNF: " MAGENTA AND conjunctive_normal_form("AB&C&D&") CENDL;
	PRINT CYAN "RPN: AB&!C!| = CNF: " MAGENTA AND conjunctive_normal_form("AB&!C!|") CENDL;
	PRINT CYAN "RPN: AB|!C!& = CNF: " MAGENTA AND conjunctive_normal_form("AB|!C!&") CENDL;
}
