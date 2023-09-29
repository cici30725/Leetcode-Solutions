class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> um = {
            {"+", [](int a, int b) {return a+b;}},
            {"-", [](int a, int b) {return a-b;}},
            {"*", [](int a, int b) {return a*b;}},
            {"/", [](int a, int b) {return a/b;}},
        };
        
        stack<int> sk;
        for(string& s : tokens){
            if(!um.count(s)){
                sk.push(stoi(s));
            }
            else{
                int rhs = sk.top();
                sk.pop();
                int lhs = sk.top();
                sk.pop();
                sk.push(um[s](lhs, rhs));
            }
        }
        
        return sk.top();
    }
};