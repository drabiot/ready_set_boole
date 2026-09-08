/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/09/08 19:16:35 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	curveTester() {
	NLINE;
	PRINT RED "CURVE TESTER" CENDL;
	NLINE;

	PRINT CYAN "map(0, 0)         = " MAGENTA AND map(0, 0) CENDL;
    PRINT CYAN "map(65535, 65535) = " MAGENTA AND map(65535, 65535) CENDL;
    PRINT CYAN "map(1, 0)         = " MAGENTA AND map(1, 0) CENDL;
    PRINT CYAN "map(0, 1)         = " MAGENTA AND map(0, 1) CENDL;
}
