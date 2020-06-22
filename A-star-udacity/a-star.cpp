#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
};

const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰   ";
    case State::kPath:
        return "🚗   ";
    case State::kStart:
        return "🚦   ";
    case State::kFinish:
        return "🏁   ";
    default:
        return "0   ";
    }
}

void const PrintBoard(vector<vector<State>> board)
{
    for (auto const row : board)
    {
        for (auto const cell : row)
        {
            cout << CellString(cell);
        }
        cout << "\n";
    }
}

vector<State> ParseLine(string line)
{
    char c = ',';
    int n;
    vector<State> vec;

    istringstream line_stream(line);
    while (line_stream >> n >> c)
    {
        if (n == 0)
            vec.push_back(kEmpty);
        else
            vec.push_back(kObstacle);
    }

    return vec;
}

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myfile(path);
    vector<vector<State>> board{};
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

const int Heuristic(int x1, int y1, int x2, int y2)
{
    return std::abs(x2 - x1) + std::abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openNodes, vector<vector<State>> &board)
{
    vector<int> node = {x, y, g, h};
    openNodes.push_back(node);
    board[x][y] = kClosed;
}

bool Compare(vector<int> n1, vector<int> n2)
{
    int n1_f = n1[2] + n1[3];
    int n2_f = n2[2] + n2[3];

    return (n1_f > n2_f);
}

void CellSort(vector<vector<int>> *v)
{
    sort(v->begin(), v->end(), Compare);
}

bool checkValidCell(int x, int y, vector<vector<State>> &board)
{
    bool isInsideGrid = (x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size());

    if (isInsideGrid)
    {
        bool isUnvisited = board[x][y] == kEmpty;
        return isUnvisited;
    }
    return false;
}

void ExpandNeighbors(vector<int> &currentNode, vector<vector<int>> &openNodes, vector<vector<State>> &board, int goal[2])
{
    int x = currentNode[0];
    int y = currentNode[1];
    int g = currentNode[2];

    for (int i = 0; i < 4; i++)
    {
        int x1 = delta[i][0];
        int y1 = delta[i][1];

        if (checkValidCell(x + x1, y + y1, board))
        {
            AddToOpen(x + x1, y + y1, g + 1, Heuristic(x + x1, y + y1, goal[0], goal[1]), openNodes, board);
        }
    }
}

vector<vector<State>> Search(vector<vector<State>> board, int start[2], int end[2])
{
    vector<vector<int>> open{};
    int x = start[0];
    int y = start[1];
    int g = 0;
    int h = Heuristic(x, y, end[0], end[1]);

    AddToOpen(x, y, g, h, open, board);

    while (!open.empty())
    {
        CellSort(&open);
        vector<int> currentNode = open.back();
        open.pop_back();
        board[currentNode[0]][currentNode[1]] = kPath;

        if (end[0] == currentNode[0] && end[1] == currentNode[1])
        {
            board[x][y] = kStart;
            board[end[0]][end[1]] = kFinish;
            return board;
        }
        ExpandNeighbors(currentNode, open, board, end);
    }

    cout << "No path found!"
         << "\n";
    return std::vector<vector<State>>{};
}

int main()
{
    int start[2] = {0, 0};
    int end[2] = {4, 5};
    auto board = ReadBoardFile("A-star-udacity/board");
    auto solution = Search(board, start, end);
    PrintBoard(solution);
}
