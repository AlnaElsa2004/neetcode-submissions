class PrefixTree {
public:
vector<string> result;
    PrefixTree() {
        
    }
    
    void insert(string word) {
        result.push_back(word);
    }
    
    bool search(string word) {
        for(int i=0;i<result.size();i++){
            if(result[i]==word){
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for(int i = 0; i < result.size(); i++) {
            if(result[i].substr(0, prefix.size()) == prefix) {
                return true;
            }
        }
        return false;
    }
};
