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

/*
	ATENÇÃO:  	A utilização incorreta deste método pode causar
				a perda de arquivos sem possível recuperação. Utilizar
				com cautela.
	
	SOBRE:		Este método foi criado por Guttman e neste código
				pode sofrer algumas modificações para atingir
				sua meta na execução do PowerRM.
*/

#include <iostream>
#include <fstream>

namespace Erase {
	class Guttman {
	public:
	 
		void ler( const char *filename ) {
		   std::ifstream file("reg.txt");
		   char text[80];
		   while ( file.getline(text, sizeof text) )
		   {
			  char value = text;
			  std::cout << "text[] = \"" << text << "\", value = " << value << "\n";
		   }
		}
	};
}

int main() {
	static const char filename[] = "file.txt";
	Erase::Guttman foo;
	foo.ler(filename);
}