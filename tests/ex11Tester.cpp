/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/08 19:45:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	reverseCurveTester() {
	NLINE;
	PRINT RED "REVERSE CURVE TESTER" CENDL;
	NLINE;

	PRINT CYAN "reverse_map(0)                  = " MAGENTA AND reverse_map(0).first AND CYAN "," MAGENTA AND reverse_map(0).second CENDL;
    PRINT CYAN "reverse_map(1)                  = " MAGENTA AND reverse_map(1).first AND CYAN "," MAGENTA AND reverse_map(1).second CENDL;
    PRINT CYAN "reverse_map(0,000000000232831)	= " MAGENTA AND reverse_map(0.000000000232831).first AND CYAN "," MAGENTA AND reverse_map(0.000000000232831).second CENDL;
    PRINT CYAN "reverse_map(0,000000000465661)	= " MAGENTA AND reverse_map(0.000000000465661).first AND CYAN "," MAGENTA AND reverse_map(0.000000000465661).second CENDL;
}
