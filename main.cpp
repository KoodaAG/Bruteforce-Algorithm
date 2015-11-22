#include <iostream>
#include <string>
#include <array>
#include <Windows.h>

std::array<char, 52> Alphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z' };


bool passwordCracked(const std::string&, const std::string&);
short lastZposition(const std::string&);
void changeFromZToEnd(std::string&, short);
void append(std::string&);
void crack(const std::string&);
void changeEndLetter(std::string&);

int main()
{
	std::string password;
	std::cout << "Enter password to crack:";
	std::cin >> password;

	system("cls");
	std::cout << "Attempt to crack...." << std::endl;
	
	crack(password);

	getchar();
}

void changeEndLetter(std::string& brutepw)
{
	short position;
	for (short i = 0; i < 52; ++i)
	{
		// Get the character whích is at the string end
		if (brutepw.at(brutepw.length() - 1) == Alphabet.at(i) && Alphabet.at(i) != 'z')
		{
			// Increase the letter by one
			position = i +1;
			brutepw.at(brutepw.length() - 1) = Alphabet.at(position);
			break;
		}
	}
}

void crack(const std::string& password)
{
	std::string brutePw = "A";

	while (!passwordCracked(password, brutePw))
	{
		changeEndLetter(brutePw);
		changeFromZToEnd(brutePw, lastZposition(brutePw));
		

		//std::cout << brutePw << std::endl;
	}

	std::cout << "Password Found -> " << brutePw << std::endl;
}

void append(std::string& brutepw)
{
	brutepw.append("A");
}

short lastZposition(const std::string& brutepw)
{
	// Find the position of the last z letter
	// If the letter is at position 0 the string is z...!
	// Else if the letter is greater than 0 the string
	// Doesn't contain only z characters
	short position = -1;
	for (short i = brutepw.length() - 1; i >= 0; --i)
	{
		if (brutepw.at(i) == 'z')
		{
			position = i;
		}
		else
		{
			break;
		}
	}
	return position;
}

void changeFromZToEnd(std::string& brutepw, short zPosition)
{
	if (zPosition == 0)
	{
		// If the last letter is Z add one letter to the string
		// and change all letters in it to A
		
		append(brutepw);

		for (short i = 0; i < brutepw.length(); ++i)
		{
			brutepw.at(zPosition) = 'A';
		}
	}
	else if (zPosition > 0)
	{
		// Get the postition of that character in the Alphabet Array
		short alphabetPos;
		for (short i = 0; i < 52; ++i)
		{
			if (brutepw.at(zPosition - 1) == Alphabet.at(i))
			{
				alphabetPos = ++i;
				break;
			}
		}
		// Increase the letter before z by 1 and asign the letter to it
		brutepw.at(zPosition - 1) = Alphabet.at(alphabetPos);

		// Change all letters after zPosition to A
		for (short i = zPosition; i < brutepw.length(); ++i)
		{
			brutepw.at(zPosition) = Alphabet.at(0);
		}

	}
}



bool passwordCracked(const std::string& password, const std::string& brutepw){ return (password == brutepw); }
