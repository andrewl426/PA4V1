// ANDREW; I think we should use main only to open and close files, and to create the network--- I think all real logic should be handled inside of networks tick()
//			also, is an output file required? I cant find anything about it in the PA 4 pdf...
//Justin: I don't think an outlook file is required. Since we are already doing cout.. adding fout might be work it.
//testing git

#include "Includes.h"

int main(int argc, char *argv[])
{
	string filename;

	for (int i = 1; i < argc; i++) //argv is much easier to deal with as a string
	{
		filename = argv[i];
	}
	if (filename == "")//if argv is null/empty prompt user for a filename
	{
		cout << "Enter a jobs filename: ";
		cin >> filename;
		cout << endl;
	}

	ifstream input_file{ filename };


	if (input_file.good() == true)
	{



	}



// OKAY, I tried to make a mainline-- but handling the argc/argv[] stuff kept breaking, even with no arguments argc was apparently not 0..
// I was also getting a nullptr crash or something, so I commented out my logic--- something is wrong with it, Im not opposed to starting 
// the mainline over again.
/*
	// Variables
	std::string input_filename = "";
	//std::string output_filename = "results.txt";
	int i = 1;

	// while there is more to process...
	while (i != 0)
	{
		// if no commandline args, Handle the opening of the network file(s) via prompt
		if (argc == 0)
		{
			cout << "Enter the filename or 0 to exit: ";
			cin >> input_filename;

			// if the user entered 0, exit immediately.
			if (input_filename == "0")
			{
				break;
			}
		}
		// else, commandline args are present, Handle the opening of the network file(s) via commandline
		else
		{
			input_filename = argv[i];

			// if there are more arguments...
			if (i < argc)
			{
				i++;
			}
			// else there are no more arguments, set i to 0 to exit
			else
			{
				i = 0;
			}
		}

		// Open file
		std::ifstream input(input_filename);
		//std::ofstream output(output_filename, std::ofstream::out);

		// ***********************************************************************************************
		// Process - create the network object and build the network --- try to use a buildNetwork function 
		//			 or something within the network class --- we get 40pts for quality OOP code, so...



		// ***********************************************************************************************

		// End of while, will loop if (i!=0)
	}
*/
	
	// End of program pause
	cout << endl << endl;
	system( "pause" );
}