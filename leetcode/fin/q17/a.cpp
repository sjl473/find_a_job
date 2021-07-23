class Solution {
public:
    const vector<string> my_map = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if(digits.empty() == true) {
            return vector<string>();
        }
        vector<string> result;
        vector<string> final;
        result.emplace_back("");
        int sum = 0;
        for(int i = 0; i < digits.length(); i++) {
            if(digits[i] == '0' || digits[i] == '1') {
                ++sum;
            }
        }
        int max_result = digits.length() - sum;
        for(int i = 0; i < digits.length(); i++) {
            char which_digit = digits[i];
            int index = which_digit - '0';
            string letter = my_map[index];
            int result_size = result.size();
            for(int k = 0; k < result_size; k++) {
                for(int j = 0; j < letter.length(); j++) {
                    auto my_copy = result[k];
                    my_copy.push_back(letter[j]);
                    result.push_back(my_copy);
                    if(my_copy.length() == max_result) {
                        final.push_back(my_copy);
                    }
                }
            }
        }
        return final;
    }
};


