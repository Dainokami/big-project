#include "ai.h"

AI::AI()
{

}

int AI::AImakeMove(int board1[13][13],int player,int len)
//计算落子点坐标
{   length=len;
    //int row=0;
    //int col=0;
    //int* bestRow, bestCol;
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            board[i][j]=board1[i][j];
        }
    }
    globestRow = -1;
    globestCol = -1;
    while_times=0;//循环次数，为了防止循环过多次导致耗时过多，我们在循环到一定阙值时返回随机数
    while(true)
    {
        MiniMax(player, 2, -INF, INF);
        if(board1[globestRow][globestCol] == 0)
        {
            qDebug()<<while_times<<"使用ai"<<100*globestRow+globestCol;;
            return 100*globestRow+globestCol;
        }
        else
        {
            globestRow = QRandomGenerator::global()->bounded(length-1);
            globestCol = QRandomGenerator::global()->bounded(length-1);
            qDebug()<<"使用随机数"<<100*globestRow+globestCol;
            return 100*globestRow+globestCol;
        }
    }
}



bool AI::isValid(int x, int y)
//判断落子合法
{

    if (x < 0 || x >=length || y < 0 || y >= length || board[x][y] != EMPTY||flag0[x][y]==1) {
            return false;
        }
        return true;
}

int AI::getLiberty(int i, int j)
//计算周围气数
{
    int liberty = 0;
       if (isValid(i - 1, j)) ++liberty;
       if (isValid(i + 1, j)) ++liberty;
       if (isValid(i, j - 1)) ++liberty;
       if (isValid(i, j + 1)) ++liberty;
       return liberty;


}


int AI::getPotential(int x, int y, int player)
{
    int potential = 0;

    // 判断给定位置是否有形成连子的潜力
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 判断相邻位置是否有相同颜色的棋子且在相同方向上存在空位
        if (isValid(nx, ny) && board[nx][ny] == player && isValid(x - dx[i], y - dy[i]) && board[x - dx[i]][y - dy[i]] == EMPTY)
        {
            potential++;
        }
    }

    // 判断给定位置周围的空位数量，作为占领地盘的潜力
    int emptyCount = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny) && board[nx][ny] == EMPTY)
        {
            emptyCount++;
        }
    }
    potential += emptyCount;

    return potential;
}

void AI::clear()
{
    for(int i=0;i<13;i++)
        for(int j=0;j<13;j++)
            flag0[i][j]=0;
    MAX=1;
    MIN=-1;
}

bool AI::judge()
{
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            copy_Qi[i][j] =board[i][j];
        }

    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            if(copy_Qi[i][j] == empty_unchecked)
                dfs(i,j,-1);
        }

    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            if(copy_Qi[i][j] == white_loseQi_or_unchecked)
                return false;
            else if(copy_Qi[i][j] == black_loseQi_or_unchecked)
                return false;
        }//检查一遍子棋盘，康康有没有棋子没气了
    return true;
}

void AI::dfs(int x, int y,int flag)
//本质是通过dfs重新绘制一副棋盘，从未落子处开始，从未落子进入黑棋部分则是有气，从有气的黑棋进入为检查的黑棋也是有气，白棋同理。
//flag是指上一个坐标是如何进入现在的坐标的，即二维数组step的第一维，flag=-1一位这个坐标是直接从judge传来的未落子坐标
{
    if(copy_Qi[x][y] == empty_unchecked && flag == -1)
    {
        copy_Qi[x][y] = empty_checked;
        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<length && y+step[i][1]>=0 && y+step[i][1]<length && copy_Qi[x+step[i][0]][y+step[i][1]] != empty_unchecked && copy_Qi[x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);}
        return;
    }

    if(board[x][y] == white_loseQi_or_unchecked)
    {
        if(board[x-step[flag][0]][y-step[flag][1]] == empty_unchecked)
        {
            copy_Qi[x][y] = white_have_Qi;
        }
        else if(copy_Qi[x-step[flag][0]][y-step[flag][1]] == white_have_Qi)
        {
            copy_Qi[x][y] = white_have_Qi;
        }
        else
            return;

        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<length && y+step[i][1]>=0 && y+step[i][1]<length && (i+2)%4 !=flag && copy_Qi[x+step[i][0]][y+step[i][1]] != empty_checked && copy_Qi[x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);}
        return;
    }
    if(board[x][y] == black_loseQi_or_unchecked)
    {
        if(board[x-step[flag][0]][y-step[flag][1]] == empty_unchecked)
        {
            copy_Qi[x][y] = black_have_Qi;
        }
        else if(copy_Qi[x-step[flag][0]][y-step[flag][1]] == black_have_Qi)
        {
            copy_Qi[x][y] = black_have_Qi;
        }
        else
            return;

        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<length && y+step[i][1]>=0 && y+step[i][1]<length && (i+2)%4 !=flag && copy_Qi[x+step[i][0]][y+step[i][1]] != empty_checked && copy_Qi[x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);}
        return;
    }



}

int AI::evaluate(int now_player)
//估值函数
{
    int score = 0;
       int maxScore = 0;
       int minScore = 0;
       int maxPlayerCount = 0;
       int minPlayerCount = 0;

       for (int i = 0; i < length; i++) {
           for (int j = 0; j < length; j++) {
               if (board[i][j] == now_player) {
                   int stoneScore = getLiberty(i, j);
                   score += stoneScore;
                   maxScore = std::max(maxScore, stoneScore);
                   maxPlayerCount++;
               } else if (board[i][j] == -now_player) {
                   int oppStoneScore = getLiberty(i, j);
                   score -= oppStoneScore;
                   minScore = std::max(minScore, oppStoneScore);
                   minPlayerCount++;
               }
           }
       }

       if (maxPlayerCount == 0 && minPlayerCount == 0) {
           return 0;
       } else if (minPlayerCount == 0) {
           return INF;
       } else if (maxPlayerCount == 0) {
           return -INF;
       } else if (maxScore >= 3 && minScore == 1) {
           return INF;
       } else if (minScore >= 3 && maxScore == 1) {
           return -INF;
       }

       return score;
}


int AI::MiniMax(int player, int depth, int alpha, int beta)
{
    while_times++;
    if(while_times>=5000)
    {
        return 0;
    }

    if (depth == 0) {
          return evaluate(player);
      }
      int bestScore;
      if (player == maxPlayer) {
          bestScore = -INF;
          for (int i = 0; i < length; i++) {
              for (int j = 0; j < length; j++) {
                    while_times++;
                  if (isValid(i, j))
                  {
                      board[i][j] = player;
                      if(!judge())
                      {
                        board[i][j] = EMPTY;
                        flag0[i][j]=1;
                        break;
                      }
                      int score = MiniMax(minPlayer, depth - 1, alpha, beta);
                      board[i][j] = EMPTY;
                      if (score > bestScore)
                      {
                          bestScore = score;
                          globestRow = i;
                          globestCol = j;
                      }
                      alpha = std::max(alpha, bestScore);
                      if (beta <= alpha)
                      {
                          break;
                      }
                  }
              }
          }
      } else {
          bestScore = INF;
          for (int i = 0; i < length; i++) {
              for (int j = 0; j < length; j++) {
                    while_times++;
                  if (isValid(i, j)) {
                      board[i][j] = player;
                      if(!judge())
                      {board[i][j] = EMPTY;
                          flag0[i][j]=1;
                          break;
                      }
                      int score = MiniMax(maxPlayer, depth - 1, alpha, beta);
                      board[i][j] = EMPTY;
                      if (score < bestScore) {
                          bestScore = score;
                          globestRow = i;
                          globestCol = j;
                      }
                      beta = std::min(beta, bestScore);
                      if (beta <= alpha) {
                          break;
                      }
                  }
              }
          }
      }

      return bestScore;


}





