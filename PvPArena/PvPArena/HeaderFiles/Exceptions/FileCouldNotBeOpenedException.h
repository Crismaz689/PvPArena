#pragma once

#include <cstring>
#include <exception>
#include <string>

/// <summary>
/// exception class, used when file cannot be open
/// </summary>
class FileCouldNotBeOpenedException : public std::exception {
private:
    std::string message = "File could not be opened: ";

public:
    /// <summary>
    /// constructor
    /// </summary>
    /// <param name="fileName">filename which could not be opened</param>
    FileCouldNotBeOpenedException(std::string fileName);

    /// <summary>
    /// destructor
    /// </summary>
    ~FileCouldNotBeOpenedException() {}

    /// <summary>
    /// gets error message
    /// </summary>
    /// <returns>error message</returns>
    const char* what();
};