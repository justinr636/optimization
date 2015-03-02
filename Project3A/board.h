// Project 3A
// 
// by Justin Ratra and Eric Dusel
// 
// board.h
// board class header file
// 

class board
// Stores the entire Sudoku board
{
   public:
	  // Constructors
      board(int);
	  
	  // Methods
      void clear();
      void initialize(ifstream &fin);
      void print();
      bool isBlank(int, int);
      ValueType getCell(int, int);
	  void setCell(int, int, int);

	  void findRowConflicts(int );
	  void findColConflicts(int );
	  void findSqrConflicts(int );

   private:

      // The following matrices go from 1 to BoardSize in each
      // dimension.  I.e. they are each (BoardSize+1) X (BoardSize+1)
      matrix<ValueType> value;

	  vector< vector<bool> > rowConflicts;
	  vector< vector<bool> > colConflicts;
	  vector< vector<bool> > sqrConflicts;
};

board::board(int sqSize)
   : value(BoardSize,BoardSize)
   , rowConflicts(BoardSize, vector<bool>(BoardSize))
   , colConflicts(BoardSize, vector<bool>(BoardSize))
   , sqrConflicts(BoardSize, vector<bool>(BoardSize))
// Board constructor
{
}

void board::clear()
{
}

void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
   char ch;

   clear();
   for (int i = 1; i <= BoardSize; i++)
   {
      for (int j = 1; j <= BoardSize; j++)
      {
		  fin >> ch;

     	  // If the read char is not Blank
	 	  if (ch != '.')
	 	  {
     	         setCell(i,j,ch-'0');   // Convert char to int
	 	  }
      }
   }
}

int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
   // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
   // coordinates of the square that i,j is in.  

   return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
   for (int i = 0; i < v.size(); i++)
      ostr << v[i] << " ";
   ostr << endl;
   return ostr;
}

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
{
   if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
      return value[i-1][j-1];
   else
      throw rangeError("bad value in getCell");
}

void board::setCell(int i, int j, int val)
// Sets a value in cell coordinates
// Throws an expection if bad values are passed
{
   if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
   {
	   value[i-1][j-1] = val;

	   // Update Conflicts
	   rowConflicts[i-1][val-1] = true;
	   colConflicts[j-1][val-1] = true;
	   sqrConflicts[squareNumber(i,j)-1][val-1] = true;
   }
   else
      throw rangeError("bad value in setCell");
}

bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
   if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
      throw rangeError("bad value in setCell");
}

void board::print()
// Prints the current board.
{
   for (int i = 1; i <= BoardSize; i++)
   {
      if ((i-1) % SquareSize == 0)
      {
          cout << " -";
		  for (int j = 1; j <= BoardSize; j++)
	 	     cout << "---";
          cout << "-";
		  cout << endl;
      }
      for (int j = 1; j <= BoardSize; j++)
      {
		  if ((j-1) % SquareSize == 0)
	 	     cout << "|";
	 	  if (!isBlank(i,j))
	 	     cout << " " << getCell(i,j) << " ";
	 	  else
	 	     cout << "   ";
      }
      cout << "|";
      cout << endl;
   }

   cout << " -";
   for (int j = 1; j <= BoardSize; j++)
      cout << "---";
   cout << "-";
   cout << endl;
}

void board::findRowConflicts(int index)
{
	vector<bool> row = rowConflicts[index];

	for (int j = 0; j < BoardSize; j++)
	{
		int num = value[index][j];
	}
}