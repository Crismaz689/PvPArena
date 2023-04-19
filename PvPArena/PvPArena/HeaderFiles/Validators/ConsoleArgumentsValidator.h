#pragma once

#include <filesystem>
#include <string>

#include "../Core/Enums/ConsoleArgumentType.h";
#include "../UI/ConsoleUI.h"

/// <summary>
/// responsible for validating console arguments
/// </summary>
class ConsoleArgumentsValidator {
private:
	static inline const int FIRST_FILE_ARGUMENT_POSITION = 2;

	static inline const int SECOND_FILE_ARGUMENT_POSITION = 4;

	static inline const std::string QUESTS_FILE_PARAMETER = "-q";

	static inline const std::string ITEMS_FILE_PARAMETER = "-i";

	static inline const std::string HELP_PARAMETER = "-h";

	static inline const std::string TXT_FILE_EXTENSION = "txt";

	static inline const std::string CSV_FILE_EXTENSION = "csv";

	bool checkIsHelpCalled(int argc, char* const argv[]);

	bool checkAreFilesCalled(int argc, char* const argv[], UI* ui);

	bool checkFiles(int argc, char* const argv[], UI* ui);

	bool checkFilesExtensions(char* const fileNames[], UI* ui);

	bool checkFileExtension(char* const fileName);

	bool checkDoFilesExist(char* const fileNames[], UI* ui);

	bool checkDoesFileExist(char* const fileName);

public:
	/// <summary>
	/// default constructor
	/// </summary>
	ConsoleArgumentsValidator() {}

	/// <summary>
	/// destructor
	/// </summary>
	~ConsoleArgumentsValidator() {}

	/// <summary>
	/// checks given console arguments in terms of being valid
	/// </summary>
	/// <param name="argc">number of arguments</param>
	/// <param name="argv">array of arguments</param>
	/// <param name="ui">user interface</param>
	/// <returns>validation state</returns>
	ConsoleArgumentType checkArguments(int argc, char* const argv[], UI* ui);
};