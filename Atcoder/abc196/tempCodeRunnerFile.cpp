    bb[i][j+1] = '#';
                dfs(i+1,bb);
                bb[i][j] = '.';
                bb[i][j+1] = '.';