#pragma once

//Description
//
//Write a program that takes input text from standard input and outputs the text -- transposed.
//Roughly explained, the transpose of a matrix
//Some
//text.
//is given by
//St
//oe
//mx
//et
// .
//Rows become columns and columns become rows.See https ://en.wikipedia.org/wiki/Transpose.

#include <string>
#include <vector>

class TextTranspose
{
public:
	TextTranspose();
	~TextTranspose();

private:

	//Fills the input member vector with lines until it reads the "end" string.
	void fillInputText();

	//According to the longestLineLength member integer appends empty spaces to it's shorter string elements.
	void normalizeLineEndings();

	//Writes text in transpose from the input member vector.
	void writeTransposeText();

	//Line inputs stored in a vector
	std::vector<std::string> m_inputs;

	//Longest line length in the input member vector
	int						 m_longestLineLength;
};

