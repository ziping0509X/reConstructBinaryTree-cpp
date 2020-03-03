//剑指第4题 重建二叉树
// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

#include <iostream>
#include <vector>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* ConstrcutBinaryTree(int* Pre_start,int* Pre_end,int* In_start,int* In_end){
    //形参返回的是一个指针，这个指针指向的是一个整形的数组，这里和直接调用表数组名字的效果也是一样的
    //找到根节点的值
    int root_value=Pre_start[0];
    TreeNode* root=new TreeNode(Pre_start[0]);
    root->val=root_value;
    root->left=root->right= nullptr;
    //在中序遍历中找到这个根节点的值，区分出左子树和右子树
    int* root_in=In_start;
    while(root_in!= nullptr&&(*root_in)!=root_value){
        root_in++;
    }//root_in已经存放着中序中的根节点的指针了

    //使用递归的思路分别构建左子树和右子树
    int length_left;
    length_left=root_in-In_start;
    int* left_pre_end=Pre_start+length_left;
    if(length_left>0){
        root->left=ConstrcutBinaryTree(Pre_start+1,left_pre_end,In_start,root_in-1);
    }
    if(length_left<Pre_end-Pre_start){
        root->right=ConstrcutBinaryTree(left_pre_end+1,Pre_end,root_in+1,In_end);
    }
    return root;
}

class Solution{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin){
        int lengthsum=pre.size();
        return ConstrcutBinaryTree(pre.data(),pre.data()+lengthsum-1,vin.data(),vin.data()+lengthsum-1);
    }
};


//using namespace std;
//
//struct BinaryTreeNode{
//    int Value;
//    BinaryTreeNode* pLeft;
//    BinaryTreeNode* pRight;
//};
//
//
//class Solution{
//public:
//    BinaryTreeNode* reConstrcutBinaryTree(vector<int> pre,vector<int> vin){
//        int lengthsum=pre.size();
//        return ConstructCore(pre.data(),pre.data()+lengthsum-1,vin.data(),vin.data()+lengthsum-1);
//
//
//    }
//
//private:
//    BinaryTreeNode* ConstructCore(int* Pre_start,int* Pre_end,int* In_start,int* In_end){
//        //形参返回的是一个指针，这个指针指向的是一个整形的数组，这里和直接调用表数组名字的效果也是一样的
//        //找到根节点的值
//        int root_value=Pre_start[0];
//        //BinaryTreeNode* root=new BinaryTreeNode();
//        BinaryTreeNode treenode;
//        //TreeNode* root=new TreeNode();
//        BinaryTreeNode* root=&treenode;
//        root->Value=root_value;
//        root->pLeft=root->pRight= nullptr;
//        //在中序遍历中找到这个根节点的值，区分出左子树和右子树
//        int* root_in=In_start;
//        while(root_in!= nullptr&&(*root_in)!=root_value){
//            root_in++;
//        }//root_in已经存放着中序中的根节点的指针了
//
//        //使用递归的思路分别构建左子树和右子树
//        int length_left;
//        length_left=root_in-In_start;
//        int* left_pre_end=Pre_start+length_left;
//        if(length_left>0){
//            root->pLeft=ConstructCore(Pre_start+1,left_pre_end,In_start,root_in-1);
//        }
//        if(length_left<Pre_end-Pre_start){
//            root->pRight=ConstructCore(left_pre_end+1,Pre_end,root_in+1,In_end);
//        }
//        return root;
//
//
//    }
//};
//
//TreeNode* ConstrcutBinaryTree(int* Pre_start,int* Pre_end,int* In_start,int* In_end){
//    //形参返回的是一个指针，这个指针指向的是一个整形的数组，这里和直接调用表数组名字的效果也是一样的
//    //找到根节点的值
//    int root_value=Pre_start[0];
//    TreeNode* root=new TreeNode(preStart[0);
//    root->Value=root_value;
//    root->pLeft=root->pRight= nullptr;
//    //在中序遍历中找到这个根节点的值，区分出左子树和右子树
//    int* root_in=In_start;
//    while(root_in!= nullptr&&(*root_in)!=root_value){
//        root_in++;
//    }//root_in已经存放着中序中的根节点的指针了
//
//    //使用递归的思路分别构建左子树和右子树
//    int length_left;
//    length_left=root_in-In_start;
//    int* left_pre_end=Pre_start+length_left;
//    if(length_left>0){
//        root->pLeft=ConstructCore(Pre_start+1,left_pre_end,In_start,root_in-1);
//    }
//    if(length_left<Pre_end-Pre_start){
//        root->pRight=ConstructCore(left_pre_end+1,Pre_end,root_in+1,In_end);
//    }
//    return root;
//}
//
//class Solution{
//public:
//    TreeNode* reConstrcutBinaryTree(vector<int> pre,vector<int> vin){
//        int lengthsum=pre.size();
//        return ConstrcutBinaryTree(pre.data(),pre.data()+lengthsum-1,vin.data(),vin.data()+lengthsum-1);
//    }
//};
//

//调试成功！
