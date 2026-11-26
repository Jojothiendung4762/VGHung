# SUGAR - loi giai day du (Python)
n = int(open("SUGAR.INP").read().split()[0])
ans = -1
k = n // 5
while k >= 0 and k >= n // 5 - 2:
    if (n - 5 * k) % 3 == 0:
        ans = k + (n - 5 * k) // 3
        break
    k -= 1
open("SUGAR.OUT", "w").write(str(ans) + "\n")
