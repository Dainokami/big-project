#include "ai.h"

AI::AI(int board[][9],int MAX,int MIN,int &LE)
{
    this->setPlayer(now_player);
    this->depth = depth;
    this->maxPlayer = MAX;
    this->minPlayer = MIN;
    for(int i=0;i<length;i++){
         for(int j=0;j<length;j++){
             this->board[i][j] = board[i][j];
         }
     }
}

int AI::AImakeMove(int board[length][length])
//计算落子点坐标
{
    int &row=0;
    int &col=0;
    int bestRow, bestCol;
    MiniMax(board, this->getPlayer(), this->depth, -INF, INF, bestRow, bestCol);
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
int AI::getLiberty(int board[][length],int i, int j)
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
}

int AI::evaluate(int board[][length], int player)
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
                        if (board[x][y] == maxPlayer)
                        {
                            emptyScore += getLiberty(board, x, y);
                        }
                        else
                        {
                            emptyScore -= getLiberty(board, x, y);
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
                        stoneScore += getLiberty(board, i, j);
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
                        oppStoneScore -= getLiberty(board, x, y);
                    }
                }
                score += oppStoneScore;
            }
        }
    }
    return score;
}


int AI::MiniMax(int board[length][length], int player,int depth, int alpha, int beta, int &bestRow, int &bestCol)
{
    //minmax算法
    if (depth == 0 || isGameOver(board))
    {
        return evaluate(board, this->maxPlayer);
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
                    int score = MiniMax(board, this->minPlayer, depth - 1, alpha, beta, bestRow, bestCol);
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
                    int score = MiniMax(board, this->maxPlayer, depth - 1, alpha, beta, bestRow, bestCol);
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

