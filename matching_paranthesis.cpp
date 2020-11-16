/**
 * Program to check whether a given string has matching pair of parantheses.
 * answer: 1 - valid, 0 - invalid.
**/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s)
{
  bool ans;
  stack<char> St; //stack to push the characters
  /**
   * if the character is an open paranthesis then push in the stack
   * else if character is a closing paranthesis then pop topmost char
   * from stack and match with the closing paranthesis, if the type matches
   * then continue so untill you reach end of string and stack is empty.
   * }
  **/
  int i, flag = 1;
  for(i = 0; i < s.size(); i++)
  {
    if(s[i] == '(' || s[i] == '{' || s[i] == '[')St.push(s[i]); //always push an open paranthesis in stack.
    else if(St.empty() && (s[i] == '}' || s[i] == ']' || s[i] == ')'))  //if stack is empty but we encounter a closing paranthesis.
    {
      ans = false;
      flag = 0; //to indicate this particular case
      break;
    }
    else       //the open paranthesis doesn't match with the closing paranthesis.
    {
      char temp = St.top();
      if(temp == '(' && s[i] != ')')
      {
        ans = false;
        break;
      }
      else if(temp == '{' && s[i] != '}')
      {
        ans = false;
        break;
      }
      else if(temp == '[' && s[i] != ']')
      {
        ans = false;
        break;
      }
      else St.pop();
    }
  }
  if(St.empty() && flag == 1)ans = true;  //if stack is empty and we didn't the above specified particular case.

  return ans;
}

int main()
{
  string s;
  cout << "You can only enter following characters as a string:\n\t";
  cout << "[, (, {, }, ), ]\n";

  cout << "\nEnter string: ";
  getline(cin, s);

  cout << "\nIs the parantheses sequence valid? ";
  bool ans = isValid(s);
  cout << "\nAnswer: " << ans << "\n";
}
