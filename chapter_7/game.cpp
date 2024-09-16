#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<vector<int>, bool> dp;

bool isEnd(vector<int> state){
    for(int i: state){
        if(i) return false;
    }
    return true;
}

vector<vector<int>> children(vector<int> & state){
    vector<vector<int>> ret;
    for(int r = 0; r<state.size(); r++){
        if(state[r] != 0){
            for(int i = 0; i < state[r]; i++){
                vector<int> child = state;
                child[r] = i;
                ret.push_back(child);
            }
        }
    }
    return ret;
}

bool dfs(vector<int> state){
    if(isEnd(state)) return true;
    auto it = dp.find(state);
    if(it!=dp.end()){
        return dp[state];
    }
    vector<vector<int>> cs = children(state);
    for(auto it = cs.begin(); it!=cs.end(); it++){
        if(!dfs(*it)){
            dp[state] = true;
            return true;
        }
    }
    dp[state] = false;
    return false;
}

bool solve(vector<int> & sstate){
    return dfs(sstate);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> sstate;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            sstate.push_back(k);
        }
        solve(sstate) ? cout << "You should start" << endl : cout << "Let them start" << endl;
    }
    return 0;
}