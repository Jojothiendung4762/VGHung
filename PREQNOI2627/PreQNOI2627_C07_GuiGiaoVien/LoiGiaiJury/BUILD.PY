# BUILD - loi giai day du (Python): sap xep topo Kahn
from collections import deque
def main():
    d = list(map(int, open("BUILD.INP", "rb").read().split()))
    n, m = d[0], d[1]
    D = [0] + d[2:2 + n]
    p = 2 + n
    g = [[] for _ in range(n + 1)]; indeg = [0] * (n + 1)
    for i in range(m):
        x, y = d[p + 2 * i], d[p + 2 * i + 1]
        g[x].append(y); indeg[y] += 1
    w = d[p + 2 * m]
    start = [0] * (n + 1); f = [0] * (n + 1)
    q = deque(i for i in range(1, n + 1) if indeg[i] == 0)
    while q:
        u = q.popleft(); fu = start[u] + D[u]; f[u] = fu
        for v in g[u]:
            if fu > start[v]: start[v] = fu
            indeg[v] -= 1
            if indeg[v] == 0: q.append(v)
    open("BUILD.OUT", "w").write(str(f[w]) + "\n")
main()
