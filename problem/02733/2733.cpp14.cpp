#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

char op[128000];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int T;
  cin >> T;
  cin.ignore(1024, '\n');

  for (int kk = 1; kk <= T; kk++) {
    bool compileError = false;
    int opCnt = 0, level = 0;
    memset(op, 0, sizeof(op));
    cout << "PROGRAM #" << kk << ":\n";

    while (1) {
      string input;
      getline(cin, input);
      if (input == "end") break;

      for (int i = 0; i < input.size(); i++) {
        switch (input[i]) {
        case '+': case '-':
        case '<': case '>':
        case '.': case '[': case ']':
          op[opCnt++] = input[i];
          if (input[i] == '[')
            level++;
          if (input[i] == ']')
            level--;
        }

        if (level < 0) compileError = true;
        if (input[i] == '%') break;
      }
    }

    if (level) compileError = true;

    unsigned char arr[32768] = {};
    int ptr = 0, skip = 0;
    stack<int> loopPos;

    for (int i = 0; i < opCnt && !compileError; i++) {
      switch (op[i]) {
      case '>':
        if (!skip) ptr = (ptr + 1) % 32768;
        break;
      case '<':
        if (!skip) ptr = (ptr > 0 ? ptr - 1 : 32767);
        break;
      case '+':
        if (!skip) arr[ptr]++;
        break;
      case '-':
        if (!skip) arr[ptr]--;
        break;
      case '.':
        if (!skip) cout << arr[ptr];
        break;
      case '[':
        loopPos.push(i);
        if (!arr[ptr] && !skip) skip = i;
        break;
      case ']':
        int loopStart = loopPos.top();
        loopPos.pop();
        if (arr[ptr]) i = loopStart - 1;
        if (skip == loopStart) skip = 0;
      }
    }

    if (compileError)
      cout << "COMPILE ERROR\n";
    else
      cout << '\n';
  }

  return 0;
}