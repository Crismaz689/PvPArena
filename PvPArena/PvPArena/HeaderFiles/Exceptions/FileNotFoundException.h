#pragma once

#include <cstring>
#include <exception>
#include <string>

/// <summary>
/// exception class, used when file is not found
/// </summary>
class FileNotFoundException : public std::exception {
private:
    std::string message = "File not found: ";

public:
    /// <summary>
    /// constructor
    /// </summary>
    /// <param name="fileName">filename which was not found</param>
    FileNotFoundException(char* const fileName);

    /// <summary>
    /// destructor
    /// </summary>
    ~FileNotFoundException() {}

    /// <summary>
    /// gets error message
    /// </summary>
    /// <returns>error message</returns>
    const char* what();
};