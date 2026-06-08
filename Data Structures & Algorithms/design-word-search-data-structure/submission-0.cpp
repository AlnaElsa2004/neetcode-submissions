class WordDictionary {
public:
    WordDictionary() {
        
    }
    vector<string> res;
    void addWord(string word) {
       res.push_back(word); 
    }
    
    bool search(string word) {

    for(int i = 0; i < res.size(); i++) {

        if(res[i].length() != word.length())
            continue;

        int count = 0;

        for(int j = 0; j < word.length(); j++) {

            if(word[j] == '.' || word[j] == res[i][j]) {
                count++;
            }
        }

        if(count == word.length()) {
            return true;
        }
    }

    return false;
}
};
