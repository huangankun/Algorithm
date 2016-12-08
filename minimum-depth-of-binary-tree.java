public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }

public class Solution {
  public int run(TreeNode root) {          
        if(root!=null){
            int left = Integer.MAX_VALUE;
            int right = Integer.MAX_VALUE;
            if(root.left!=null){
                left = run(root.left);
            }
            if(root.right!=null){
                right = run(root.right);
            }
            if(left<right){
                return left+1;
            }
            else if(left>right){
                return right+1;
            }
            else if(left==right&&left!=Integer.MAX_VALUE){
                return left+1;
            }
            else 
                return 1;
        }
        return 0;
            
        
    
    }  
}