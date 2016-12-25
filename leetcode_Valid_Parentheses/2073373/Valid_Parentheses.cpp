class Solution {
public:
    bool isValid(string s) 
    {
        int len=s.length();
        vector<char> myStack;               
        for(int i=0;i<len;i++)
            if(s[i] == '(' 
            || s[i] == '{'  
            || s[i] =='[')
                myStack.push_back(s[i]);
            else
            {
                if(myStack.empty())
                    return false;
                char stack_top = myStack[myStack.size()-1];
                if(s[i] == ')' && stack_top != '(')
                    return false;
                if(s[i] == ']' && stack_top != '[')
                    return false;
                if(s[i] == '}' && stack_top != '{')
                    return false;
                myStack.pop_back();
            }
        if(myStack.size() > 0) return false;
        return true;
    }
};