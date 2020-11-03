/* ------------------------------------------------------------------|
给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
 



 

示例 1：

输入：[2,1]
输出：false
示例 2：

输入：[3,5,5]
输出：false
示例 3：

输入：[0,3,2,1]
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：48 ms, 在所有 C++ 提交中击败了99.08%的用户
*	内存消耗：21.2 MB, 在所有 C++ 提交中击败了5.27%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool validMountainArray(vector<int>& A) {
    if (A.size() < 3) {
        return false;
    }
    
    int left = 0;
    int right = A.size() - 1;

    //left+1 < A.size()-1
    while (left < A.size() - 2 && A[left] < A[left + 1]) {
        left++;
    }
    //right - 1 >= 0
    while (right > 0 && A[right] < A[right - 1]) {
        right--;
    }
    
    return left > 0 && right < A.size() - 1 && left == right;
}