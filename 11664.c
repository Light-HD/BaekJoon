#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double ans;
typedef struct{
    int x, y, z;
}Point;
Point A, B, C;
double Distance(Point a, Point b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}
void InputData()
{
    scanf("%d %d %d %d %d %d %d %d %d", &A.x, &A.y, &A.z, &B.x, &B.y, &B.z, &C.x, &C.y, &C.z);
}
void OutputData()
{
   printf("%.10lf\n", ans);
}

void Solve()
{
    double a = Distance(A, B);
    double b = Distance(B, C);
    double c = Distance(C, A);

    double s = (a + b + c) / 2;
    double S = sqrt(s*(s - a)*(s - b)*(s - c));

    if(c > a && c > b) {
        int obtuse = pow(a, 2) + pow(b, 2) < pow(c, 2);
        if(obtuse) {
            ans = b;
            return;
        }
    }
    if(b > a && b > c) {
        int obtuse = pow(a, 2) + pow(c, 2) < pow(b, 2);
        if(obtuse) {
            ans = c;
            return;
        }
    }
    if(S == 0){
        if(a > c && a > b) ans = 0;
        else ans = b < c ? b : c;
        return;
    }
    ans = (2 * S) / a;
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}
