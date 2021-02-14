for (auto ni:G[i]) {
        sell = max(sell,a[i]);
        buy = min(buy,a[ni]);
        if (vis[ni] == false) dfs(vis,a,G,ni,buy,sell);
        vis[ni] = true;
    }