#include <stdio.h>
#include <stack>
using namespace std;
stack<char> s;
char x;

int main()
{
input:
  x = getchar();
  if (x == '(') {
    s.push('(');
  }
  else if (x == ')') {
    while (s.top() != '(') {
      printf("%c", s.top());
      s.pop();
    }
    s.pop();
  }
  else if (x == '+' || x == '-') {
    while (!s.empty() && s.top() != '(') {
      printf("%c", s.top());
      s.pop();
    }
    s.push(x);
  }
  else if (x == '*' || x == '/') {
    while (!s.empty() && (s.top()=='*' || s.top()=='/')) {
      printf("%c", s.top());
      s.pop();
    }
    s.push(x);
  }
  else if (x >= 'A' && x <= 'Z') {
    printf("%c", x);
  }
  else {
    while (!s.empty()) {
      printf("%c", s.top());
      s.pop();
    }
    return 0;
  }
  goto input;
  return 0;
}