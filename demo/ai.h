#ifndef AI_H
#define AI_H
//#include <netpan.h>
#include <algorithm>
#include <QDebug>
#include <QRandomGenerator>
class AI
{
public:

   AI();
    virtual int AImakeMove( int board1[13][13],int player,int le1);//ai落子函数
    virtual ~AI() {}
    void clear();
private:
    int maxPlayer=-1; // 最大玩家，ai
    int minPlayer=1; // 最小玩家，人
    int while_times=0;//循环次数，为了防止循环过多次导致耗时过多，我们在循环到一定阙值时返回随机数
    int board[13][13];//定义棋盘
    int flag0[13][13]={0};//标志棋盘，搜索过程中若该位置不合法或下完导致输，flag0置1，该处禁止落子
    int dx[4] = {-1, 0, 1, 0};//这两行为遍历上下左右四个位置
    int dy[4] = {0, 1, 0, -1};//同上
    const int INF = 0x3f3f3f3f;//最大值
    const int EMPTY = 0;//对标空=0
    int MAX=1;//对标白=1
    int MIN=-1;//对标黑=-1
    int copy_Qi[13][13];//dfs用复制棋盘
    int step[4][2]={0,1,1,0,0,-1,-1,0};//dfs内部用遍历上下左右4个方位
    int length=0;//传入棋盘大小
    int globestRow=1;//最佳行号
    int globestCol=1;//最佳列号


    int evaluate(int now_player); // 估值函数
    bool isValid(int x, int y);//判断合法
    int getLiberty(int i, int j) ;//气数判定
    int MiniMax( int player, int depth, int alpha, int beta); // MiniMax算法
    bool judge();//judge见pan
    void dfs(int x,int y,int flag);//dfs见pan
    int getPotential(int x, int y, int player);//j计算潜力函数

    enum Chess//dfs用
    {
        black_loseQi_or_unchecked = -1,empty_unchecked,white_loseQi_or_unchecked,empty_checked,white_have_Qi,black_have_Qi
    }chess;
};

#endif



