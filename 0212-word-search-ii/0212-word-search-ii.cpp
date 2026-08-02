#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void insertTrie(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, vector<string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';
        
        // Base case: if cell is visited ('#') or child path doesn't exist in Trie
        if (ch == '#' || !curr->children[idx]) {
            return;
        }

        curr = curr->children[idx];
        
        // If we found a complete word
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; // De-duplicate by clearing the word
        }

        // Mark the current cell as visited
        board[r][c] = '#';

        // Explore all 4 possible directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, curr, result);
            }
        }

        // Backtrack: restore the cell value
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            insertTrie(root, w);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};