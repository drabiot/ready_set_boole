/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:06:06 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/20 17:32:47 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"
#include "tester.hpp"

int	main(void) {
	try {
		adderTester();
		multiplierTester();
		grayCodeTester();
	} catch (const std::exception &e) {
		ERROR RED AND e.what() CENDL;
	}
	return (0);
}
