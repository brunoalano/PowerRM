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

// 3rd Party Librarys && Default Librarys
#include <iostream>

// Created Librarys
#include "console.h"
#include "remove.h"

int main ( int argc, char *argv[] ) {
	if (argc != 2) {
		noArgsShow();
	}
	
	licenseShow();
	
	PowerRM::RemoveTool foo2;
	foo2.setFile(argv[1]);
	foo2.exclude();
		
	return 0;
}