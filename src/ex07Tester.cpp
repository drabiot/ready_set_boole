/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 19:12:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	satTester() {
	NLINE;
	PRINT RED "SAT TESTER" CENDL;
	NLINE;
	PRINT CYAN "RPN: AB|  : " MAGENTA AND sat("AB|") CENDL;
	PRINT CYAN "RPN: AB&  : " MAGENTA AND sat("AB&") CENDL;
	PRINT CYAN "RPN: AA!& : " MAGENTA AND sat("AA!&") CENDL;
	PRINT CYAN "RPN: AA^  : " MAGENTA AND sat("AA^") CENDL;
}
