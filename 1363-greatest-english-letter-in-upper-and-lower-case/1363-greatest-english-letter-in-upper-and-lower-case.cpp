class Solution {
public:
    string greatestLetter(string s) {
        bool counter[128] = {0};
        for (char c : s)
            counter[c] = true;

        for (char i = 'Z'; i >= 'A'; --i) {
            if (counter[i] && counter[i + 'a' - 'A'])
                return std::string(1, (char)i);
        }

        return "";
    }
};