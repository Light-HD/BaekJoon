#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000000)
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

int ans;
int d, num;
int x, y;
typedef struct {
    int num, flag;
}Data;
void InputData()
{
    scanf("%d %d", &d, &num);
    scanf("%d %d", &x, &y);
}
void OutputData()
{
   printf("%d\n", ans);
}
Data calc(int cur, int d){
    int num = 0, flag = 0;
    switch(cur){
        case 1 :
        if(d == RIGHT){
            
        }
        break;
    }
}
void Solve()
{
    //32 -> 31 -> 42 -> 41
    //33 -> 34 -> 43 -> 44
    //33 -> 32 -> 23 -> 22
    //43 -> 42 -> 13 -> 12

    //332 -> 331 -> 342 -> 341 -> 432

}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}
