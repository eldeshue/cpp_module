/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:44:51 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/24 15:13:34 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string getReplacedString(const std::string &origin, const std::string &toFind, const std::string &toReplace)
{
	std::string result;
	const int skipSize = toFind.size();

	size_t startPos = 0;
	size_t foundPos = 0;
	while (true)
	{
		foundPos = origin.find(toFind, startPos);
		if (foundPos == std::string::npos)
		{
			// insert rest of origin
			result.append(origin.begin() + startPos, origin.end());
			break;
		}
		result.append(origin.begin() + startPos, origin.begin() + foundPos); // insert before pattern1 occur
		startPos = foundPos;
		result.append(toReplace); // insert pattern2 instead of pattern 1
		startPos += skipSize;	  // skip pattern1
	}
	return result;
}

size_t getFileSize(std::ifstream &ifs)
{
	size_t fileSize = 0;

	ifs.seekg(0, std::ios::end);
	fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	return fileSize;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error : wrong number of argument.\n";
		return 1;
	}
	const std::string inputFileName(argv[1]);
	const std::string patternToFind(argv[2]);
	const std::string patternToReplace(argv[3]);
	const std::string outputFileName = inputFileName + ".replace";

	if (patternToFind == "")
	{
		std::cerr << "Error : invalid pattern to search.\n";
		return 1;
	}

	std::ifstream ifs(inputFileName.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error : cannot open input file.\n";
		return 1;
	}

	const size_t fileSize = getFileSize(ifs);
	std::string originText(fileSize, 'x');
	ifs.read(&originText[0], fileSize);
	if (ifs.bad())
	{
		std::cerr << "Error : reading input file.\n";
		return 1;
	}

	const std::string result = getReplacedString(originText, patternToFind, patternToReplace);

	std::ofstream ofs(outputFileName.c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error : cannot open output file.\n";
		return 1;
	}

	ofs.write(result.c_str(), result.size());
	if (ofs.bad())
	{
		std::cerr << "Error : writing output file.\n";
		return 1;
	}
}
