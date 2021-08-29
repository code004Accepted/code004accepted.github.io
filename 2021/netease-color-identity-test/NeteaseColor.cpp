#include <iostream>
#include <cstdio>
using namespace std;
/*
绿=1
橙=2
银=3
紫=4
蓝=5
金=6
粉=7
*/
int score[8] = { 0 };
int doublecolor[10][3] = {
    {0,0,0},
    {0,7,6},
    {0,6,2},
    {0,7,4},
    {0,6,5},
    {0,6,4},
    {0,2,7},
    {0,5,7},
    {0,6,1},
    {0,2,1}
};
int doublescore[10] = { 0 };
void addscore(int problemid, int ans)
{
    if (problemid == 1 && ans == 1)
        score[6]++, score[1]++;
    if (problemid == 1 && ans == 2)
        score[4]++, score[3]++, score[2]++;
    if (problemid == 1 && ans == 3)
        score[7]++, score[5]++;

    if (problemid == 2 && ans == 1)
        score[5]++, score[4]++;
    if (problemid == 2 && ans == 2)
        score[7]++, score[2]++;
    if (problemid == 2 && ans == 3)
        score[3]++, score[6]++, score[1]++;

    if (problemid == 3 && ans == 1)
        score[3]++, score[4]++, score[2]++;
    if (problemid == 3 && ans == 2)
        score[5]++, score[1]++;
    if (problemid == 3 && ans == 3)
        score[6]++, score[7]++;

    if (problemid == 4 && ans == 1)
        score[3]++, score[2]++;
    if (problemid == 4 && ans == 2)
        score[4]++, score[6]++, score[1]++;
    if (problemid == 4 && ans == 3)
        score[7]++, score[5]++;

    if (problemid == 5 && ans == 1)
        score[1]++, score[4]++;
    if (problemid == 5 && ans == 2)
        score[2]++, score[7]++;
    if (problemid == 5 && ans == 3)
        score[3]++, score[6]++, score[5]++;

    if (problemid == 6 && ans == 1)
        score[1]++, score[4]++, score[3]++;
    if (problemid == 6 && ans == 2)
        score[5]++, score[2]++;
    if (problemid == 6 && ans == 3)
        score[6]++, score[7]++;

    if (problemid == 7 && ans == 1)
        score[1]++, score[6]++, score[4]++;
    if (problemid == 7 && ans == 2)
        score[2]++, score[7]++;
    if (problemid == 7 && ans == 3)
        score[3]++, score[5]++;

    if (problemid == 8 && ans == 1)
        score[4]++, score[2]++, score[1]++, score[3]++;
    if (problemid == 8 && ans == 2)
        score[5]++, score[6]++, score[7]++;

    return;
}
void result(int switcher)
{
    bool book[8] = { false }, marked = false;
    for (int i = 1; i <= 7; i++)
    {
        if (!book[score[i]])
            book[score[i]] = true;
        else
        {
            marked = true;
            break;
        }
    }
    if (marked) //有重合分值
        addscore(8, switcher);
    /**/
    //好奇看看处理后有无重复分值而已，不影响最终判断
    memset(book, false, sizeof(book));
    marked = false;
    for (int i = 1; i <= 7; i++)
    {
        if (!book[score[i]])
            book[score[i]] = true;
        else
        {
            marked = true;
            break;
        }
    }
    if (marked) //还有重合分值
        printf("[ERR]Same scores still\n");
    /**/
    if (switcher == 1)//双色
    {
        int maxcount = 0, maxrecord = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (score[doublecolor[i][1]] == 0 || score[doublecolor[i][2]] == 0)
                continue;
            doublescore[i] = score[doublecolor[i][1]] + score[doublecolor[i][2]];
            if (maxcount < doublescore[i])
            {
                maxcount = doublescore[i];
                maxrecord = i;
            }
            else if (maxcount == doublescore[i])
            {
                printf("[DoubleERR]Same score on #%d(%d,%d) and #%d(%d,%d) (Score: %d)\n", maxrecord, doublecolor[maxrecord][1], doublecolor[maxrecord][2], i, doublecolor[i][1], doublecolor[i][2], maxcount);
                for (int tester = 1; tester<=7; tester++)
                {
                    printf("%d,",score[tester]);
                }
                printf("\n");
                //maxrecord = i;
            }
        }
        printf("Double: %d & %d (TotalScore: %d)\n", doublecolor[maxrecord][1], doublecolor[maxrecord][2], maxcount);
    }
    if (switcher == 2)//单色
    {
        int maxcount = 0, maxrecord = 0;
        for (int i = 1; i <= 7; i++)
        {
            if (maxcount < score[i])
            {
                maxcount = score[i];
                maxrecord = i;
            }
            else if (maxcount == score[i])
            {
                printf("[SingleERR]Same score on %d and %d (Score: %d)\n", maxrecord, i, maxcount);
                //maxrecord = i;
            }
        }
        printf("Single: %d (Score: %d)\n", maxrecord, maxcount);
    }
    return;
}
int main()
{
    //printf("%d", doublecolor[1][1]); //测试数组是否正常配置
    freopen("results.txt", "w", stdout);
    for (int ans1 = 1; ans1 <= 3; ans1++)
    {
        for (int ans2 = 1; ans2 <= 3; ans2++)
        {
            for (int ans3 = 1; ans3 <= 3; ans3++)
            {
                for (int ans4 = 1; ans4 <= 3; ans4++)
                {
                    for (int ans5 = 1; ans5 <= 3; ans5++)
                    {
                        for (int ans6 = 1; ans6 <= 3; ans6++)
                        {
                            for (int ans7 = 1; ans7 <= 3; ans7++)
                            {
                                for (int ans8 = 1; ans8 <= 2; ans8++)
                                {
                                    memset(score, 0, sizeof(score));
                                    addscore(1, ans1);
                                    addscore(2, ans2);
                                    addscore(3, ans3);
                                    addscore(4, ans4);
                                    addscore(5, ans5);
                                    addscore(6, ans6);
                                    addscore(7, ans7);
                                    addscore(8, ans8);
                                    result(ans8);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Completed.\n");
    freopen("CON", "w", stdout);
    printf("Completed.\n");
    return 0;
}
