#include <iostream>

int main(){
    int price, count, money;
    std::cin >> price >> count >> money;
    if(money>=price*count){
        std::cout << 0;
    }else{
        std::cout << price*count-money;
    }
    
    return 0;
}