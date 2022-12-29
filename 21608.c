#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (21)
double ans;
int N;
typedef struct{
    int r, c;
}Point;
typedef struct{
    int num;
    int likearr[MAXN * MAXN];
}Student;
Point locs[MAXN * MAXN];
Student students[MAXN * MAXN];
int map[MAXN][MAXN];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void InputData()
{
    scanf("%d", &N);
    for (int i = 1; i <= N * N; i++)
    {
        Student std;
        
        memset(std.likearr, 0, sizeof(std.likearr));

        scanf("%d", &std.num);
        for (int j = 0; j < 4; j++)
        {
            int k = 0;
            scanf("%d", &k);
            std.likearr[k] = 1;
        }
        students[i] = std;
    }
}
void OutputData()
{
    printf("%.0lf\n", ans);
}
void Second(Point parr[], int parrcnt, int num)
{
    int max = 0;
    Point sarr[MAXN * MAXN];
    int sarrcnt = 0;

    //parr에 있는 위치 중 주변에 비어있는 칸 수 세기
    for (int i = 0; i < parrcnt; i++)
    {
        int cnt = 0;
        
        int r = parr[i].r;
        int c = parr[i].c;

        //4방위 탐색
        for (int j = 0; j < 4; j++)
        {
            int nr = r + dr[j];
            int nc = c + dc[j];

            if(nr < 1 || nc < 1 || nr > N || nc > N) continue; //경계조건
            if(map[nr][nc]) continue; //비어있지 않은 칸
            cnt++;
        }

        //max 갱신
        if(max < cnt){
            max = cnt;
            sarrcnt = 0;
            sarr[sarrcnt].r = r;
            sarr[sarrcnt].c = c;
            sarrcnt++;
        }

        //동일 조건
        else if (max == cnt) {
            sarr[sarrcnt].r = r;
            sarr[sarrcnt].c = c;
            sarrcnt++;
        }
    }
    int r = sarr[0].r;
    int c = sarr[0].c;
    map[r][c] = num;
    locs[num].r = r;
    locs[num].c = c;
}

void First(Student std)
{
    int max = -1;
    Point parr[MAXN * MAXN];
    int parrcnt = 0;

    // 비어 있는 칸 중 좋아하는 학생이 인접한 칸 개수 세기
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            if(map[r][c]) continue;

            int cnt = 0;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 1 || nc < 1 || nr > N || nc > N) continue;
                if(std.likearr[map[nr][nc]]) cnt++;
            }
            
            if(max < cnt) {
                max = cnt;
                parrcnt = 0;
                parr[parrcnt].r = r;
                parr[parrcnt].c = c;
                parrcnt++;
            }
            else if (max == cnt) {
                parr[parrcnt].r = r;
                parr[parrcnt].c = c;
                parrcnt++;
            }
        }
    }

    if(parrcnt > 1)
    {
        Second(parr, parrcnt, std.num);
    }
    else 
    {
        int r = parr[0].r;
        int c = parr[0].c;
        map[r][c] = std.num;
        locs[std.num].r = r;
        locs[std.num].c = c;
    }
}
void Satisfaction(Student std, int r, int c)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 1 || nc < 1 || nr > N || nc > N) continue;

        if(std.likearr[map[nr][nc]]) cnt++;
    }
    if(cnt == 0) return;
    ans += pow(10, cnt-1);
}
void Solve()
{
    //학생 자리 배치
    for (int i = 1; i <= N * N; i++)
    {
        First(students[i]);
    }
    
    // 만족도 계산
    for (int i = 1; i <= N * N; i++)
    {
        Student std = students[i];
        Satisfaction(std, locs[std.num].r, locs[std.num].c);
    }
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}
