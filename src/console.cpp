/*
	PowerRM - The openSource Remove Files Tool
	Copyright (C) 2011  Bruno Alano

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http:www.gnu.org/licenses/>
*/

// Include C++ Librarys
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


// License Show Function (licenseShow)
void licenseShow() { 
	#ifdef WIN32
	system("cls");
	#else
	system("clear");
	#endif
	std::cout << "\n\tPowerRM Copyright (C) 2011  Bruno Alano" << std::endl;
    std::cout << "\tThis program comes with ABSOLUTELY NO WARRANTY." << std::endl;
    std::cout << "\tThis is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "\tunder certain conditions." << std::endl;
	
	std::cout << "\n\n\tYou accept the license? [Y/n]\n\t";
	char licenseOption;
	std::cin >> licenseOption;
	
	for ( ;; ) {
		if (licenseOption == 'Y' || licenseOption == 'y') {
			break;
		} else if (licenseOption == 'N' || licenseOption == 'n') {
			exit(1);
		} else {
			std::cout << "Invalid option!" << std::endl;
		}
	}
	
	#ifdef WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void noArgsShow() {
	#ifdef WIN32
	system("cls");
	#else
	system("clear");
	#endif
	
	std::cout << "\n\tInvalid arguments!" << std::endl;
	std::cout << "\tPowerRM <file name with file directory>" << std::endl;
	exit(1);
}