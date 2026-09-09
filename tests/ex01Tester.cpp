/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:04:39 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/19 18:05:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	multiplierTester() {
	NLINE;
	PRINT RED "MULTIPLIER TESTER" CENDL;
	NLINE;
	PRINT CYAN "  0  x 5    =  " MAGENTA AND multiplier(0, 5) CENDL;
	PRINT CYAN "-10  x 5    = " MAGENTA AND multiplier(-10, 5) CENDL;
	PRINT CYAN " 14  x 6    =  " MAGENTA AND multiplier(14, 6) CENDL;
	PRINT CYAN " 100 x 697  =  " MAGENTA AND multiplier(100, 697) CENDL;
	PRINT CYAN "9578 x 1547 =  " MAGENTA AND multiplier(9578, 1547) CENDL;
}
