
n = int(input())
res = False
# ll ans_a = -1,ans_b = -1;
# ll a_max = 0,b_max = 0;
# while(pow(3,a_max) < pow(10,18)) {
#     a_max++;
# }
# while(pow(5,b_max) < pow(10,18)) {
#     b_max++;
# }
# ll A = 1,B = 1;
# rep(a,a_max) {
#     rep(b,b_max) {
#         if (pow(3,a)+pow(5,b) == n) {
#             res = true;
#             ans_a = a;
#             ans_b = b;
#         }
#     }
# }
ans_a = -1
ans_b = -1
for a in range(30):
    for b in range(20):
        if 3**a + 5**b == n:
            res = True
            ans_a = a
            ans_b = b

if res:
    print(ans_a,ans_b)
else :
    print(-1)
