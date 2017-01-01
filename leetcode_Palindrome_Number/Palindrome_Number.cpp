class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return 0;
        int n=0,temp=x,big=1,small=1;
        while(temp!=0)                  //  取数位 
        {
            n++;
            temp/=10;
            if(temp)big*=10;
        }

        for(int i=0;i<n/2;++i)          // 高地位互相判断 
        {
            if((x/big)%10!=(x/small)%10)return 0;
            big/=10;
            small*=10;
        }
        return 1;
        
    }
};