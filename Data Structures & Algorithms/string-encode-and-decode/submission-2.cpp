class Solution {
public:
    //5#HELLO#5WORLD
    string encode(vector<string>& strs) {
        if(strs.size()==0) return "";
        string ans="";
        for(int i=0;i<strs.size();i++)
        {
            ans=ans + to_string(strs[i].size());
            ans=ans + '#';
            ans=ans + strs[i];
            //ans=+'#';
        }
        return ans;
    }
    vector<string> decode(string s) {
        if(s=="") return {};
        vector<string> ans;
        int i=0;
        while(i<s.size())
        {
            string num="";
            while(s[i]!='#') {
                num+=s[i];
                i++;
            }
            int val=stoi(num);
            i++;
            string temp=s.substr(i,val);
            i=i+ val ;
            ans.push_back(temp);
        }

        return ans;
    }
};
