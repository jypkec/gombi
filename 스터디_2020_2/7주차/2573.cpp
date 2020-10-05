#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arctic;
vector<vector<int>> melt;
int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int melting();
int find_union();
void dfs(int cnt, int x, int y);

int main(){
    cin >> N >> M;
    arctic = vector<vector<int>>(N, vector<int>(M, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arctic[i][j];
        }
    }
    int year =0;
    while(1){
        year++;
        if(!melting()){
            cout << 0 << endl;
            break;
        }
        if(find_union() != 1){
            cout << year<< endl;
            break;
        }
    }
    return 0;
}

int melting(){
    melt = vector<vector<int>>(N, vector<int>(M, 0));
    int ice =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arctic[i][j] > 0){
                int cnt = 0;
                for(int a = 0; a<4; a++){
                    int x = i+dx[a];
                    int y = j+dy[a];
                    if(x >=0 && y >= 0 && x <=N-1 && y<=M-1){
                        if(arctic[x][y]==0){
                            cnt++;
                        }
                    }
                }
                melt[i][j] = cnt;
                //cout << "i : " << i << " J : " << j << " cnt : " << melt[i][j] << endl;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arctic[i][j] > melt[i][j]){
                arctic[i][j] -= melt[i][j];
                ice++;
            }
            else{
                arctic[i][j] = 0;
            }
        }
    }
    /*cout << "NEW ARCTIC" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arctic[i][j] << " ";
        }
        cout << endl;
    }*/
    return ice;
}

int find_union(){
    int cnt = 0;
    melt = vector<vector<int>>(N, vector<int>(M, 0));
    for(int i=0; i< N; i++){
        for(int j=0; j< M; j++){
            if(melt[i][j] ==0 && arctic[i][j] !=0){
                cnt++;
                dfs(cnt, i, j);
            }
        }
    }
    return cnt;
}

void dfs(int cnt, int x, int y){
    if(arctic[x][y] !=0 && melt[x][y] == 0){
        melt[x][y] = cnt;
    }
    else{
        return;
    }
    for(int der = 0; der<4; der++){
        if(x+dx[der] >= 0 && x+dx[der] <= N-1 && y+dy[der] >=0 && y+dy[der] <= M-1){
            dfs(cnt, x+dx[der], y+dy[der]);
        }
    }
}
