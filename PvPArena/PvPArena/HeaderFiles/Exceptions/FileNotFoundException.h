#pragma once

#include <cstring>
#include <exception>
#include <string>

class FileNotFoundException : public std::exception {
private:
    std::string message = "File not found: ";

public:
    FileNotFoundException(char* const fileName);
    const char* what();
};