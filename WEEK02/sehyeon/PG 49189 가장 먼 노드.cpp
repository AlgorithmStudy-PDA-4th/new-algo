#include <string>
#include <vector>
#include <queue>
#include<iostream>

using namespace std;

int node_size, maxi, maxi_cnt;
int dist[20001];
bool isvisit[20001];
vector<int> v[20001];

void bfs() {
    queue<pair<int, int>> q;
    q.push({1,0});
    isvisit[1] = 1;
    
    while(!q.empty()) {
        pair<int, int> tmp;
        tmp = q.front();
        vector<int> v_tmp = v[tmp.first];
        q.pop();
        for(int i=0;i<v_tmp.size();i++) {
            if(!isvisit[v_tmp[i]]) {
                isvisit[v_tmp[i]] = 1;
                dist[v_tmp[i]] = tmp.second+1;
                if(tmp.second+1 > maxi) {
                    maxi = tmp.second+1;
                    maxi_cnt = 1;
                }
                else if(tmp.second+1==maxi) maxi_cnt++;
                q.push({v_tmp[i], tmp.second+1});
                cout << v_tmp[i] << " " << maxi << " " << maxi_cnt << "\n";
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    node_size = n;
    for(int i=0;i<edge.size();i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    bfs();
    cout << maxi << " " << maxi_cnt;
    return maxi_cnt;
}
