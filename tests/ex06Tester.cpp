/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 18:18:50 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	conjonctiveNormalFormTester() {
	NLINE;
	PRINT RED "CONJONCTIVE NORMAL FORM TESTER" CENDL;
	NLINE;
	PRINT CYAN "RPN: AB&     = CNF: " MAGENTA AND conjonctive_normal_form("AB&") CENDL;
	PRINT CYAN "RPN: AB&!    = CNF: " MAGENTA AND conjonctive_normal_form("AB&!") CENDL;
	PRINT CYAN "RPN: AB|     = CNF: " MAGENTA AND conjonctive_normal_form("AB|") CENDL;
	PRINT CYAN "RPN: AB|!    = CNF: " MAGENTA AND conjonctive_normal_form("AB|!") CENDL;
	PRINT CYAN "RPN: AB|C&   = CNF: " MAGENTA AND conjonctive_normal_form("AB|C&") CENDL;
	PRINT CYAN "RPN: AB|C|D| = CNF: " MAGENTA AND conjonctive_normal_form("AB|C|D|") CENDL;
	PRINT CYAN "RPN: AB&C&D& = CNF: " MAGENTA AND conjonctive_normal_form("AB&C&D&") CENDL;
	PRINT CYAN "RPN: AB&!C!| = CNF: " MAGENTA AND conjonctive_normal_form("AB&!C!|") CENDL;
	PRINT CYAN "RPN: AB|!C!& = CNF: " MAGENTA AND conjonctive_normal_form("AB|!C!&") CENDL;
}
