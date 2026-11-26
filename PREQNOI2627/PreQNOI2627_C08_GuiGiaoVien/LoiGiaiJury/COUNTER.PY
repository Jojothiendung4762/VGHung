# COUNTER - loi giai day du (Python): BFS tu goc, day gia tri tu cha xuong con
def main():
    d = open("COUNTER.INP", "rb").read().split()
    n, q = int(d[0]), int(d[1])
    g = [[] for _ in range(n + 1)]
    p = 2
    for _ in range(n - 1):
        a, b = int(d[p]), int(d[p + 1]); p += 2
        g[a].append(b); g[b].append(a)
    c = [0] * (n + 1)
    for _ in range(q):
        c[int(d[p])] += int(d[p + 1]); p += 2
    seen = [False] * (n + 1); seen[1] = True
    order = [1]
    for u in order:
        cu = c[u]
        for v in g[u]:
            if not seen[v]:
                seen[v] = True; c[v] += cu; order.append(v)
    open("COUNTER.OUT", "w").write(" ".join(map(str, c[1:])) + "\n")
main()
