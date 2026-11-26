# Bài 2 - XẾP HÀNG (LINEUP) - lời giải đầy đủ bằng Python, O(N)
import sys
data = open("LINEUP.INP").read().split()
n = int(data[0]); s = data[1]
totalR = s.count('R')
best = n
leftL = 0          # số 'L' bên trái vị trí đang xét
rightR = totalR    # số 'R' từ vị trí đang xét trở về sau
for c in s:
    if c == 'R':
        rightR -= 1          # bỏ chính lớp trưởng ra
    cost = leftL + rightR
    if cost < best:
        best = cost
    if c == 'L':
        leftL += 1
open("LINEUP.OUT", "w").write(str(best) + "\n")
