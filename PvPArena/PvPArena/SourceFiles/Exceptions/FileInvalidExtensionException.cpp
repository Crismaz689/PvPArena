#include "../../HeaderFiles/Exceptions/FileInvalidExtensionException.h";

FileInvalidExtensionException::FileInvalidExtensionException(char* const fileName) {
	this->message += std::string(fileName);
}

const char* FileInvalidExtensionException::what() {
	return this->message.c_str();
}