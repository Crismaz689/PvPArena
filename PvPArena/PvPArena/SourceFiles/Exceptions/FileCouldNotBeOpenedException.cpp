#include "../../HeaderFiles/Exceptions/FileCouldNotBeOpenedException.h";

FileCouldNotBeOpenedException::FileCouldNotBeOpenedException(std::string fileName) {
	this->message += fileName;
}

const char* FileCouldNotBeOpenedException::what() {
	return this->message.c_str();
}