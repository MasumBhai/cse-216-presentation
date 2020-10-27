/// Name : Syed Taha Yeasin Ramadan
/// ID : 201914023
/// Leetcode Username : tahayeasin
/// Problem Link : https://leetcode.com/problems/word-ladder/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict;
        for(string c: wordList){
            dict.insert(c);
        }

       if (dict.find(endWord) == dict.end())   return 0;

       int lvl = 0, wordsize = beginWord.size();

       queue<string> que;
       que.push(beginWord);
       while (!que.empty()) {
          ++lvl;
          int sz = que.size();
          for (int i = 0; i < sz; i++) {
             string word = que.front();
             que.pop();
             for (int j = 0; j < wordsize; j++) {
                char char_val = word[j];
                for (char c = 'a'; c <= 'z'; c++) {
                   word[j] = c;
                   if (word == endWord) return lvl+ 1;
                   if (dict.find(word) == dict.end())  continue;
                   dict.erase(word);
                   que.push(word);
                }
                word[j] = char_val;
             }
          }
       }
       return 0;

    }
};














