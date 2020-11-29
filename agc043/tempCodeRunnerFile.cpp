vector<vector<int>> min_cost(h,vector<int>(w,INF));
    // queue<pair<int,int>> que;
    // que.emplace(0,0);
    // min_cost[0][0] = 0;
    // while(!que.empty()){
    //     auto p = que.front();
    //     que.pop();
    //     for (int i = 0; i < 2;i++){
    //         int nx = p.first + dx[i],ny = p.second + dy[i];
    //         if((nx<0||nx>h-1)||(ny<0||ny>w-1)) continue;
    //         if (c[nx][ny] == '.') {
    //             if (min_cost[nx][ny] >  min_cost[p.first][p.second]){
    //                 min_cost[nx][ny] =  min_cost[p.first][p.second];
    //                 que.emplace(nx,ny);
    //             }
    //         }
    //     }
    //     if (c[p.first + dx[0]][p.second + dy[0]] == '#' && c[p.first + dx[1]][p.second + dy[1]] == '#'){
    //             if (min_cost[p.first + dx[0]][p.second + dy[0]] >  min_cost[p.first][p.second]+1){
    //                 min_cost[p.first + dx[0]][p.second + dy[0]] =  min_cost[p.first][p.second]+1;
    //                 que.emplace(p.first + dx[0],p.second + dy[0]);
    //             }
    //             if (min_cost[p.first + dx[1]][p.second + dy[1]] >  min_cost[p.first][p.second]+1){
    //                 min_cost[p.first + dx[1]][p.second + dy[1]] =  min_cost[p.first][p.second]+1;
    //                 que.emplace(p.first + dx[1],p.second + dy[1]);
    //             }
    //         }
    // }
    
    // cout << min_cost[h-1][w-1] + count << endl;