#include <iostream>
#include <cstring>
using namespace std;

class BigNumber{
private:
  char* val;
  int digit;
  explicit BigNumber(const BigNumber& copy);
public:
  explicit BigNumber(const unsigned int digit);
  explicit BigNumber(const unsigned int digit, const char* val);
  ~BigNumber();
  void Add(const char* num);
  void Add(const BigNumber& num);
  void Set(const char* num);
  void Set(const BigNumber& big_num);
  void Print() const;
  char* get_p_val() const { return val; }
};

BigNumber::BigNumber(const unsigned int digit){
  this->val = new char[digit+2];
  this->digit = digit;
  for(int i=0;i<=(this->digit+1);i++){
    this->val[i] = 0;
  }
}

BigNumber::BigNumber(const unsigned int digit, const char* val){
  this->val = new char[digit+2];
  this->digit = digit;
  for(int i=0;i<=(this->digit+1);i++){
    this->val[i] = 0;
  }
  strncpy(this->val,val,digit+2);
}

BigNumber::~BigNumber(){
  delete[] val;
}

void BigNumber::Print() const{
  for(int i=(this->digit);i>=0;i--){
    if(this->val[i]!=0) printf("%c",this->val[i]);
  }
}

void BigNumber::Set(const char* num){
  for(int i=0;i<=(this->digit+1);i++){
    this->val[i] = 0;
  }
  strncpy(this->val,num,digit+2);
}

void BigNumber::Set(const BigNumber& big_num){
 this->Set(big_num.get_p_val());
}

void BigNumber::Add(const char* num){
  for(int i=0,carry=0;;i++){
    if(num[i]!='\0') {
      if(this->val[i]==0) this->val[i]=num[i];
      else this->val[i] += (num[i]-'0');
    }
    if(carry==1){
      if(this->val[i]==0) this->val[i]='1';
      else this->val[i]++;
      carry=0;
    }
    if(this->val[i]>'9'){ // carry 발생
      carry=1;
      this->val[i] -= 10;
    } else if(num[i]=='\0') break;
  }
}

void BigNumber::Add(const BigNumber& num){
  this->Add(num.get_p_val());
}

void Combi(int N, int R, BigNumber* store_class){
  static char ComboStore[101][101][101]={0};
  if(N<2 || R<1 || N==R) {
    store_class->Set("1");
    strcpy(ComboStore[N][R],"1");
  }else{
    BigNumber combi_num(100);
    BigNumber combi_num2(100);
    if(ComboStore[N-1][R-1][0]==0) Combi(N-1,R-1,&combi_num);
    else combi_num.Set(ComboStore[N-1][R-1]);
    if(ComboStore[N-1][R][0]==0) Combi(N-1,R,&combi_num2);
    else combi_num.Set(ComboStore[N-1][R]);
    combi_num.Add(combi_num2);
    store_class->Set(combi_num);
    strncpy(ComboStore[N][R],store_class->get_p_val(),sizeof(ComboStore[N][R]));
  }
}

int main(){
  int N, R;
  BigNumber result(100);
  scanf("%d%d",&N,&R);
  Combi(N,R,&result);
  result.Print();
  return 0;
}