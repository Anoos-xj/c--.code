#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    for (char c : s)
    {
        if (c == delimiter)
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += c;
        }
    }
    if (!token.empty())
    {
        tokens.push_back(token);
    }
    return tokens;
}

vector<vector<char>> parse_fen(const string &fen)
{
    vector<vector<char>> board(8, vector<char>(8, ' '));
    vector<string> parts = split(fen, '/');
    for (int i = 0; i < 8; ++i)
    {
        string part = parts[i];
        int col = 0;
        for (char c : part)
        {
            if (c >= '1' && c <= '8')
            {
                int num = c - '0';
                col += num;
            }
            else
            {
                board[i][col++] = c;
            }
            if (col >= 8)
                break;
        }
    }
    return board;
}

pair<int, int> find_king(const vector<vector<char>> &board, char king)
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == king)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool attack(char attacker, int i, int j, int x, int y, const vector<vector<char>> &board)
{
    if (i == x && j == y)
        return false;

    switch (attacker)
    {
    case 'p':
    { // 黑兵
        if (x == i + 1 && abs(y - j) == 1)
            return true;
    }
        return false;
    case 'P':
    { // 白兵
        if (x == i - 1 && abs(y - j) == 1)
            return true;
    }
        return false;
    case 'n':
    { // 黑马
        int dx = abs(x - i), dy = abs(y - j);
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }
    case 'N':
    { // 白马
        int dx = abs(x - i), dy = abs(y - j);
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }
    case 'b':
    { // 黑象
        if ((i - j != x - y) && (i + j != x + y))
            return false;
        int dx = x - i, dy = y - j;
        int step_x = dx != 0 ? dx / abs(dx) : 0;
        int step_y = dy != 0 ? dy / abs(dy) : 0;
        int steps = max(abs(dx), abs(dy));
        for (int s = 1; s < steps; ++s)
        {
            int r = i + step_x * s, c = j + step_y * s;
            if (r < 0 || r >= 8 || c < 0 || c >= 8)
                return false;
            if (board[r][c] != ' ')
                return false;
        }
        return true;
    }
    case 'B':
    { // 白象
        if ((i - j != x - y) && (i + j != x + y))
            return false;
        int dx = x - i, dy = y - j;
        int step_x = dx != 0 ? dx / abs(dx) : 0;
        int step_y = dy != 0 ? dy / abs(dy) : 0;
        int steps = max(abs(dx), abs(dy));
        for (int s = 1; s < steps; ++s)
        {
            int r = i + step_x * s, c = j + step_y * s;
            if (r < 0 || r >= 8 || c < 0 || c >= 8)
                return false;
            if (board[r][c] != ' ')
                return false;
        }
        return true;
    }
    case 'r':
    { // 黑车
        if (i != x && j != y)
            return false;
        if (i == x)
        {
            int step = (j < y) ? 1 : -1;
            for (int c = j + step; c != y; c += step)
                if (board[i][c] != ' ')
                    return false;
        }
        else
        {
            int step = (i < x) ? 1 : -1;
            for (int r = i + step; r != x; r += step)
                if (board[r][j] != ' ')
                    return false;
        }
        return true;
    }
    case 'R':
    { // 白车
        if (i != x && j != y)
            return false;
        if (i == x)
        {
            int step = (j < y) ? 1 : -1;
            for (int c = j + step; c != y; c += step)
                if (board[i][c] != ' ')
                    return false;
        }
        else
        {
            int step = (i < x) ? 1 : -1;
            for (int r = i + step; r != x; r += step)
                if (board[r][j] != ' ')
                    return false;
        }
        return true;
    }
    case 'q':
    { // 黑后
        if (i == x || j == y)
        {
            if (attack('r', i, j, x, y, board))
                return true;
        }
        if ((i - j == x - y) || (i + j == x + y))
        {
            return attack('b', i, j, x, y, board);
        }
        return false;
    }
    case 'Q':
    { // 白后
        if (i == x || j == y)
        {
            if (attack('R', i, j, x, y, board))
                return true;
        }
        if ((i - j == x - y) || (i + j == x + y))
        {
            return attack('B', i, j, x, y, board);
        }
        return false;
    }
    case 'k':
    { // 黑王
        int dx = abs(x - i), dy = abs(y - j);
        return (dx <= 1 && dy <= 1) && (dx != 0 || dy != 0);
    }
    case 'K':
    { // 白王
        int dx = abs(x - i), dy = abs(y - j);
        return (dx <= 1 && dy <= 1) && (dx != 0 || dy != 0);
    }
    default:
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        string fen;
        cin >> fen;
        vector<vector<char>> board = parse_fen(fen); // 解析棋盘，返回二维数组
        auto white_king = find_king(board, 'K');     // 找白王位置，并记录
        auto black_king = find_king(board, 'k');     // 找黑王位置，并记录

        bool white_check = false; // 白被将了吗？
        for (int i = 0; i < 8 && !white_check; ++i)
        {
            for (int j = 0; j < 8 && !white_check; ++j)
            {
                char c = board[i][j];
                if (c >= 'a' && c <= 'z' && c != 'k')
                {
                    if (attack(c, i, j, white_king.first, white_king.second, board))
                    {
                        white_check = true;
                        break;
                    }
                }
            }
        }

        bool black_check = false; // 黑被将了吗？
        for (int i = 0; i < 8 && !black_check; ++i)
        {
            for (int j = 0; j < 8 && !black_check; ++j)
            {
                char c = board[i][j];
                if (c >= 'A' && c <= 'Z' && c != 'K')
                {
                    if (attack(c, i, j, black_king.first, black_king.second, board))
                    {
                        black_check = true;
                        break;
                    }
                }
            }
        }

        if (white_check)
            cout << "check\n";
        else if (black_check)
            cout << "CHECK\n";
        else
            cout << "none\n";
    }

    return 0;
}