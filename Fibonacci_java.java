/*
 15级楼梯，一步最多三级，爬上楼梯可以有多少种走法实现
*/
public static void main(String[] args) {
        int f1 = 1;
        int f2 = 2;
        int f3 = 4;
        int result = 0;
        for(int i = 4;i<=15;i++){
            result = f1+f2+f3;
            f1 = f2;
            f2 = f3;
            f3 = result;
        }
        System.out.println(result);
    }