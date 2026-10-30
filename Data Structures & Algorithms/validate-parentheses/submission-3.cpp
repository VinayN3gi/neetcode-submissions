class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            char x=s[i];
            if(x=='{' || x=='[' || x=='(') stk.push(x);
            else
            {
                if(stk.empty()) return false;
                if(x==']' && stk.top()!='[') return false;
                else if(x==')' && stk.top()!='(') return false;
                else if(x=='}' && stk.top()!='{') return false;
                else stk.pop();
            }
        }
        return stk.empty();
    }
};
