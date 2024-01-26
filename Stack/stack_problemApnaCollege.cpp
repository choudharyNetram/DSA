#include<iostream>
using namespace std ;

/// 
/*
Infix expression: The expression of the form an operator b (a + b). When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b operator (ab+). When an operator is followed by every pair of operands.

Input: A + B * C + D
Output: ABC*+D+
// read from gfg about postfix and Infix 

// conversation  from infix to postfix 

*/
/* C++ implementation to convert
infix expression to postfix
 */
#include <bits/stdc++.h>
using namespace std;
#include<stack> 
// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{
 
    stack<char> st; // For stack operations, we are using
                    // C++ built in stack
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        // If an operator is scanned
        else {
            while (!st.empty()
                   && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;
}
 
// Driver's code
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
 
    // Function call
    cout<<"coverting infex to prefix"<<endl; 
    infixToPostfix(exp);
    return 0;
}


