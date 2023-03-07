#pragma once

#include <cstring>
#include <exception>
#include <string>

class FileCouldNotBeOpenedException : public std::exception {
private:
    std::string message = "File could not be opened: ";

public:
    FileCouldNotBeOpenedException(std::string fileName);

    ~FileCouldNotBeOpenedException() {}

    const char* what();
};