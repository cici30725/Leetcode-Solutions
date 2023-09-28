class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        unordered_map<char, char> um;
        um[')'] = '(';
        um['}'] = '{';
        um[']'] = '[';
        for(char c : s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    sk.push(c);
                    break;
                case ')':
                case '}':
                case ']':
                    if(sk.empty() || sk.top()!=um[c])
                        return false;
                    else
                        sk.pop();
                    break;
                default:
                    return false;
            }
        }
        
        return (sk.empty() ? true : false);
    }
};