double abs_math(double num)
{
    return num<0?-num:num;      	//取绝对值
}
class Solution{
    public:
    int mySqrt(int x)
    {
        double g = x;
        while(abs_math(g*g-x)>0.000001){
            g = (g + x / g ) / 2;
        }
        return g;
    }
}
；