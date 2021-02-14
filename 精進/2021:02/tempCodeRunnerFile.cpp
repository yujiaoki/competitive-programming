 string s1 = "", s2 = "";
    rep(i,s.size()) {
        if (i % 2 == 0) s1 += '1';
        else s1 += '0';
    }
    rep(i,s.size()) {
        if (i % 2 == 0) s2 += '0';
        else s2 += '1';
    }
    int ans = 2483483;
    int cnt = 0;
    rep(i,s.size()) {
        if (s[i] != s1[i]) cnt++;
    }
    chmin(ans,cnt);
    cnt = 0;
    rep(i,s.size()) {
        if (s[i] != s2[i]) cnt++;
    }
    chmin(ans,cnt);
    cout << ans << endl;