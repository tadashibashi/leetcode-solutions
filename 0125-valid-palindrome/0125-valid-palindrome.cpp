class Solution {
public:
    bool isPalindrome(string s) {
        for (auto start=s.begin(), end=(s.end()-1); 
            start < end; 
            ++start, --end) 
        {
            while(!isalnum(*start) && start < end) ++start;
            while(!isalnum(*end) && end > start) --end;

            if (tolower(*start) != tolower(*end)) return false;
        }

        return true;
    }
};