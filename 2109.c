#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (10010)
int ans, max;
int N;
typedef struct{
    int p, d;
}University;
University uni[MAXN];
int ck[MAXN];
void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int d,p;
        scanf("%d %d", &p, &d);
        max = max > d ? max : d;
        University u = {p, d};
        uni[i] = u;
    }
    
}
void OutputData()
{
   printf("%d\n", ans);
}
int Compare(const void* a, const void* b){
    int first = ((University*)b)->p - ((University*)a)->p;
    int second = ((University*)a)->d - ((University*)b)->d;
    return first == 0 ? second : first;
}
void Solve()
{
    qsort(uni, N, sizeof(uni[0]), Compare);

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        int p = uni[i].p;
        int d = uni[i].d;
        //d일부터 내려가면서 빈공간에 스케줄 넣기
        for (int j = d; j >= 1; j--)
        {
            if(!ck[j]){
                sum += p;
                ck[j] = 1;
                break;
            }
        }
    }
    ans = sum;
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}
