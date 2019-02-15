#import<iostream>
main(int A,int B,int C){std::cin>>A>>B>>C;std::cout<<((A>B?A:B)>C?((A<B?A:B)>C?(A<B?A:B):C):(A>B?A:B));}