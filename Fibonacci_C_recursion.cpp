/*
 15级楼梯，一步最多三级，爬上楼梯可以有多少种走法实现
*/
#include<iostream>
using namespace std;
 
int count(int x){
    if(x==15)
        return 1;
    else if(x>15)
        return 0;
    return count(x+1)+count(x+2)+count(x+3);
}
int main(){
        cout<<count(0)<<endl;
    return 0;
}
