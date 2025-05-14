#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

// Exception for excessively high fullness (over 100)
class FullnessTooHighException : public std::runtime_error {
public:
    // Constructor - sets the exception message
    FullnessTooHighException()
        : std::runtime_error("Fullness Level cannot exceed 100! Overfeeding alert.") {}
};

#endif // EXCEPTIONS_HPP

