#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


class MyString
{
private:

	string _value;


	//'A' = 65 , a = 97 , 97 - 32 = 65.
//In this equation we are able to convert any lower case letter to upper case letter
//by subtracting 32 from it to get converted successfully.
	static char toUpperCase(char letter)
	{

		if (letter >= 'a' && letter <= 'z')
		{
			letter = letter - 32;

			return letter;
		}

		return letter;
	}


	//'A' = 65 , a = 97 , 65 - 32 = 97.
	//In this equation we are able to convert any upper case letter to lower case letter
	//by adding 32 to it to get converted successfully.
	static char toLowerCase(char letter)
	{
		if (letter >= 'A' && letter <= 'Z')
		{
			letter = letter + 32;

			return letter;
		}

		return letter;
	}

	static bool isUpperCase(char letter)
	{
		return (letter >= 'A' && letter <= 'Z');
	}

	static bool isLowerCase(char letter)
	{
		return (letter >= 'a' && letter <= 'z');
	}

	static bool isNumber(char letter) 
	{
		return (letter >= '1' && letter <= '9');
	}

	static bool isPunctCharacter(char letter) 
	{
		return ((letter >= ' ' && letter <= '/') || (letter >= ':' && letter <= '@')
			|| (letter >= '[' && letter <= '`') || (letter >= '{' && letter <= '~'));
	}

	static bool isVowel(char letter) 
	{
		return (toUpperCase(letter) == 'A' || toUpperCase(letter) == 'E' ||
			toUpperCase(letter) == 'I' || toUpperCase(letter) == 'O' || toUpperCase(letter) == 'U');
	}

	static char invertCharacter(char letter)
	{
		return (isLowerCase(letter)) ? toUpperCase(letter) : toLowerCase(letter);
	}


	//Take Only c string style.
	static int _customLength(const char* str)
	{
		int counter = 0;

		while (*str != '\0')
		{
			counter++;
			str++;
		}

		return counter;
	}

public:

	MyString()
	{
		_value;
	}

	MyString(string value)
	{
		_value = value;
	}


	void setValue(string value)
	{
		_value = value;
	}

	string getValue()
	{
		return _value;
	}

	__declspec(property(get = getValue, put = setValue)) string value;


	static short countWords(string text)
	{
		short pos = 0;
		string word = "";
		string delimiter = " ";

		short wordCounter = 0;

		while ((pos = text.find(delimiter)) != string::npos)
		{
			word = text.substr(0, pos);

			if (word != "")
				wordCounter++;

			text.erase(0, pos + delimiter.length());
		}

		if (text != "")
			wordCounter++;


		return wordCounter;
	}


	short countWords()
	{
		return countWords(_value);
	}



	static string toUpperCase(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = toUpperCase(text[i]);
		}

		return text;
	}

	string toUpperCase()
	{
		return toUpperCase(_value);
	}

	static string toLowerCase(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = toLowerCase(text[i]);
		}

		return text;
	}

	string toLowerCase()
	{
		return toLowerCase(_value);
	}

	static string invertString(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = invertCharacter(text[i]);
		}

		return text;
	}

	string invertString()
	{
		return invertString(_value);
	}

	static string mySubstr(string text, short start, short end)
	{

		string word = "";

		short length = text.length();

		if (start < 0 || start > length)
			return "";

		if (end > length)
			end = length;


		for (int i = start; i < end; i++)
		{
			word += text[i];
		}

		return word;
	}

	string mySubstr(short start, short end)
	{
		return mySubstr(_value, start, end);
	}


	static int customLength(string text)
	{
		const char* str = text.c_str();

		return _customLength(str);
	}

	int customLength()
	{
		const char* str = _value.c_str();

		return _customLength(str);
	}

	static string firstLetterWordUpperCase(string text)
	{
		bool isFirstLetter = true;

		short length = customLength(text);

		for (int i = 0; i < length; i++)
		{
			if (isFirstLetter)
				text[i] = toUpperCase(text[i]);

			isFirstLetter = (text[i] == ' ') ? true : false;
		}

		return text;
	}

	string firstLetterWordUpperCase()
	{
		return firstLetterWordUpperCase(_value);
	}

	static string firstLetterWordLowerCase(string text)
	{
		bool isFirstLetter = true;

		short length = customLength(text);

		for (int i = 0; i < length; i++)
		{
			if (isFirstLetter)
				text[i] = toLowerCase(text[i]);

			isFirstLetter = (text[i] == ' ') ? true : false;
		}

		return text;
	}

	string firstLetterWordLowerCase()
	{
		return firstLetterWordLowerCase(_value);
	}


	static string trimRight(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
				return mySubstr(text, i, text.length());
		}

		return text;
	}

	string trimRight()
	{
		return trimRight(_value);
	}

	static string trimLeft(string text)
	{
		for (int i = text.length() - 1; i >= 0; i--)
		{
			if (text[i] != ' ')
				return mySubstr(text, 0, i + 1);
		}

		return text;
	}

	string trimLeft()
	{
		return trimLeft(_value);
	}

	static string trimAll(string text)
	{
		text = trimRight(text);
		text = trimLeft(text);

		return text;
	}

	string trimAll()
	{
		return trimAll(_value);
	}


	static string eraseStr(string text, short start, short end) 
	{
		string words = "";

		words = mySubstr(text, 0, start) + mySubstr(text, end, text.length());

		return words;
	}

	string eraseStr(short start, short end) 
	{
		return eraseStr(_value, start, end);
	}


	static vector <string> splitString(string text, string delimiter) 
	{
		vector <string> vText;
		string word = "";
		short pos = 0;

		while ((pos = text.find(delimiter)) != string::npos) 
		{
			word = mySubstr(text, 0, pos);

			if (word != "")
				vText.push_back(word);

			text = eraseStr(text, 0, pos + delimiter.length());
		}

		if (text != "")
			vText.push_back(text);

		return vText;
	}


	vector<string> splitString(string delimiter)
	{
		return splitString(_value, delimiter);
	}


	static string joinString(vector<string> &vText, string delimiter) 
	{
		string text = "";

		for (string line : vText) 
		{
			text += line + delimiter;
		}

		return eraseStr(text, text.length() - delimiter.length(), text.length());
	}

	string joinString(string delimiter) 
	{
		vector <string> vText = splitString(delimiter);

		return joinString(vText, delimiter);
	}


	static short countCapitalLetters(string text) 
	{
		short counter = 0;

		for (int i = 0; i < text.length(); i++) 
		{
			if (isUpperCase(text[i]))
				counter++;
		}

		return counter;
	}

	short countCapitalLetters() 
	{
		return countCapitalLetters(_value);
	}


	static short countSmallLetters(string text)
	{
		short counter = 0;

		for (int i = 0; i < text.length(); i++)
		{
			if (isLowerCase(text[i]))
				counter++;
		}

		return counter;
	}

	short countSmallLetters()
	{
		return countSmallLetters(_value);
	}


	static short countNumbers(string text)
	{
		short counter = 0;

		for (int i = 0; i < text.length(); i++)
		{
			if (isNumber(text[i]))
				counter++;
		}

		return counter;
	}

	short countNumbers()
	{
		return countNumbers(_value);
	}

	static short countPunctuationSymbols(string text)
	{
		short counter = 0;

		for (int i = 0; i < text.length(); i++)
		{
			if (isPunctCharacter(text[i]))
				counter++;
		}

		return counter;
	}

	short countPunctuationSymbols()
	{
		return countPunctuationSymbols(_value);
	}


	static short countVowels(string text)
	{
		short counter = 0;

		for (int i = 0; i < text.length(); i++)
		{
			if (isVowel(text[i]))
				counter++;
		}

		return counter;
	}

	short countVowels()
	{
		return countVowels(_value);
	}

	static short  findLetterFirstPos(string text, string letter) 
	{
		const char* ch = letter.c_str();
		for (int i = 0; i <= text.length(); i++) 
		{
			if (text[i] == *ch) 
			{
				return i;
			}
		}
	}

	short  findLetterFirstPos(string letter)
	{
		return findLetterFirstPos(_value, letter);
	}

	static short findLetterLastPos(string text, string letter)
	{
		const char* ch = letter.c_str();

		for (int i = text.length() - 1; i >= 0; i--)
		{
			if (text[i] == *ch)
			{
				return i;
			}
		}
	}

	short  findLetterLastPos(string letter)
	{
		return findLetterLastPos(_value, letter);
	}

	static char charPosition(string text, short pos) 
	{
		for (int i = 0; i < text.length(); i++) 
		{
			if (i == pos) 
			{
				return text[i];
			}
		}
	}



	char charPosition(short pos)
	{
		return charPosition(_value, pos);
	}


    static  bool stringCompare(string text1, string text2)
	{
		return (text1 == text2);
	}

	bool stringCompare(string text) 
	{
		return stringCompare(_value, text);
	}

	static  bool compareStringObjects(MyString& obj1, MyString& obj2)
	{
		return (obj2._value == obj2._value);
	}

	bool compareStringObjects(MyString& otherObject)
	{
		return compareStringObjects(*this, otherObject);
	}


	static bool compareObjects(MyString &obj1, MyString& obj2) 
	{
		return (&obj1 == &obj2);
	}

    bool compareObjects(MyString& otherObject)
	{
		return compareObjects(*this, otherObject);
	}

	static bool equalTo(string text1, string text2)
	{
		return text1 == text2;
	}

	bool equalTo(string text)
	{
		return equalTo(_value, text);
	}

	static bool equalToIgnoreCase(string text1, string text2)
	{
		text1 = toUpperCase(text1);
		text2 = toUpperCase(text2);

		return text1 == text2;
	}

	bool equalToIgnoreCase(string text)
	{
		return equalToIgnoreCase(_value, text);
	}

	static string reverseWords(string text, string delimiter)
	{
		vector <string> vText = splitString(text, delimiter);
		string reverseTextWords = "";

		for (int i = vText.size() - 1; i >= 0; i--) 
		{
			reverseTextWords += vText[i] + delimiter;
		}

		return reverseTextWords;
	}

	string reverseWords(string delimiter = " ")
	{
		return reverseWords(_value, delimiter);
	}

	
	static string reverseString(string text) 
	{
		string reverseText = "";

		for (int i = text.length() - 1; i >= 0; i--) 
		{
			reverseText  += text[i];
		}

		return reverseText;
	}

	string reverseString() 
	{
		return reverseString(_value);
	}



	static string concatString(string text1, string text2)
	{
		return text1 + text2;
	}

	string concatString(string text)
	{
		return concatString(_value, text);
	}

	static string concatStringObjects(MyString &obj1, MyString &obj2) 
	{
		return obj1.value + obj2.value;
	}

	string concatStringObjects(MyString &otherObject) 
	{
		return concatStringObjects(*this, otherObject);
	}

	static string stringReplace(string text, string stringToReplace, string replaceTo) 
	{
		vector <string> vText = splitString(text, " ");

		for (string &line : vText) 
		{
			if (toLowerCase(line) == toLowerCase(stringToReplace)) 
			{
				line = replaceTo;

				break;
			}
		}

		text = joinString(vText, " ");

		return text;
	}

	string stringReplace(string stringToReplace, string replaceTo)
	{
		return stringReplace(_value, stringToReplace, replaceTo);
	}

	

	~MyString() 
	{
		cout << "The End Of String Object life Time\n";
	}
};


