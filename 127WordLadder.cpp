#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // BFS approach: first put wordList in hashtable for easy access.
        // while loop:
        // for every index of word(starting with beginword), swap out that index with all 26 letters of alphabet to see if there's match in wordlist
        // if there is match, add it to queue as a tuple(word and level of word in the tree), remove it from hashtable
        // can break out if words are all added already (no more in hashtable), keep counter
        // if there are elements in queue, go through that and check for matches in hashtable
        int n = beginWord.length();
        unordered_set<string> words;
        queue<tuple<string, int>> wordque;
        wordque.push(make_tuple(beginWord, 0));
        for (string x : wordList)
        {
            words.insert(x);
        }
        int count = wordList.size();
        while (!wordque.empty())
        {
            tuple<string, int> toptuple = wordque.front();
            wordque.pop();
            string currword = get<0>(toptuple);
            int layer = get<1>(toptuple) + 1;
            for (int i = 0; i < n; i++)
            {
                string temp = currword;
                if (count == 0)
                    break;
                for (char sub = 'a'; sub <= 'z'; sub++)
                {
                    if (count == 0)
                        break;
                    temp[i] = sub;
                    if (words.find(temp) != words.end())
                    {
                        if (temp == endWord)
                        {
                            return layer + 1;
                        }
                        wordque.push(make_tuple(temp, layer));
                        words.erase(temp);
                        count--;
                    }
                }
            }
        }
        return 0;
    }
};
// Time complexity: O(ML^2) where L is the length of the word and M is the number of words in Wordslist.
// Space complexity: O(n) for the hashtable and queue.

int main()
{
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl; // Output: 5
    // Test case 2
    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    cout << sol.ladderLength(beginWord2, endWord2, wordList2) << endl; // Output: 0
}