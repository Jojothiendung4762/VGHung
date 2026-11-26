# Bài 3 - HỆ THỐNG ĐÁNH CHẶN (MISSILE) - lời giải đầy đủ bằng Python, O(N log N)
from bisect import bisect_left, bisect_right
data = open("MISSILE.INP").read().split()
n = int(data[0])
down = []   # lưu -tail của dãy không tăng => mảng không giảm
up = []     # tail của dãy tăng ngặt
for t in range(1, n + 1):
    x = int(data[t])
    k = bisect_right(down, -x)
    if k == len(down): down.append(-x)
    else: down[k] = -x
    k = bisect_left(up, x)
    if k == len(up): up.append(x)
    else: up[k] = x
open("MISSILE.OUT", "w").write("%d\n%d\n" % (len(down), len(up)))
