
using namespace std;

class game
{
public:
    void displayGuidelines()
    {
        cout << endl;
        cout << "In Sudoku, each number must appear exactly once in every row, column, and 3x3 sub-grid. It's a game that demands strategy and careful thinking to solve." << endl;
        cout << endl;

        cout << "Good luck and enjoy the challenge!" << endl;
    }
};

class Sudoku
{
public:
    int grid[9][9];

    Sudoku();
    void fillRandomCells(int numCells);
    void printGrid();
    bool solveGrid();
    bool isSafe(int row, int col, int num);
};

class Player
{
private:
    string username;
    string password;

public:
    Player() : username(""), password("") {}

    Player(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    string getUsername() const
    {
        return username;
    }

    string getPassword() const
    {
        return password;
    }
};

bool loginUser(const string &username, const string &password, const Player players[], int size);
void savePlayerData(const Player &player);

Player players[100];
int playerCount = 0;

int genRandNum(int maxLimit)
{
    return rand() % maxLimit;
}

bool FindUnassignedLocation(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == UNASSIGNED)
                return true;
        }
    }
    return false;
}

bool UsedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

bool Sudoku::isSafe(int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num);
}

Sudoku::Sudoku()
{

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            this->grid[i][j] = UNASSIGNED;
}

void Sudoku::fillRandomCells(int numCells)
{
    for (int i = 0; i < numCells; i++)
    {
        int row = genRandNum(9);
        int col = genRandNum(9);
        int num = genRandNum(9) + 1;

        if (isSafe(row, col, num))
        {
            grid[row][col] = num;
        }
        else
        {
            i--;
        }
    }
}

void Sudoku::printGrid()
{
    cout << "Current Sudoku Grid:\n";
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << "-------------------------\n";
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                cout << "| ";
            }
            if (grid[i][j] == 0)
                cout << ". ";
            else
                cout << grid[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-------------------------\n";
}

bool Sudoku::solveGrid()
{
    int row, col;

    if (!FindUnassignedLocation(this->grid, row, col))
    {
        return true; // Puzzle solved
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            this->grid[row][col] = num;

            if (solveGrid())
            {
                return true;
            }

            this->grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}

bool loginUser(const string &username, const string &password, const Player players[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (players[i].getUsername() == username && players[i].getPassword() == password)
        {
            return true;
        }
    }
    return false;
}

void savePlayerData(const Player &player)
{
    ofstream outFile("players.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << player.getUsername() << " " << player.getPassword() << "\n";
        outFile.close();
    }
    else
    {
        cerr << "Unable to save player data.\n";
    }
}

int main()
{
    
     start();
    srand(static_cast<unsigned int>(std::time(0)));

    game sudokuGame;
    sudokuGame.displayGuidelines(); 

    ifstream inFile("players.txt");
    if (inFile.is_open())
    {
        string username, password;
        while (inFile >> username >> password)
        {
            players[playerCount++] = Player(username, password);
        }
        inFile.close();
    }
    else
    {
        cerr << "Unable to load existing players.\n";
    }

    string username, password;
    int choice;
    cout << "1. Login\n2. Sign Up\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (loginUser(username, password, players, playerCount))
        {
            cout << "Login successful!\n";
        }
        else
        {
            cout << "Login failed. Invalid username or password.\n";
            return 1;
        }
    }
    else if (choice == 2)
    {
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        bool usernameExists = false;
        for (int i = 0; i < playerCount; i++)
        {
            if (players[i].getUsername() == username)
            {
                usernameExists = true;
                break;
            }
        }

        if (usernameExists)
        {
            cout << "Username already exists. Please choose a different one.\n";
            return 1;
        }

        players[playerCount++] = Player(username, password);
        savePlayerData(Player(username, password));
        cout << "Sign up successful!\n";
    }
    else
    {
        cout << "Invalid choice.\n";
        return 1;
    }

    Sudoku sudoku;
    sudoku.fillRandomCells(30);
    sudoku.printGrid();

    time_t startTime = std::time(0);
    while (true)
    {
        cout << "Enter move (row col num): ";
        int row, col, num;
        cin >> row >> col >> num;

        if (std::difftime(std::time(0), startTime) > 60)
        {
            cout << "Time's up! You didn't solve the puzzle in 1 minute.\n";
            break;
        }

        row--;
        col--;
        if (!sudoku.isSafe(row, col, num))
        {
            cout << "Invalid move, try again.\n";
            continue;
        }
        sudoku.grid[row][col] = num;
        sudoku.printGrid();
        if (sudoku.solveGrid())
        {
            sudoku.printGrid();
            cout << "Congratulations! You've solved the Sudoku puzzle!\n";
            break;
        }
    }

    return 0;
}