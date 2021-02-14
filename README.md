# 競プロ頑張る備忘録

## 空白なしの文字列受け取り
```getline(cin,s);```

## setのforループ
```for (auto x:st){}```

- 同じような処理は書き漏れでバグりやすいので関数化して簡単にまとめる。例えば繰り返しで使ってる変数の初期化ミス

- vectorでsize0ができるのはなぜかまずい。できる分は多くサイズとっておく。https://atcoder.jp/contests/code-festival-2015-morning-middle/submissions/18640477

コーナーケース(b==0) とかに注意する
