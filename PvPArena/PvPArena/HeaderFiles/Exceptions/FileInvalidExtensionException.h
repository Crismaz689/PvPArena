#pragma once

#include <cstring>
#include <exception>
#include <string>

/// <summary>
/// exception class, used when file extension is invalid
/// </summary>
class FileInvalidExtensionException : public std::exception {
private:
    std::string message = "Invalid extension for file: ";

public:
    /// <summary>
    /// constructor
    /// </summary>
    /// <param name="fileName">filename which has invalid extension</param>
    FileInvalidExtensionException(char* const fileName);

    /// <summary>
    /// destructor
    /// </summary>
    ~FileInvalidExtensionException() {}

    /// <summary>
    /// gets error message
    /// </summary>
    /// <returns>error message</returns>
    const char* what();
};