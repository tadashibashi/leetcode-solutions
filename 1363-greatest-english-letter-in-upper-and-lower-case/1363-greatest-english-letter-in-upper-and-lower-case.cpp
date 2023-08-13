class Solution {
public:
    string greatestLetter(string s) {
        std::set<char> set;
        int greatest = 0;
        for (auto it = s.begin(); it < s.end(); ++it) {
            set.emplace(*it);
        }

        for (const char &c : s) {
            if (isupper(c)) {
                if (set.count(tolower(c)))
                    if (c > greatest)
                        greatest = c;
            }
        }

        return greatest > 0 ? std::string({(char)greatest}) : std::string{};
    }
};