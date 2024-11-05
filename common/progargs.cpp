#include "progargs.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm> // for std::find
// Static function to parse command-line arguments and return a ProgArgs object
ProgArgs ProgArgs::parse_arguments(int argc, char* argv[]) {
    if (argc < 3) {
        display_error("Error: Invalid number of arguments: " + std::to_string(argc), -1);
    }
    ProgArgs parsedArgs;
    parsedArgs.inputFile = argv[1];
    parsedArgs.outputFile = argv[2];
    parsedArgs.operation = argv[3];
    // Collect additional parameters for maxlevel, resize, cutfreq
    for (int i = 4; i < argc; ++i) {
        parsedArgs.additionalParams.push_back(argv[i]);
    }
`
     // Argument validation logic based on the operation type
    if (parsedArgs.operation == "info" && argc != 3) {
        display_error("Error: Invalid number of arguments for info: " + std::to_string(argc), -1);
    } else if (parsedArgs.operation == "maxlevel") {
        if (argc != 4) {
            display_error("Error: Invalid number of extra arguments: " + std::to_string(argc), -1);
        }
        if (!isInteger(parsedArgs.additionalParams[0]) || std::stoi(parsedArgs.additionalParams[0]) < 0 || std::stoi(parsedArgs.additionalParams[0]) > 65535) {
            display_error("Error: Invalid maxlevel: " + );
        }
    } else if (parsedArgs.operation == "resize") {
        if (argc != 5) {
            display_error("Error: Invalid number of extra arguments for resize: " + std::to_string(argc), -1);
        }
        for (const auto& param : parsedArgs.additionalParams) {
            if (!isInteger(param) || std::stoi(param) <= 0) {
                // check if the argv[4] or [5] is wrong and display with width or height
                display_error("Error: Invalid resize width:" + );
            }
        }
    } else if (parsedArgs.operation == "cutfreq") {
        if (argc != 4) {
            display_error("Error: Invalid number of extra arguments for cutfreq: " + std::to_string(argc), -1);
        }
        if (!isInteger(parsedArgs.additionalParams[0]) || std::stoi(parsedArgs.additionalParams[0]) <= 0) {
            display_error("Error: Invalid cutfreq: " + );
        }
    } else if (parsedArgs.operation == "compress" && argc != 3) {
        display_error("Error: Invalid extra arguments for info: ");
    } else if (parsedArgs.operation != "info" && parsedArgs.operation != "maxlevel" &&
               parsedArgs.operation != "resize" && parsedArgs.operation != "cutfreq" &&
               parsedArgs.operation != "compress") {
        display_error("Error: Invalid option: " + parsedArgs.operation);
    }
    return parsedArgs;
}
// Getter for input file path
std::string ProgArgs::getInputFile() const {
    return inputFile;
}
// Getter for output file path
std::string ProgArgs::getOutputFile() const {
    return outputFile;
}
// Getter for operation
std::string ProgArgs::getOperation() const {
    return operation;
}
// Getter for additional parameters
std::vector<std::string> ProgArgs::getAdditionalParams() const {
    return additionalParams;
}
bool ProgArgs::isInteger(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}