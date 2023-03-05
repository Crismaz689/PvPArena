#include "../../HeaderFiles/Exceptions/FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(char* const fileName) {
	this->message += std::string(fileName);
}

const char* FileNotFoundException::what() {
	return this->message.c_str();
}