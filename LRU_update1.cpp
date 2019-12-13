#include <iostream>
#include <list>
#include <vector>
using namespace std;
int cache[100][100];
int user_input[100];
void showCache(int row, int col)
{
    cout << "showing cache" << endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m,n;
    cout << "n :"; cin >> n;
    cout << "m :"; cin >> m;
    int col = n;
    int row = m/n;
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cache[i][j] = -1;
        }
    }
    int val,cache_input_count = 0;
    while(cin >> val)
    {
        if(val == -1)
            break;
        user_input[cache_input_count] = val;
        cache_input_count++;
    }

    vector <int> recent_val;
    bool check = false;
    for(int idx = 0; idx <cache_input_count; idx++ )
    {

        int cache_idx_no = user_input[idx] % row;
        for(int i = 0; i < col; i++)
        {
            if(cache[cache_idx_no][i] == -1)
            {
                cache[cache_idx_no][i] = user_input[idx];
                recent_val.push_back(user_input[idx]);
                check = true;
                break;
            }
        }

        if(check == true)
        {
            check = false;
            showCache(row,col);
            continue;
        }

    }
}
