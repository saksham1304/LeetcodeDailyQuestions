#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    string truncateSentence(string s, int k) {
        vector<string> words; // Changed the vector type to string
        string currentWord;

        for (char ch : s) {
            if (ch == ' ') {
                words.push_back(currentWord);
                currentWord = ""; // Reset currentWord for the next word
            } else {
                currentWord += ch;
            }
        }

        // Add the last word to the vector
        words.push_back(currentWord);

        // Build the truncated sentence
        string truncatedSentence;
        for (int i = 0; i < min(k, static_cast<int>(words.size())); ++i) {
            truncatedSentence += words[i];
            if (i < k - 1) {
                truncatedSentence += ' '; // Add space between words
            }
        }

        return truncatedSentence;
    }
};