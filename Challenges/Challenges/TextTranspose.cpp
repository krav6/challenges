#include "stdafx.h"
#include "TextTranspose.h"

#include <iostream>
#include <algorithm>

TextTranspose::TextTranspose()
{
	fillInputText();
	normalizeLineEndings();
	writeTransposeText();
}

TextTranspose::~TextTranspose()
{
}

void TextTranspose::fillInputText()
{
	std::string text;
	m_longestLineLength = 0;

	while (std::getline(std::cin, text) && "end" != text)
	{
		m_inputs.push_back(text);
		if (text.length() > m_longestLineLength)
		{
			m_longestLineLength = text.length();
		}
	}
}

void TextTranspose::normalizeLineEndings()
{
	std::for_each(m_inputs.begin(), m_inputs.end(),
		[this](std::string& text)
	{
		if (text.length() < this->m_longestLineLength)
		{
			text.append(this->m_longestLineLength - text.length(), ' ');
		}
	});
}

void TextTranspose::writeTransposeText()
{
	for (int i = 0; i < m_longestLineLength; ++i)
	{
		for (auto& line: m_inputs)
		{
			std::cout << line[i];
		}
		
		std::cout << std::endl;
	}
}