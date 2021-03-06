/*
二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        string str = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                str.append(to_string(temp->val));
                str.append(",");
                q.push(temp->left);
                q.push(temp->right);
            }
            else
            {
                str.append("null,");
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;
        vector<string> ser;
        string temp;
        stringstream input(data);
        while (getline(input, temp, ','))
        {
            ser.push_back(temp);
        }

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(stoi(ser[0]));
        q.push(root);
        int i = 1;
        while (i < ser.size())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (ser[i] != "null")
            {
                TreeNode *l = new TreeNode(stoi(ser[i]));
                temp->left = l;
                q.push(l);
            }
            i++;
            if (ser[i] != "null")
            {
                TreeNode *r = new TreeNode(stoi(ser[i]));
                temp->right = r;
                q.push(r);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));