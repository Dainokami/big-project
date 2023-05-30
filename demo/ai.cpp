#include "ai.h"
AI::AI(){}


<<<<<<< HEAD

int AI::AImakeMove(int Board[13][13],int Maxplayer,int Minplayer,int Length)
=======
int AI::AImakeMove(int board[length][length],int player)
>>>>>>> 44d386abdd9f81d582d30b32044ec42b29141922
//计算落子点坐标
{
    length = Length;
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
            board[i][j] = Board[i][j];
    int row=0;
    int col=0;
    int bestRow, bestCol;
<<<<<<< HEAD
    maxPlayer = Maxplayer;
    minPlayer = Minplayer;
    MiniMax(this->maxPlayer,depth,-INF, INF, bestRow, bestCol);
=======
    MiniMax(board, player, this->depth, -INF, INF, bestRow, bestCol);
>>>>>>> 44d386abdd9f81d582d30b32044ec42b29141922
    row = bestRow;
    col = bestCol;
    return 100*row+col;
}


bool AI::isValid(int x, int y)
//判断落子合法
{
    if (this->board[x][y] != EMPTY)
    {
        return false;
    }
    for (int k = 0; k < 4; k++)
    {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if (this->board[tx][ty] == EMPTY)
        {
            return true;
        }
    }
    return false;
}
int AI::getLiberty(int i, int j)
//计算周围气数
{
    int liberty = 0;
    //int m = sizeof(board) / sizeof(board[0]), n = sizeof(board[0]) / sizeof(board[0][0]);
    if (i > 0 && board[i-1][j] == 0) ++liberty;
    if (i <= length-1 && board[i+1][j] == 0) ++liberty;
    if (j > 0 && board[i][j-1] == 0) ++liberty;
    if (j <= length-1 && board[i][j+1] == 0) ++liberty;
    return liberty;
}


<<<<<<< HEAD
int AI::evaluate(int player)
=======
int AI::evaluate(int board[][length])
>>>>>>> 44d386abdd9f81d582d30b32044ec42b29141922
//估值函数
{
    int score = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (board[i][j] == EMPTY)
            {
                int emptyScore = 0;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isValid(x, y) && board[x][y] != EMPTY)
                    {
                        if (board[x][y] == player)
                        {
                            emptyScore += getLiberty(x, y);
                        }
                        else
                        {
                            emptyScore -= getLiberty(x, y);
                        }
                    }
                }
                score += emptyScore;
            }
            else if (board[i][j] == maxPlayer)
            {
                int stoneScore = 0;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isValid(x, y) && board[x][y] == EMPTY)
                    {
                        stoneScore += getLiberty(i, j);
                    }
                }
                score += stoneScore;
            }
            else
            {
                int oppStoneScore = 0;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isValid(x, y) && board[x][y] == EMPTY)
                    {
                        oppStoneScore -= getLiberty(x, y);
                    }
                }
                score += oppStoneScore;
            }
        }
    }
    return score;
}


int AI::MiniMax(int player,int Depth,int alpha, int beta, int &bestRow, int &bestCol)
{
    //minmax算法
    if (Depth == 0 /*|| isGameOver(board)*/)
    {
<<<<<<< HEAD
        return evaluate(this->maxPlayer);
=======
        return evaluate(board);
>>>>>>> 44d386abdd9f81d582d30b32044ec42b29141922
    }

    int bestScore;
    if (player == this->maxPlayer)
    {
        bestScore = -INF;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                if (board[i][j] == 0)
                {
                    board[i][j] = player;
                    int score = MiniMax(this->minPlayer, Depth - 1, alpha, beta, bestRow, bestCol);
                    board[i][j] = 0;
                    if (score > bestScore)
                    {
                        bestScore = score;
                        bestRow = i;
                        bestCol = j;
                    }
                    alpha = std::max(alpha, bestScore);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
    }
    else
    {
        bestScore = INF;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                if (board[i][j] == 0)
                {
                    board[i][j] = player;
                    int score = MiniMax( this->maxPlayer, Depth - 1, alpha, beta, bestRow, bestCol);
                    board[i][j] = 0;
                    if (score < bestScore)
                    {
                        bestScore = score;
                        bestRow = i;
                        bestCol = j;
                    }
                    beta = std::min(beta, bestScore);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
    }

    return bestScore;
}

