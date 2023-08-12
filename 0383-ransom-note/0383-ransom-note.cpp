class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int magChars[26] = {0};

        for (const char &c : magazine)
            ++magChars[c - 'a'];
        for (const char &c : ransomNote)
            if (--magChars[c - 'a'] < 0)
                return false;
        return true;
    }
};