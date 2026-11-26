# Bài 4 - KHO CÀ CHUA (TOMATO) - lời giải đầy đủ bằng Python, BFS nhiều nguồn
import sys
from collections import deque
data = open("TOMATO.INP", "rb").read().split()
n, m = int(data[0]), int(data[1])
g = list(map(int, data[2:2 + n * m]))
W = m + 2                      # thêm viền -1 quanh lưới để khỏi kiểm tra biên
G = [-1] * ((n + 2) * W)
for i in range(n):
    G[(i + 1) * W + 1:(i + 1) * W + 1 + m] = g[i * m:(i + 1) * m]
d = [-1] * len(G)
q = deque()
for v in range(len(G)):
    if G[v] == 1:
        d[v] = 0
        q.append(v)
steps = (-W, W, -1, 1)
while q:
    u = q.popleft()
    du = d[u] + 1
    for s in steps:
        v = u + s
        if G[v] == 0 and d[v] == -1:
            d[v] = du
            q.append(v)
ans = 0
for v in range(len(G)):
    if G[v] == 0:
        if d[v] == -1:
            ans = -1
            break
        if d[v] > ans:
            ans = d[v]
open("TOMATO.OUT", "w").write(str(ans) + "\n")
