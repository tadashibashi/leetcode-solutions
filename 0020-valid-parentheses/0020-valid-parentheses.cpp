class Solution {
public:
    bool isValid(string s) {
        stack<char> openParen;

        for (const char &c : s) {
            switch(c) {
                case '[':
                case '(':
                case '{':
                    openParen.emplace(c);
                    break;
                case ']':
                    if (openParen.empty() || openParen.top() != '[') return false;
                    else openParen.pop();
                    break;
                case ')':
                    if (openParen.empty() || openParen.top() != '(') return false;
                    else openParen.pop();
                    break;
                case '}':
                    if (openParen.empty() || openParen.top() != '{') return false;
                    else openParen.pop();
                    break;
            }
        }

        return openParen.empty();
    }
};