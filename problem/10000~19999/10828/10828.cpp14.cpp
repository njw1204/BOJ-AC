#include <cstdio>
#include <string>
using namespace std;

class CStack {
private:
  static const int MAX_SIZE = 10000;
  int num[MAX_SIZE];
  int size;
public:
  CStack() { size = 0; }
  void Push(int val) { num[size++] = val; }
  int Pop() { return (size > 0) ? num[--size] : -1; }
  int Top() { return (size > 0) ? num[size - 1] : -1; }
  int Empty() { return (size == 0) ? 1 : 0; }
  int Size() { return size; }
};

constexpr unsigned int HashCode(const char* str) {
  return str[0] ? (unsigned int)str[0] + 0xEDB8832Full * HashCode(str + 1)
                : 8603;
}

void ExecStackCommand(CStack& stack, const string& command) {
  unsigned int opcode = HashCode(command.substr(0, 2).c_str());

  switch (opcode) {
  case HashCode("pu"):
    stack.Push(stoi(command.substr(5)));
    break;
  case HashCode("po"):
    printf("%d\n", stack.Pop());
    break;
  case HashCode("si"):
    printf("%d\n", stack.Size());
    break;
  case HashCode("em"):
    printf("%d\n", stack.Empty());
    break;
  case HashCode("to"):
    printf("%d\n", stack.Top());
    break;
  }
}

int main() {
  CStack myStack;
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    char input[20];
    scanf(" %[^\n]s", input);
    string command = input;
    ExecStackCommand(myStack, command);
  }

  return 0;
}