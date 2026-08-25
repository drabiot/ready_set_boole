/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:06:06 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/25 18:17:49 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"
#include "tester.hpp"

int	main(void) {
	try {
		adderTester();
		multiplierTester();
		grayCodeTester();
		booleanEvaluationTester();
		//badBooleanEvaluationTester();
		truthTableTester();
		//badTruthTableTester();
		negationNormalFormTester();
		conjonctiveNormalFormTester();
	} catch (const std::exception &e) {
		ERROR RED AND e.what() CENDL;
	}
	return (0);
}
