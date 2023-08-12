class Solution {
public:
    string reverseWords(string s) {
        int end = -1;
        string res;
        res.reserve(s.size());

        for (int i = s.size()-1; i >= 0; --i) {
            if (end == -1) { // need to find the end of a word
                if (isalnum(s[i]))
                    end = i;
            } else {         // looking for word 
                const bool space = isspace(s[i]);
                if (i == 0 || space) {
                    int c = i;
                    if (space)
                        ++c;

                    for (; c <= end; ++c)
                        res += s[c];
                    res += ' ';
                    end = -1;
                }
            }
        }

        if (end != -1)
            res.push_back(s[0]);
        else if (!res.empty())
            res.pop_back();

        return res;
    }
};