
#include <cstdio>
#include <algorithm> //c++
using namespace std;
int card[100001];
int serch[100001]; 

//a[0], a[1], ... a[9]를 오름차순으로 정렬하고 싶으면,sort(a,a+10); 라 호출하면 됩니다.

 
bool twoserch(int left, int right, int serchnum){
    
int mid = (left + right) / 2;
    bool result;

    if (left > right || right<0)
        return false;
    else 
{
        if (card[mid] > serchnum){
            result = twoserch(left, mid - 1, serchnum);
        }
        else if (card[mid] < serchnum)
        {
            result = twoserch(mid + 1, right, serchnum);
        }
        else
{
            return true;
        }
   }
}
 
int main(void){
 
 
    int N, M;
 
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++)
        scanf("%d", &card[i]);
 
    scanf("%d", &M);
 
    for (int i = 0; i < M; i++)
        scanf("%d", &serch[i]);
 
    sort(card, card + N);
 
    for (int i = 0; i < M; i++){
        
int searchNum = serch[i];
        int left = 0, right = N - 1;
        int mid;
     
        if (twoserch(left, right, searchNum))
            printf("1\n");
        else
            printf("0\n");
    }
 
 
    return 0;
}
