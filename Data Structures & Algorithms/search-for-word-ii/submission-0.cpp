class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode* root;
    vector<string> result;
    int rows, cols;

    void insert(string word) {
        TrieNode* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->isWord = true;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* node,
             string word) {

        if(r < 0 || c < 0 || r >= rows || c >= cols ||
           board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];

        if(node->children[ch - 'a'] == nullptr) {
            return;
        }

        node = node->children[ch - 'a'];
        word += ch;

        if(node->isWord) {
            result.push_back(word);
            node->isWord = false; // avoid duplicates
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new TrieNode();

        for(string word : words) {
            insert(word);
        }

        rows = board.size();
        cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                dfs(board, r, c, root, "");
            }
        }

        return result;
    }
};