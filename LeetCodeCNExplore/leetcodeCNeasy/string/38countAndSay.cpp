// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/39/

/*
报数
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"
*/
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        else if (n == 2)
        {
            return "11";
        }
        else
        {
            string pre = countAndSay(n - 1);
            int count = 1;
            int num = -1;
            string res = "";
            for (int i = 0; i < pre.size(); i++)
            {
                int cursor = i;
                int count = 0;
                while (pre[cursor] == pre[i] && cursor < pre.size())
                {
                    count++;
                    cursor++;
                }
                res += to_string(count);
                res += pre[i];
                i = cursor - 1; // i move to cursor for next iteration after i++ in the for loop
            }
            return res;
        }
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
    cout << s.countAndSay(6) << endl;
}