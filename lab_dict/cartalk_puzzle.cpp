/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of 
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector< StringTriple > cartalk_puzzle(PronounceDict d,
                                      const string& word_list_fname)
{
    /* Your code goes here! */
    	string word;

	vector<StringTriple> out;

	vector<string> vectorWords;
	ifstream words(word_list_fname);
	

	if(words.is_open()) 
	{
   		while(getline(words, word)) 
        {
			if(word.length() == 5)
				vectorWords.push_back(word);
		}
	}

	for(auto & eachWord : vectorWords)
	{
		std:: string removeFirst = eachWord.substr(1);
		std:: string removeSecond;
		removeSecond.append(eachWord.begin(),eachWord.begin()+1);
		removeSecond.append(removeFirst.begin()+1,removeFirst.end());
		if(d.homophones(eachWord, removeFirst)&&d.homophones(eachWord, removeSecond)&&d.homophones(removeFirst, removeSecond))
		{	
			StringTriple a;
			std::get<0>(a) = eachWord; 
			std::get<1>(a) = removeFirst;
			std::get<2>(a) = removeSecond;
			out.push_back(a);
		}			 
	}

    return out;
}


