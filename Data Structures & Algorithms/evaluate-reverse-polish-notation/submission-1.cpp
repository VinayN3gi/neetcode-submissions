class Solution {
public:
    int solve(string op,int num1,int num2)
    {
        if(op=="+") return num1 + num2;
        else if(op=="-") return num1 - num2;
        else if(op=="*") return num1 * num2;
        else return num1 / num2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int val1=stk.top();stk.pop();
                int val2=stk.top();stk.pop();
                int ans=solve(tokens[i],val2,val1);
                stk.push(ans);
            }
            else 
            {
                int val=stoi(tokens[i]);
                stk.push(val);
            }
        }

        return stk.top();
    }
};
