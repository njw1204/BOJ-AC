#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define ERROR 1
#define BIGINT_SIZE 10005
#define BIGINT_MAX_LEN BIGINT_SIZE-2


typedef struct {
  int len;
  char sign;
  char num[BIGINT_SIZE];
} BigInt;


void Swap(BigInt* left, BigInt* right) {
  int maxLen, minLen, maxSide;
  if (left->len > right->len) {
    maxLen = left->len;
    minLen = right->len;
    maxSide = -1;
  }
  else {
    maxLen = right->len;
    minLen = left->len;
    maxSide = 1;
  }
  
  for (int i = 0; i < maxLen; i++) {
    if (i < minLen) {
      char t = left->num[i];
      left->num[i] = right->num[i];
      right->num[i] = t;
    }
    else if (maxSide == -1) {
      right->num[i] = left->num[i];
      left->num[i] = 0;
    }
    else {
      left->num[i] = right->num[i];
      right->num[i] = 0;
    }
  }

  int ti = left->len;
  left->len = right->len;
  right->len = ti;

  char tc = left->sign;
  left->sign = right->sign;
  right->sign = tc;
}


void Reset(BigInt* var) {
  var->sign = 1;
  var->len = 0;
  memset(var->num, 0, BIGINT_SIZE);
}


int Set(BigInt* var, const char* num) {
  Reset(var);
  for (int i = strlen(num) - 1, p = 0; i >= 0; i--, p++) {
    if (num[i] >= '0' && num[i] <= '9') {
      if (p >= BIGINT_MAX_LEN) {
        Reset(var);
        return ERROR;
      }
      else var->num[p] = num[i];
    }
    else if (i != 0 || (num[i] != '+' && num[i] != '-')) {
      Reset(var);
      return ERROR;
    }
    else if (num[i] == '-')
      var->sign = -1;
  }

  var->len = strlen(var->num);
  for (int i = var->len - 1; i >= 1; i--) {
    if (var->num[i] == '0') {
      var->num[i] = 0;
      var->len--;
    }
    else break;
  }
  
  return SUCCESS;
}


void Get(const BigInt* var, char* num) {
  int pos = 0;
  memset(num, 0, BIGINT_SIZE);
  if (var->sign == -1) num[pos++] = '-';
  for (int i = var->len - 1; i >= 0; i--, pos++)
    num[pos] = var->num[i];
}


int Compare(const BigInt* left, const BigInt* right, int absolute) {
  if (absolute == FALSE) {
    if (left->sign == 1 && right->sign == 1)
      return Compare(left, right, TRUE);
    else if (left->sign == 1 && right->sign == -1)
      return 1;
    else if (left->sign == -1 && right->sign == 1)
      return -1;
    else
      return Compare(right, left, TRUE);
  }

  if (left->len < right->len) return -1;
  else if (left->len > right->len) return 1;

  for (int i = left->len - 1; i >= 0; i--) {
    if (left->num[i] < right->num[i]) return -1;
    else if (left->num[i] > right->num[i]) return 1;
  }

  return 0;
}


int Add(BigInt* left, BigInt* right) {
  if (Compare(left, right, TRUE) == -1)
    Swap(left, right);

  if (left->sign == right->sign) {
    int carry = 0;
    for (int i = 0; i < left->len; i++) {
      int sum = left->num[i] - '0' + carry;
      if (i < right->len) sum += right->num[i] - '0';
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      }
      else carry = 0;
      left->num[i] = sum + '0';
    }

    if (carry) {
      if (left->len >= BIGINT_MAX_LEN) {
        Reset(left);
        return ERROR;
      }
      else {
        left->num[left->len] = '1';
        left->num[left->len + 1] = 0;
        left->len++;
      }
    }

    return SUCCESS;
  }

}


int main() {
  char num[BIGINT_SIZE], num2[BIGINT_SIZE];
  BigInt a, b;
  scanf("%s%s", num, num2);
  Set(&a, num);
  Set(&b, num2);
  Add(&a, &b);
  Get(&a, num);
  printf("%s\n", num);
  return 0;
}