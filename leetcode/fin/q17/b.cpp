class Solution {
public:
    unordered_map<int, string> my_map = unordered_map<int, string>();
    vector<int> v = vector<int>();
    string path = "";
    vector<string> result = vector<string>();
    int size = 0;
    Solution() {
        my_map[0] = "";
        my_map[1] = "";
        my_map[2] = "abc";
        my_map[3] = "def";
        my_map[4] = "ghi";
        my_map[5] = "jkl";
        my_map[6] = "mno";
        my_map[7] = "pqrs";
        my_map[8] = "tuv";
        my_map[9] = "wxyz";
    }
    void bt(vector<int>& v, int depth) {
        if(depth == this->size) {
            result.push_back(this->path);
            return;
        }
        string which_word = this->my_map[v[depth]];
        for(int i = 0; i < which_word.length(); i++) {
            path.push_back(which_word[i]);
            bt(v, depth + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return vector<string>();
        }
        vector<int> v = vector<int>(digits.length(), 0);
        for(int i = 0; i < digits.length(); i++) {
            v[i] = digits[i] - '0';
        }
        this->v = v;
        this->size = digits.length();
        bt(this->v, 0);
        return result;
    }
};
