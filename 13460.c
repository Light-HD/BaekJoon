#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (10)
int ans;
int N, M;
char map[MAXN + 10][MAXN + 10];
char ck[MAXN + 10][MAXN + 10][MAXN + 10][MAXN + 10];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
typedef struct{
    int br, bc, rr, rc, cnt;
}Point;
Point que[100000];
int wp, rp;
void push(int br, int bc, int rr, int rc, int cnt){
    Point p = {br, bc, rr, rc, cnt};
    que[wp++] = p;
}
void pop(void){
    rp++;
}
Point front(void){
    return que[rp];
}
int empty(void){
    return wp == rp;
}
void InputData()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", &map[i][1]); 
    }
}
void OutputData()
{
   printf("%d\n", ans);
}
void move(int* r, int* c, int* dist, int i){
    while(map[*r + dr[i]][*c + dc[i]] != '#' && map[*r][*c] != 'O'){
        *r += dr[i];
        *c += dc[i];
        *dist++;
    }
}
int BFS(int br, int bc, int rr, int rc){
    push(br, bc, rr, rc, 0);
    ck[br][bc][rr][rc] = 1;
    while(!empty()){
        Point p = front();
        pop();
        int br = p.br;
        int bc = p.bc;
        int rr = p.rr;
        int rc = p.rc;
        int cnt = p.cnt;
        if(cnt >= 10) break;
        for (int i = 0; i < 4; i++)
        {
            int nbr = br;
            int nbc = bc;
            int nrr = rr;
            int nrc = rc;
            int distr = 0, distb = 0;

            while(map[nrr + dr[i]][nrc + dc[i]] != '#' && map[nrr][nrc] != 'O'){
                nrr += dr[i];
                nrc += dc[i];
                distr++;
            }
            while(map[nbr + dr[i]][nbc + dc[i]] != '#' && map[nbr][nbc] != 'O'){
                nbr += dr[i];
                nbc += dc[i];
                distb++;
            }

            if(map[nbr][nbc] == 'O') continue;
            if(map[nrr][nrc] == 'O'){
                return cnt + 1;
            }
            if(nrr == nbr && nrc == nbc){
                if(distr > distb) {
                    nrr -= dr[i];
                    nrc -= dc[i];
                }
                else {
                    nbr -= dr[i];
                    nbc -= dc[i];
                }
            }
            if(ck[nbr][nbc][nrr][nrc]) continue;
            ck[nbr][nbc][nrr][nrc] = 1;
            push(nbr, nbc, nrr ,nrc, cnt + 1);
        }
    }
    return -1;
}
void Solve()
{
    int br, bc, rr, rc;
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= M; c++)
        {
            if(map[r][c] == 'B'){
                br = r;
                bc = c;
            }
            if(map[r][c] == 'R'){
                rr = r;
                rc = c;
            }
        }
        
    }
    ans = BFS(br, bc, rr, rc);
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}
