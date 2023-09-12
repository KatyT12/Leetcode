class Solution {
public:
    int minDeletions(string s) {
        int num_deletions = 0;
        map<char, int> letters = {};
        map<int, char> freqs = {};

        for(char& c : s){
            if(letters.find(c) == letters.end()){
                letters[c] = 1;
            }else{
                letters[c]++;
            }
        }

        for(auto& pair : letters){
            cout << pair.second << "\n";
            int j = pair.second;
            if(freqs.find(j) != freqs.end()){
                while(j > 0 && freqs.find(j) != freqs.end()){
                    j--;
                    num_deletions++;
                }
                if(j > 0){freqs[j] = pair.first;}
            }else{
                freqs[j] = pair.first;
            }
        }
        return num_deletions;
    }
};