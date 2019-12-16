#include <iostream>
#include <list>
#include <vector>
using namespace std;
int cache[100][100];
int user_input[100];

void showCache(int row, int col, bool is_hit)
{
    if(is_hit == true)
        cout << "Hit" << endl;
    else
        cout << "Miss" << endl;


    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(cache[i][j] == -1){
                cout << " B ";
            }
            else cout <<  cache[i][j] <<" ";
        }
        cout << endl;
    }
}

int main()
{
    int m,n,value;
    cout << "n :"; cin >> n;
    cout << "m :"; cin >> m;

    int col = n;
    int row = m/n;
    int check_empty = 0;
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cache[i][j] = -1;
        }
    }

    int loop_counter = 0;
    int val,total_input = 0;
    while(cin >> val)
    {
        if(val == -1)
            break;
        user_input[total_input] = val;
        total_input++;
    }

    list <int> lru_val;
    bool is_hit = false;
    int check_condition = 0;
    for(int idx = 0; idx < total_input; idx++)
    {
        int set_idx = user_input[idx] % row;
        for(int i = 0; i < col; i++)
        {
            if (cache[set_idx][i] == -1 || cache[set_idx][i] == user_input[idx]){
                    if (cache[set_idx][i] == -1){
                        cache[set_idx][i] = user_input[idx];
                        lru_val.push_back(user_input[idx]);
                        check_condition = 1;
                        is_hit = false;
                        break;
                    }
                    else {
                        lru_val.remove(user_input[idx]);
                        lru_val.push_back(user_input[idx]);
                        check_condition = 1;
                        is_hit = true;
                        break;
                    }

            }
        }
        if (check_condition == 1){
                check_condition = 0;
                showCache(row,col,is_hit);
                continue;
            }
        for(int i = 0; i < col; i++)
        {
            if(cache[set_idx][i] != -1){
                if(cache[set_idx][i] == user_input[idx]){
                    lru_val.remove(user_input[idx]);
                    lru_val.push_back(user_input[idx]);
                    check_condition = 1;
                    is_hit = true;
                    break;
                }
            }
        }
        if (check_condition == 1){
                check_condition = 0;
                showCache(row,col,is_hit);
                continue;
            }

        for(int i = 0; i < col;i++){
            if (cache[set_idx][i] != -1 && cache[set_idx][i] != user_input[idx]){
                check_empty++;
            }
        }
        if(check_empty == col){
            for(auto itr = lru_val.begin(); itr != lru_val.end();itr++){
                if(*itr % row == set_idx){
                    value = *itr;
                    lru_val.remove(value);
                    break;
                }
            }
            for (int i = 0; i < col;i++){
                if(cache[set_idx][i] == value){
                    cache[set_idx][i] = user_input[idx];
                    check_condition = 1;
                    is_hit = false;
                    lru_val.push_back(user_input[idx]);
                    break;
                }
            }
        }
        if (check_condition == 1){
                check_condition = 0;
                showCache(row,col,is_hit);
                continue;
            }

    }

}
