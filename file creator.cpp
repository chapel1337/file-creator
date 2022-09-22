#include <iostream>
#include <string>
#include <fstream>
#include <random>

using std::cout; using std::string; using std::cin;

// written by chapel1337
// made on 9/22/2022
// 
// my largest and most ambitious project yet
// i'm surprised i was able to finish this
// possible features to add in the future: a working newline feature and checking if file exists

std::string read()
{
	// credit to ROMAHKAO
	std::string s{};
	std::getline(std::cin >> std::ws, s);
	return s;
}


bool noteSent{ false };

std::ofstream outputFile{};
string lineInput{};
string fileName{ "undefined" };
string fileExtension{ "undefined" };
string outputName{ "undefined" };


// indentifier error prevention
void menu();
void addLine();


void invalidInput()
{
	cout << "invalid input\n\n";
	menu();
}

void askNewLine()
{
	string response{};

	cout << "do you want to continue to add lines to your file?\n";
	response = read();

	if (response == "yes")
	{
		addLine();
	}
	else if (response == "no")
	{
		fileName, fileExtension, outputName = "undefined";
		menu();
	}
	else
	{
		cout << "input yes or no\n";
		askNewLine();
	}
}

void createFile()
{
	if (fileName == "undefined")
	{
		invalidInput();
	}
	else if (fileExtension == "undefined")
	{
		invalidInput();
	}
	else
	{
		outputName = fileName + '.' + fileExtension;
		outputFile.open(outputName, std::ios_base::app | std::ios_base::out);

		outputFile << lineInput + '\n';
		outputFile.close();
		lineInput = "undefined";

		cout << "done\n\n";
		askNewLine();
	}

	/* failed newline feature, commented to preserve effort (:skull:)

	for (int i{ 0 }; i < lineInput.length(); i++)
	{
		if (lineInput[i] == '\\' && lineInput[i + 1] == 'n')
		{
			outputFile << '\n';
		}
		else
		{
			continue;
		}
	}
	*/
}

void addLine()
{
	cout << "input a line of text: \n";
	lineInput = read();

	outputFile.open(outputName, std::ios_base::app | std::ios_base::out);

	outputFile << lineInput + '\n';
	outputFile.close();
	lineInput = "undefined";

	cout << "done\n\n";
	askNewLine();
}

void menu()
{
	if (noteSent == false)
	{
		cout << "note: this program only supports single line inputs\n\n";
		noteSent = true;
	}

	cout << "name your file: ";
	fileName = read();

	cout << '\n';

	cout << "name your file extension: ";
	fileExtension = read();

	cout << '\n';

	cout << "input a line of text: \n";
	lineInput = read();

	createFile();
}

int main()
{
	cout << "file creator\n";
	cout << "written by chapel1337\n\n";
	menu();
}