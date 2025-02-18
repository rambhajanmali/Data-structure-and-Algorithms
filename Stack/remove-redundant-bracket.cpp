#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {

            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorCount++;
                }
                st.pop();
            }
            // yha pr aap tabhi pohochoge jab apke sstack k top pr ek opening bracket hoga
            st.pop();
            if (operatorCount == 0)
            {
                return true;
            }
        }
    }
    // yha pahuche iska mtlb har opeartor ke pair ke beech me ek operaror mila h
    return false;
}

int main()
{
    string str = "((a+b))";
    bool ans = checkRedundant(str);
    if (ans == true)
    {
        cout << "redundant bracket present h" << endl;
    }
    else
    {
        cout << "redundant bracket present nahi h" << endl;
    }
    // cout<<checkRedundant(str)<<endl;
    return 0;
}