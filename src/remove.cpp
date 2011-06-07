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

// 3rd Party Librarys and Default Librarys
#include <iostream>
#include <string>
#include <sys/stat.h> // Verify if File Exists
#include <cstring>

// Dependent Librarys
#include "remove.h"
#include "process.h"

// Windows Librarys
#ifdef WIN32
#include <windows.h>
#endif

bool FileExists(std::string strFilename) { 
  struct stat stFileInfo; 
  bool blnReturn; 
  int intStat; 
  intStat = stat(strFilename.c_str(),&stFileInfo); 
  if(intStat == 0) { 
    blnReturn = true; 
  } else { 
    blnReturn = false; 
  } 
   
  return(blnReturn); 
}

void PowerRM::RemoveTool::setFile(std::string getFile) {
	this->file.append(getFile);
}

void PowerRM::RemoveTool::del( char *t ) {
	DWORD attr = GetFileAttributes( t );
	attr &= ~FILE_ATTRIBUTE_READONLY;
	SetFileAttributes( t, attr );
	DeleteFile( t );
}
		
void PowerRM::RemoveTool::exclude() {
	char * tempString;
	tempString = new char[this->file.length() + 1];
	strcpy(tempString, this->file.c_str());
	
	if (!FileExists(this->file)) {
	  std::cout << "\n\tThe file doesn't exists!" << std::endl;
	} else {
		this->del( tempString );
		
		if (FileExists(this->file)) {
			std::cout << "\n\tThe file can't be deleted in passive mode!" << std::endl;
			std::cout << "\n\n\tThe system will close the case if it is running and removes it." << std::endl;
			std::cout << "\tAllow? [Y/n]: ";
			char accept;
			std::cin >> accept;
			
			// Get File Process Name
			char *p = strrchr( tempString, '\\' );
			char *fname;
			if(p && (strlen(p) < 100)) { 
				p++; 
				strcpy(fname, p); 
			} 
			
			// Close Process
			char szName[100] = "calc.exe";
			int iRes;
			iRes=KILL_PROC_BY_NAME(szName);
			std::cout << "Result Code: " << iRes << std::endl;
			
			// Delete Again
			this->del( tempString );
		  
		} else {
			std::cout << "\n\tSucessfull deleted!" << std::endl;
		}
	}
}