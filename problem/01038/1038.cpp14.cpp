#include <iostream>
using namespace std;

long long int pow10[10] = {0}; // pow(10,i) 값들을 저장하기 위한 배열

int CheckDecNum(long long num, int digit) { // 감소하는 수일시 -1, 아닐시 문제되는 자리값 반환
  for (int i = 0; i < digit; i++) {
    long long temp_pow10 = pow10[i];
    for (int j = i + 1; j < digit + 1; j++) {
      if ((num / temp_pow10 % 10) >= (num / pow10[j] % 10))
        return i;
    }
  }
  return -1;
}

int main() {
  int dp[10][10] = {0}; // i = i자리수, j = 첫번째 숫자
  int count = 9;     // count = 지금까지 구한 감소하는 수 개수
  int N, digit, first_num, second_num;

  for (int i = 0; i < 10; i++) dp[0][i] = 1; // 초기값 설정
  cin >> N;
  if (N < 11) {
    cout << N;
    return 0;
  }

  bool finish_loop = false;
  for (int i = 1; i < 10 && (!finish_loop); i++) {
    for (int j = i; j < 10 && (!finish_loop); j++) {
        // i자리(현재 구하는 자리)의 최소 숫자는 i, 최대 숫자는 9
      for (int k = i - 1; k < j && (!finish_loop); k++) {
        // i-1자리(이전 자리)의 최소 숫자는 i-1, 최대 숫자는 j-1
        count += dp[i - 1][k];
        if (count >= N) { // 지금까지 구한 감소하는 수 개수가 N개보다 많거나 같으면
          count -= dp[i - 1][k]; // 지금 구한 카운트는 다시 뺀다.
          finish_loop = true;
          // 현재 구간안에 우리가 찾는 감소하는 수가 있다.
          // 자리수, 첫번째 숫자, 두번째 숫자를 설정
          digit = i;
          first_num = j;
          second_num = k;
          break;
        } else dp[i][j] += dp[i - 1][k];
      }
    }
  }
  if (finish_loop == false) { // N번째 감소하는 수가 없으면
    cout << -1;
    return 0;
  }
  // pow10 값을 미리 저장해둠
  for (int i = 0; i < 10; i++) {
    pow10[i] = 1;
    for (int j = 0; j < i; j++) pow10[i] *= 10;
  }

  long long result = first_num * 10 + second_num;
  for (int i = 1; i < digit; i++) result *= 10; // first_num 과 second_num 설정
  for (int i = 1; i < digit - 1; i++) result += pow10[i] * i; // 그 외 자리를 최솟값으로 설정
    
  while (1) {
    int check_data = CheckDecNum(result, digit);
    if (check_data == -1) {
      count++;
      if (count == N) break;
      result++;
    } else if (check_data > 8) {
      cout << "Error!" << endl;
      return 0;
    } else result += pow10[check_data + 1] - (result % pow10[check_data + 1]);
  }
  printf("%lld", result);
  return 0;
}