class Solution {
//     public List<List<String>> printTree(TreeNode root) {
//         List<List<String>> result = new ArrayList<>();
//         int dep = getDepth(root);
//         Queue<TreeNode> queue = new LinkedList<>();
//         queue.add(root);
//         // System.out.println("dep = "+dep);
//         for(int i = 0;i < dep;i++) {
//             List<String> list = new ArrayList<>();
//             for(int j = 0;j < Math.pow(2, dep)-1;j++)
//                 list.add("");
//             List<Integer> index = new ArrayList<>();
//             getIndex(i, 0, list.size() - 1, index);
//             for(int j = 0;j < Math.pow(2, i);j++) {
//                 TreeNode temp = queue.poll();
//                 if(temp == null) {
//                     queue.add(temp);
//                     queue.add(temp);
//                 } else {
//                     list.set(index.get(j), ""+temp.val);
//                     queue.add(temp.left);
//                     queue.add(temp.right);
//                 }
//             }
//             result.add(list);
//         }
//         return result;
//     }
    
//     public int getDepth(TreeNode root) {
//         if(root == null)
//             return 0;
//         return 1 + Math.max(getDepth(root.left), getDepth(root.right));
//     }
    
//     public void getIndex(int num, int left, int right, List<Integer> index) {
//         int mid = (left + right) / 2;
//         if(num == 0)
//             index.add(mid);
//         else {
//             getIndex(num - 1, left, mid - 1, index);
//             getIndex(num - 1, mid + 1, right, index);
//         }
//     }
// } 
