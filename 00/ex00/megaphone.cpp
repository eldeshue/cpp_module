
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string input("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	if (argc <= 1)
	{
		std::cout << input;
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			input = argv[i];
			for (std::string::iterator itr = input.begin(); itr != input.end(); ++itr)
			{
				*itr = std::toupper(*itr);
			}
			std::cout << input;
		}
	}
	std::cout << std::endl;
	return 0;
}
