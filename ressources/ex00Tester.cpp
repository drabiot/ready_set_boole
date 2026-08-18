/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:04:39 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/18 18:46:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	adderTester() {
	PRINT RED "ADDER TESTER" CENDL;
	NLINE;
	PRINT CYAN " 16 + 26 = " MAGENTA AND adder(16, 26) CENDL;
	PRINT CYAN " 26 + 16 = " MAGENTA AND adder(26, 16) CENDL;
	PRINT CYAN " 0  + 54 = " MAGENTA AND adder(0, 54) CENDL;
	PRINT CYAN "-54 + 54 = " MAGENTA AND adder(-54, 54) CENDL;
}
