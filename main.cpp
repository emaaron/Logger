/*
*	Name: Aaron Vasquez
*	Date: Feburary 6, 2026
*	Project: Logger
*	CPP Version: C++ ISO 2020
*/

// Imported libraries
#include <iostream> // Using: cout, cerr
#include <string> // Using: string, getline()
#include <filesystem> // Using: path()
#include <fstream> // Using: ofstream()
#include <ctime> // Using: time(), localtime(), strftime();

// getDateFileName() -> Used for file naming
std::string getDateFileName()
{
	time_t now = time(NULL);
	struct tm* gmTime = localtime(&now);
	char timeForm[80];
	strftime(timeForm, sizeof(timeForm), "%Y_%B_%A_%w - %I.%M%p", gmTime);
	return std::string(timeForm);
}

// getDate() -> Used for timestamp inside file
std::string getDate()
{
	time_t now = time(NULL);
	struct tm* gmTime = localtime(&now);
	char timeForm[80];
	strftime(timeForm, sizeof(timeForm), "%Y_%B_%A_%w %I:%M%p", gmTime);
	return std::string(timeForm);
}

// createFile() -> Function meant for checking & creating file
void createFile(const std::string& message)
{
	// file variables
	std::string fileName = getDateFileName(), Date = getDate();

	// filePath
	std::filesystem::path filePath(fileName + ".txt");

	// Check for file existance (Note: Sometime in future update for editing file)
	if (std::filesystem::exists(filePath))
	{
		std::cerr << fileName << " already exists!" << std::endl; return;
	}

	// Create the file
	std::ofstream File(filePath);

	// writing inside file
	File << Date << " - \"" << message << '"';

	// Close file after done
	if (File.is_open()) { File.close(); }

	// Return to main (not requried to add return keyword)
	return;
}

// Main function
int main()
{
	// Message variable
	std::string message = "";

	// Grab user message
	std::getline(std::cin, message);

	// Message empty?
	if (message == "") { return 1; }

	// Call createFile()
	createFile(message);

	// End program
	return 0;
}

/*
*	Helpful sources:
*	https://youtu.be/Qoed2uBwF_o
*	https://youtu.be/0cM2F3jTd98
*/