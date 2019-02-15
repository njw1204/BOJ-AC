#include <stdio.h>
int main (){
    char a[101];
    int i;
    scanf("%s",a);
    for(i=0;a[i]!=NULL;i++){
       
        printf("%c",a[i]);
        if(i % 10 ==9)
        {printf("\n");}
       
       
    }
    return 0;
}

