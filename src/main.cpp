/*
 *	FOR EACH PROCESS CREATED BY RUNNING A UVM EXECUTABLE, A NEW UVM INSTANCE
 *	SHALL BE CREATED. SO TWO UVM EXECUTABLES CANNOT RUN IN ONE UVM INSTANCE.
 *	TAKE NOTE OF THIS, AS IT WILL BE IMPORTANT WHEN PROGRAMMING UVM.
 */

/*
 *	ALSO TAKE NOTE THAT WHEN UVM EXECUTABLES ARE BEING RUNNED, THEY NEVER
 *	NEED TO BE EDITED, SO WE JUST OPEN THEM IN READ-ONLY MODE.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "./debug.h"
#include "./uef.h"

using namespace std;

int main(int argc, char *argv[])
{
	DEBUG("Checking if `argc` there are no arguments except the program's name which was passed.");
	if(argc == 1)
	{
		/*
		 *	The variable `argv[0]` returns the program's name.
		 */
		ERROR("No arguments are specified...");
		DEBUG("Looks like `argc` was equal to 1, meaning no actual arguments were passed.");
		return 0;
	}
	else if(argc == 2)
	{
		DEBUG("Creating a string variable named `filename`...");
		string filename;
		DEBUG("Creating a string variable named `file_contents...`");
		string file_contents;
		DEBUG("Creating an `ifstream` variable which reads the file using the file name which is passed in the first argument. This file is read as binary.");
    	ifstream fileobj(argv[1], ifstream::binary);
		DEBUG("Checking if the file passed in the first argument was real...");
		if(!fileobj)
		{
			ERROR("File not found!");
			DEBUG("Looks like the file wasn't found! We will stop the program and return the program with error code `2`.");
			return 2;
		}
		else
		{
			DEBUG("File was found, now it is time to read the file.");
			fileobj.seekg (0, fileobj.end);
			DEBUG("Getting the length of the file...");
			int length = fileobj.tellg();
			DEBUG("Got the length of the file, the length is...");
			DEBUG_INT(length);
			fileobj.seekg (0, fileobj.beg);
			DEBUG("Loading the file contents into a char array...");
			DEBUG("Printing the contents of the char array...");
			char *buffer = new char[length];
			DEBUG(buffer);
			cout << buffer[0] << buffer[1];
			DEBUG("Checking if UEF header in the executable file is valid...");
			if(check_uef(buffer) == true)
			{
				INFO("SUCCESS!");
				DEBUG("The UEF header is valid...");
			}
			else
			{
				ERROR("Not a valid UVM executable file!");
				DEBUG("The UEF header is NOT valid...");
			}
		}
	}
	return 0;
}
