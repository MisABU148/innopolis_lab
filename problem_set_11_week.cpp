//
// Created by Maria on 02.04.2024.
//
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,char>>vert = {{1, 'A'}, {0, 'B'}, {1, 'C'}, {3, 'D'}, {3, 'E'}, {1, 'F'},
                               {0, 'G'}, {2, 'H'}};
vector<vector<int>> gr = {{0,0,0,0,0,0,0,0},{1,0,1,1,1,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,1,1,0,1},{0,0,0,0,0,0,0,0}};
int count = 0;

bool ts(string ans) {
    if (ans.size() == 8) {
        count++;
        cout<<"T.S. "<<ans[0];
        for (int i = 1; i<8; i++) {
            cout<<", "<<ans[i];
        }
        cout<<"; \\"<<"\\"<<endl;
        return 1;
    }
    for (int i = 0; i<8; i++) {
        if (vert[i].first == 0) {
            for (int j = 0; j<8; j++) {
                if (gr[i][j]) {
                    vert[j].first--;
                }
            }
            vert[i].first--;
            ts(ans+vert[i].second);

            vert[i].first++;
            for (int j = 0; j<8; j++) {
                if (gr[i][j]) {
                    vert[j].first++;
                }
            }
        }
    }
    return 1;
}

int main(){
    ts("");
    cout<<count;
}