class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int lenSource = haystack.length(),lenNeed = needle.length();
        if(lenNeed == 0) return 0;
        for(int i =0,j=0 ; i<=lenSource - lenNeed;i++)
        {
            for(j= 0; j< lenNeed; j++)
                if(haystack[i+j] != needle[j]) break;
            if(j ==lenNeed) return i;       //匹配成功
        }
        return -1;
    }
};