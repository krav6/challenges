#include "stdafx.h"
#include "MarkovAlgorithm.h"

#include <iostream>
#include <algorithm>

MarkovAlgorithm::MarkovAlgorithm()
{
	fillInputText();
	buildMaps();
	writeRandom();
}


MarkovAlgorithm::~MarkovAlgorithm()
{
}

void MarkovAlgorithm::fillInputText()
{
	std::string inputText;

	while (std::getline(std::cin, inputText) && "end" != inputText)
	{
		std::size_t previousPosition = 0;
		std::size_t actualPosition;
		while (std::string::npos != (actualPosition = inputText.find_first_of(" ", previousPosition)))
		{
			if (actualPosition > previousPosition)
			{
				m_inputs.push_back(inputText.substr(previousPosition, actualPosition - previousPosition));
			}

			previousPosition = actualPosition + 1;
		}

		if (previousPosition < inputText.length())
		{
			m_inputs.push_back(inputText.substr(previousPosition, std::string::npos));
		}
	}
}

void MarkovAlgorithm::buildMaps()
{
	for (int i = 0; i < m_inputs.size() - 2; ++i)
	{
		std::vector<std::string> prefixes{ m_inputs[i], m_inputs[i + 1] };
		m_dictionary[prefixes].push_back(m_inputs[i + 2]);
	}
}

void MarkovAlgorithm::writeRandom()
{
	auto iterator = m_dictionary.begin();
	std::advance(iterator, rand() % m_dictionary.size());
	std::string randomString;

	std::cout << iterator->first[0] << " ";
	do 
	{
		std::cout << iterator->first[1] << " ";
		randomString = iterator->second[rand() % iterator->second.size()];
	} while (m_dictionary.end() != (iterator = m_dictionary.find(std::vector<std::string>{iterator->first[1], randomString})));

	std::cout << randomString;
}