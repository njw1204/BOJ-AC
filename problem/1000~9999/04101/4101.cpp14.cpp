#include <iostream>

int main(){
    while(1){
        int A, B;
        std::cin >> A >> B;
        if(A==0) break;
        
        if(A>B) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}