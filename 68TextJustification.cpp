#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    // add spaces to words from index (start to end) non-inclusive of end
    void addspaces(int start, int end, int amt, vector<string>& words){
        string spaces = " ";
        for(int i=1;i<=amt;i++){
            spaces += " ";
        }
        for(int i = start;i<end;i++){
            words[i] += spaces;
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int index = 1;
        int currwidth = words[0].length();
        int size = words.size();
        int start = 0;
        int remaininglength = 0;
        int spacestoadd = 0;
        vector<string> res;
        while (index < size){
            if(currwidth + words[index].length()+1 <= maxWidth){
                currwidth += words[index].length() + 1;
            }
            else{
                remaininglength = maxWidth - currwidth;
                cout << "remaining length: " << remaininglength << endl;
                spacestoadd = (index-1-start < 1) ? remaininglength : remaininglength/(index-1 - start);
                if(index-1-start == 0){
                    words[index-1] += string(remaininglength, ' ');
                }
                else{
                    addspaces(start,index-1,spacestoadd,words);
                }
                cout<< "spaces to add: " << spacestoadd << endl;
                if(index-1-start >= 1){
                    for(int i = 0;i < remaininglength%(index-1-start);i++){
                        words[start+i] += " ";
                    }
                }
                string temp = "";
                for(int i = start;i<index;i++){
                    temp+= words[i];
                }
                res.push_back(temp);
                start = index;
                currwidth = words[index].length();
            }
            index++;
        }
        string lastLine = "";
        for(int i = start; i < index; i++) {
            if (i > start) lastLine += " ";  // Add a space between words
            lastLine += words[i];
        }
        // Add remaining spaces at the end to fill to maxWidth
        lastLine += string(maxWidth - lastLine.length(), ' ');
        res.push_back(lastLine);
        return res;
    }
};

int main(){
    Solution tester;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = {"This    is    an", "example  of text", "justification.  "};
    assert(tester.fullJustify(words, 16) == res);
    words = {"What","must","be","acknowledgment","shall","be"};
    res = {"What   must   be", "acknowledgment  ", "shall be        "};
    assert(tester.fullJustify(words, 16) == res);
}