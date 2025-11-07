#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    bool inputflag{false};
    bool outputflag{false};
    for (int i{1}; i < cmdLineArgs.size(); i++) {
        if (cmdLineArgs[i] == "--help" || cmdLineArgs[i] == "-h") {
            std::cout << "Usage: mpags-cipher [-h/--help]" << std::endl;
            std::cout << "Enter anything after the executable to have it returned" << std::endl;
        }
        if (cmdLineArgs[i] == "--version" || cmdLineArgs[i] == "-v") {
            std::cout << "mpags-cipher version 1.0" << std::endl;
        }
        if (cmdLineArgs[i] == "-i" && inputflag == false) {
            if (i + 1 == cmdLineArgs.size() || cmdLineArgs[i + 1][0] == '-'){
                std::cerr << "Error: No input file specified" << std::endl;
                return 1;
            }
            std::string input_file = cmdLineArgs[i + 1];
            std::cout << "Input file set to: " << input_file << std::endl;
            std::cout << "Input file handling not yet supported" << std::endl;
            inputflag = true;
        }
        else if (cmdLineArgs[i] == "-i" && inputflag == true){
            std::cerr << "Error: Input file already specified" << std::endl;
            return 1;
        }
        
        if (cmdLineArgs[i] == "-o" && outputflag == false) {
            if (i + 1 == cmdLineArgs.size() || cmdLineArgs[i + 1][0] == '-'){
                std::cerr << "Error: No output file specified" << std::endl;
                return 1;
            }
            std::string output_file = cmdLineArgs[i + 1];
            std::cout << "Output file set to: " << output_file << std::endl;
            std::cout << "Output file handling not yet supported" << std::endl;
            outputflag = true;
        }
        else if (cmdLineArgs[i] == "-o" && outputflag == true){
            std::cerr << "Error: Output file already specified" << std::endl;
            return 1;
        }
    }
    return 0;

        // Initialise variables
        char c{'x'};
        std::string out_text;

        // loop over each character from user input
        while (std::cin >> c) {
            // Uppercase alphabetic characters
            if (std::isalpha(c)) {
                out_text += std::toupper(c);
                continue;
            }

            // Transliterate digits to English words
            switch (c) {
                case '0':
                    out_text += "ZERO";
                    break;
                case '1':
                    out_text += "ONE";
                    break;
                case '2':
                    out_text += "TWO";
                    break;
                case '3':
                    out_text += "THREE";
                    break;
                case '4':
                    out_text += "FOUR";
                    break;
                case '5':
                    out_text += "FIVE";
                    break;
                case '6':
                    out_text += "SIX";
                    break;
                case '7':
                    out_text += "SEVEN";
                    break;
                case '8':
                    out_text += "EIGHT";
                    break;
                case '9':
                    out_text += "NINE";
                    break;
            }

            // If the character isn't alphabetic or numeric, DONT add it
        }

        // Print out the transliterated text
        std::cout << out_text << std::endl;
}

