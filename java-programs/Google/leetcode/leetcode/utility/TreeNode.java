package leetcode.utility;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }

    public TreeNode getLeftNode() {
        return left;
    }

    public TreeNode getRightNode() {
        return right;
    }

    public int getNodeValue() {
        return val;
    }
}
