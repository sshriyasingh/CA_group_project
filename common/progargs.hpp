#ifndef PROGARGS_HPP
#define PROGARGS_HPP

#include <string>
#include <vector>

class ProgArgs {

private:
    ProgArgs() = default;

    std::string inputFile;
    std::string outputFile;
    std::string operation;
    std::vector<std::string> additionalParams;

    static bool isInteger(const std::string& str);

public:
    static ProgArgs parse_arguments(int argc, char* argv[]);

    std::string getInputFile() const;
    std::string getOutputFile() const;
    std::string getOperation() const;
    std::vector<std::string> getAdditionalParams() const;

    // Static utility function for error display
    static void display_error(const std::string& error_message, int error_code = -1);
};

#endif 
