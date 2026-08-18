/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:06:06 by tchartie          #+#    #+#             */
/*   Updated: 2026/08/18 18:08:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boollib.hpp"
#include "tester.hpp"

int	main(void) {
	try {
		adderTester(1, 2);
	} catch (const std::exception &e) {
		ERROR RED AND e.what() CENDL;
	}
	return (0);
}
