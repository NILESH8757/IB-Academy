// gonna make a GUI project on this someday ;), enjoyed solving it.
// Can be pruned more effectively, by not calculating all moves beforehand
/*
   sample test input:
      53..7....
      6..195...
      .98....6.
      8...6...3
      4..8.3..1
      7...2...6
      .6....28.
      ...419..5
      ....8..79
      
   sample test output:
      534678912
      672195348
      198342567
      859761423
      426853791
      713924856
      961537284
      287419635
      345286179
      
*/

//utility function to check half filled (isDone == false) or complete filled (isDone == true) sudoku board is valid or not
bool isValidSudoku(vector<vector<char> > &board, bool isDone)
{
  bool r[9][9], c[9][9], s[3][3][9];
  memset(r, false, sizeof(r));
  memset(c, false, sizeof(c));
  memset(s, false, sizeof(s));
  
  int number;
  
  for (int i = 0; i < 9; i++) 
  {
    for (int j = 0; j < 9; j++) 
    {
      if (board[i][j] > '0' && board[i][j] <='9') 
      {
        number = board[i][j] - '1';
        //check row
        if (r[i][number]) 
          return false;
        r[i][number] = true;
        
        //check column
        if (c[j][number]) 
           return false;
        c[j][number] = true;
        
        // check 3x3 sub-sudoku
        if (s[i / 3][j / 3][number]) 
           return false;
        s[i / 3][j / 3][number] = true;
      }
      else
      {
         if(isDone)
           return false;
      }
    }
  }
  
  return true;
}

//utility function to get all possible moves for a position (x, y)
vector<char> getMoves(vector<vector<char> > &A, int x, int y)
{
   vector<bool> vis(10, true);
   vector<char> moves;

   for(int i = 0; i < 9; i++)
   {
      if(A[i][y] > '0' && A[i][y] <= '9')
      {
         int num = A[i][y] - '0';
         vis[num] = false;
      }
   }
   
   for(int j = 0; j < 9; j++)
   {
     if(A[x][j] > '0' && A[x][j] <= '9')
     {
        int num = A[x][j] - '0';
        vis[num] = false;
     }
   }

   int sx = (x/3) * 3, sy = (y/3) * 3;
   
   for(int i = sx; i < sx + 3; i++)
   {
     for(int j = sy; j < sy + 3; j++)
     {
        if(A[i][j] > '0' && A[i][j] <= '9')
        {
          int num = A[i][j] - '0';
          vis[num] = false;
        }
     }
   }

   for(int i = 1; i < 10; i++)
     if(vis[i])
      moves.push_back('0' + i);

   return moves;
}

// function which does all the work
void sudokuSolver(vector<vector<char> > &A, vector<pair<int,int> > &toFill, vector<vector<vector<char> > > &moves, int cur, bool &done)
{
   if(cur == toFill.size())
   {
      if(isValidSudoku(A, true))
      {
         done = true;
      }
      return;
   }

   int i = toFill[cur].first;
   int j = toFill[cur].second;

   for(char c : moves[i][j])
   {
     A[i][j] = c;

     if(isValidSudoku(A, false))
     {
        sudokuSolver(A, toFill, moves, cur + 1, done);

        if(done)
         return;
        else
         A[i][j] = '.'; 
     }
     else
     {
        A[i][j] = '.';
     }
   }
   
   if(A[i][j] == '.')
     return;
}


void solveSudoku(vector<vector<char> > &A) // call this function with input array from main()
{
    vector<vector<vector<char> > > allMoves(9, vector<vector<char> >(9));
    vector<pair<int,int> > indexToFill;

    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
      {
         if(A[i][j] == '.')
         {
             indexToFill.push_back({i, j});
             vector<char> moves = getMoves(A, i, j);
             allMoves[i][j] = moves;
         }
      }
    }
    
    bool done = false;
    int cur = 0; 
    sudokuSolver(A, indexToFill, allMoves, cur, done);
}
