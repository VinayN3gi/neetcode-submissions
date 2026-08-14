class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            char x=s[i];
            if(stk.empty()) stk.push(x);
            else if(x==']')
            {
                if(stk.top()=='[') 
                {
                    stk.pop();
                }
                else return false;
            }
            else if(x=='}')
            {
                if(stk.top()=='{')
                {
                    stk.pop();
                }
                else return false;
            }
            else if(x==')')
            {
                if(stk.top()=='(') stk.pop();
                else return false;
            }
            else if((x=='}' || x==']' || x==')') && stk.empty()) return false;
            else stk.push(x);
        }
        return stk.empty();
    }
};
