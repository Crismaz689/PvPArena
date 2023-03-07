#pragma once

#include <cstring>
#include <exception>
#include <string>

class FileInvalidExtensionException : public std::exception {
private:
    std::string message = "Invalid extension for file: ";

public:
    FileInvalidExtensionException(char* const fileName);

    ~FileInvalidExtensionException() {}

    const char* what();
};