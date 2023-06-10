#ifndef AI_H
#define AI_H
//#include <netpan.h>
#include <algorithm>
#include <QDebug>
#include <QRandomGenerator>
class AI
{
public:
   //static constexpr int length = 13;

   AI();
    virtual int AImakeMove( int board1[13][13],int player,int le1);
    //virtual int AImakeMove(int &row, int &col, int board[length][length]);
     int row=0;
     int col=0;
    //这个不知道是否必要

    virtual ~AI() {}

private:
    //int depth1=4; // 搜索深度，我们自己赋一个值4/5都行,这可能有问题，注意全局变量
    int maxPlayer=-1; // 最大玩家，ai
    int minPlayer=1; // 最小玩家，人
    //int player;
    int board[13][13];
    int flag0[9][9]={0};
    //int length=9;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    const int INF = 0x3f3f3f3f;
    const int EMPTY = 0;
    //static int row=0,col=0;
   //int (&b)[length][length];
    int MAX=1;
    int MIN=-1;
    int copy_Qi[13][13];
    //int copy_qi[13][13];
    int step[4][2]={0,1,1,0,0,-1,-1,0};
    int length=0;
    int globestRow=1;
    int globestCol=1;
    //int ji=0;

    int evaluate(int now_player); // 估值函数
    bool isValid(int x, int y);//判断合法
    int getLiberty(int i, int j) ;//气数判定
    int MiniMax( int player, int depth, int alpha, int beta); // MiniMax算法
    bool judge();
    void dfs(int x,int y,int flag);
    int getPotential(int x, int y, int player);
    enum Chess
    {
        black_loseQi_or_unchecked = -1,empty_unchecked,white_loseQi_or_unchecked,empty_checked,white_have_Qi,black_have_Qi
    }chess;
};
/*enum Player_state
{
    black_player=-1,white_player =1
}player_state;*/
#endif



