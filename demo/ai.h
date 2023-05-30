#ifndef AI_H
#define AI_H
//#include <netpan.h>
#include <algorithm>
class AI
{
public:
    int length = 9;

    AI();
    /*AI(int (&b)[length][length], int MAX, int MIN) : depth(4), maxPlayer(MAX), minPlayer(MIN) {

         for(int i=0;i<length;i++){
               for(int j=0;j<length;j++){
                   board[i][j] = b[i][j];
               }
           }
     }*/
<<<<<<< HEAD
    virtual int AImakeMove(int Board[13][13],int Maxplayer,int Minplayer,int Length);
=======
    virtual int AImakeMove( int board[length][length],int player);
>>>>>>> 44d386abdd9f81d582d30b32044ec42b29141922
    //virtual int AImakeMove(int &row, int &col, int board[length][length]);
    int row;
    int col;
    //这个不知道是否必要

    virtual ~AI() {}

private:
    int depth=4; // 搜索深度，我们自己赋一个值4/5都行,这可能有问题，注意全局变量
    int maxPlayer; // 最大玩家，ai
    int minPlayer; // 最小玩家，人
<<<<<<< HEAD
    int board[13][13];
=======
    int player;
    int board[length][length];
>>>>>>> 44d386abdd9f81d582d30b32044ec42b29141922
    //int length=9;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    const int INF = 0x3f3f3f3f;
    const int EMPTY = 0;
<<<<<<< HEAD
    int evaluate(int Player); // 估值函数
=======
    int (&b)[length][length];
    int MAX=1;
    int MIN=-1;
    int evaluate(int board[length][length]); // 估值函数
>>>>>>> 44d386abdd9f81d582d30b32044ec42b29141922
    bool isValid(int x, int y);//判断合法
    int getLiberty(int i, int j) ;//气数判定
    int MiniMax(int player, int Depth, int alpha, int beta, int &bestRow, int &bestCol); // MiniMax算法
};
#endif



