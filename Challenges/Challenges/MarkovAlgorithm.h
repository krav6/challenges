#pragma once

/*Text generation algorithms exist in a wide variety of formats, including "Mad Libs" and Markov processes.A Markov chain algorithm generates text by creating a statistical model of potential textual suffixes for a given prefix.That's a fancy way of saying "it basically determines the next most probable word given the training set." Markov chain programs typically do this by breaking the input text into a series of words, then by sliding along them in some fixed sized window, storing the first N-1 words as a prefix and then the Nth word as a member of a set to choose from randomly for the suffix. Then, given a prefix, pick randomly from the suffixes to make the next piece of the chain.
Take this example text :
Now is not the time for desert, now is the time for dinner
For a set of triples, yielding a bi - gram(2 word) prefix, we will generate the following prefixes and suffix :
	Prefixes        Suffixes
	--------        --------
	Now, is         not
	is, not the
	not, the        time
	the, time       for
	time, for       desert
	for, desert     now
		desert, now     is
		now, is         not, the
		is, the         time
		the, time       for
		time, for       desert, dinner
		
Challenge
Your challenge today is to implement a Markov generator supporting a bi-gram prefix. It should be capable of ingesting a body of text for training and output a body of text generated from that.
*/

#include <string>
#include <vector>
#include <map>

class MarkovAlgorithm
{
public:
	MarkovAlgorithm();
	~MarkovAlgorithm();

	//Fills the input member vector with lines until it reads the "end" string.
	void fillInputText();

	void buildMaps();

	void writeRandom();

	//Line inputs stored in a vector
	std::vector<std::string> m_inputs;

	std::map < std::vector<std::string>, std::vector<std::string> > m_dictionary;
};

