class Solution {
public:
    const char &match(const char &c) {
        static const char parens[] = {'(', '[', '{'};
        switch (c) {
            case ')': return parens[0];
            case ']': return parens[1];
            case '}': return parens[2];

            default:
                throw -1;
        }
    }

    bool isValid(string s) {
        stack<char> paren;

        for (const char &c : s) {
            switch (c) {
                case '[': case '{': case '(': paren.emplace(c); break;
                case '}': case ']': case ')':
                    if (paren.empty() || paren.top() != match(c)) return false;
                    paren.pop();
                    break;
            }
        }

        return paren.empty();
    }
};