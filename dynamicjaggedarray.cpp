#include <iostream>

using namespace std;

int main()
{
    int row;
    cin >> row;
    int col;
    int **arr = new int *[row];
    int sizes[5];
    for (int i = 0; i < row; i++)
    {
        cout << "enter the number of clumn in row " << i + 1 << endl;
        cin >> col;
        sizes[i] = col;

        arr[i] = new int[col];
    }

    for (int j = 0; j < row; j++)
    {
        for (int i = 0; i < sizes[j]; i++)
        {
            cout << "enter the elements row wise for row" << j + 1 << endl;
            cin >> arr[j][i];
            cout << "press ENTER" << endl;
        }
    }

    for (int j = 0; j < row; j++)
    {
        for (int i = 0; i < sizes[j]; i++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}