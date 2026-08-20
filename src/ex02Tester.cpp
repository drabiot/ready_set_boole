/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:25:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/20 17:32:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	grayCodeTester() {
	NLINE;
	PRINT RED "GRAY CODE TESTER" CENDL;
	NLINE;
	PRINT CYAN "0 :  " MAGENTA AND gray_code(0) CENDL;
	PRINT CYAN "1 :  " MAGENTA AND gray_code(1) CENDL;
	PRINT CYAN "2 :  " MAGENTA AND gray_code(2) CENDL;
	PRINT CYAN "3 :  " MAGENTA AND gray_code(3) CENDL;
	PRINT CYAN "4 :  " MAGENTA AND gray_code(4) CENDL;
	PRINT CYAN "5 :  " MAGENTA AND gray_code(5) CENDL;
	PRINT CYAN "6 :  " MAGENTA AND gray_code(6) CENDL;
	PRINT CYAN "7 :  " MAGENTA AND gray_code(7) CENDL;
	PRINT CYAN "8 : " MAGENTA AND gray_code(8) CENDL;
}
