//Design a data structure that supports the following two operations:
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string 
//containing only letters a-z or .. A . means it can represent any one letter.
//
//For example:
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//Note:
//You may assume that all words are consist of lowercase letters a-z.


#include <string>
#include <set>
#include <vector>
using namespace std;

class WordDictionary {
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		dict.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return subSearch(word, 0);
	}
private:
	bool subSearch(string word, int num){
		const int alphaNum = 26;
		for(int i = num; i != word.size(); ++i){
			if('.' == word[i]){
				for(int j = 0; j != alphaNum; ++j){
					word[i] = 'a' + j;
					if(subSearch(word, i + 1)){
						break;
					}
				}
				if(subSearch(word, i + 1)){
					break;
				}
				word[i] = '.';
			}
		}
		return dict.find(word) != dict.end();
	}
	set<string> dict;
};

int main(){
	WordDictionary temp;
	temp.addWord("a");
	bool result = temp.search(".");
	return 0;
}