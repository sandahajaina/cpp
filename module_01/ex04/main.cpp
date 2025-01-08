/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:26:03 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/08 11:32:37 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool replaceOccurrences(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: Unable to open the file '" << filename << "'." << std::endl;
        return false;
    }

    std::string newFilename = filename + ".replace";
    std::ofstream outfile(newFilename.c_str());
    if (!outfile) {
        std::cerr << "Error: Unable to create the file '" << newFilename << "'." << std::endl;
        infile.close();
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::string newLine;
        size_t pos = 0;

        while (true) {
            size_t found = line.find(s1, pos);
            if (found == std::string::npos) {
                newLine += line.substr(pos);
                break;
            }

            newLine += line.substr(pos, found - pos);
            newLine += s2;
            pos = found + s1.length();
        }

        outfile << newLine << '\n';
    }

    infile.close();
    outfile.close();

    return true;
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (!replaceOccurrences(filename, s1, s2)) {
        return 1;
    }

    std::cout << "Replacement completed successfully. The new file is '" << filename << ".replace'." << std::endl;
    return 0;
}