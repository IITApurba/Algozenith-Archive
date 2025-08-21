#include <bits/stdc++.h>
using namespace std;

int board[4][4];

int get_random(int x)
{
    return rand() % x;
}

void random_spawn()
{
    // rejection sampling
    while (1)
    {
        int x = get_random(4);
        int y = get_random(4);
        if (board[x][y] == 0)
        {
            int temp = get_random(4);
            if (temp == 0 || temp == 1 || temp == 2)
                board[x][y] = 2;
            else
                board[x][y] = 4;
            return;
        }
    }
}

void setup_game()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
    random_spawn();
    random_spawn();
}

int check_game_end()
{
    // 0 -> Not ended.  1-> Ended and Win. 2-> Ended and lose.
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
            {
                return 1;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j + 1 < 4 && board[i][j] == board[i][j + 1])
            {
                return 0;
            }
            if (i + 1 < 4 && board[i][j] == board[i + 1][j])
            {
                return 0;
            }
        }
    }
    return 2;
}

void display()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
                cout << "_ ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void swipe(int arr[])
{
    int last = 4;
    int last_fixed = 1;
    for (int cur = 3; cur >= 0; cur--)
    {
        // cout<<cur<<" "<<arr[cur];
        if (arr[cur] == 0)
            continue;
        if (last_fixed)
        {
            // ...x....Z -> ......xZ
            arr[last - 1] = arr[cur];
            if (cur != last - 1)
                arr[cur] = 0;
            last = last - 1;
            last_fixed = 0;
        }
        else
        {
            if (arr[last] == arr[cur])
            {
                // ...x....x -> ......2x
                arr[last] += arr[cur];
                last_fixed = 1;
                arr[cur] = 0;
            }
            else
            {
                // ...x....y -> ......xy
                arr[last - 1] = arr[cur];
                if (cur != last - 1)
                    arr[cur] = 0;
                last = last - 1;
                last_fixed = 0;
            }
        }
    }
}

void move_up()
{
    for (int col = 0; col < 4; col++)
    {
        int arr[4];
        for (int i = 0; i < 4; i++)
        {
            arr[i] = board[3 - i][col];
        }
        swipe(arr);
        for (int i = 0; i < 4; i++)
        {
            board[3 - i][col] = arr[i];
        }
    }
}

void move_down()
{
    for (int col = 0; col < 4; col++)
    {
        int arr[4];
        for (int i = 0; i < 4; i++)
        {
            arr[i] = board[i][col];
        }
        swipe(arr);
        for (int i = 0; i < 4; i++)
        {
            board[i][col] = arr[i];
        }
    }
}

void move_left()
{
    for (int row = 0; row < 4; row++)
    {
        int arr[4];
        for (int i = 0; i < 4; i++)
        {
            arr[i] = board[row][3 - i];
        }
        swipe(arr);
        for (int i = 0; i < 4; i++)
        {
            board[row][3 - i] = arr[i];
        }
    }
}

void move_right()
{
    for (int row = 0; row < 4; row++)
    {
        int arr[4];
        for (int i = 0; i < 4; i++)
        {
            arr[i] = board[row][i];
        }
        swipe(arr);
        for (int i = 0; i < 4; i++)
        {
            board[row][i] = arr[i];
        }
    }
}

int main()
{
    setup_game();
    while (!check_game_end())
    {
        // Take user action and do it.
        display();
        cout << "What move to do? (U,D,L,R):";
        char ch;
        cin >> ch;
        int temp[4][4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temp[i][j] = board[i][j];
            }
        }
        // save old board.
        if (ch == 'U')
        {
            move_up();
        }
        else if (ch == 'D')
        {
            move_down();
        }
        else if (ch == 'L')
        {
            move_left();
        }
        else if (ch == 'R')
        {
            move_right();
        }
        else
        {
            cout << "Invalid Move.";
            continue;
        }
        // Check if it changed... or else its invalid.
        bool changed = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (temp[i][j] != board[i][j])
                {
                    changed = 1;
                    break;
                }
            }
        }
        if (changed)
        {
            random_spawn();
        }
        else
        {
            cout << "Invalid Move.";
            continue;
        }
    }

    return 0;
}