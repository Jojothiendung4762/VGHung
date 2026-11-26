# Bai 4 - DISTSUM: Tong khoang cach (PreQNOI 2026-2027, Contest 09)
# Y tuong: doi goc. ans[con] = ans[cha] + n - 2 * sz[con]. Duyet BFS, khong de quy.


def main():
    data = open("DISTSUM.INP", "rb").read().split()
    n = int(data[0])
    adj = [[] for _ in range(n + 1)]
    for i in range(n - 1):
        u, v = int(data[1 + 2 * i]), int(data[2 + 2 * i])
        adj[u].append(v)
        adj[v].append(u)

    # BFS tu dinh 1
    parent = [0] * (n + 1)
    depth = [0] * (n + 1)
    order = [1]
    for u in order:                      # order duoc noi dai trong luc duyet
        pu, du = parent[u], depth[u] + 1
        for v in adj[u]:
            if v != pu:
                parent[v] = u
                depth[v] = du
                order.append(v)

    # Kich thuoc cay con
    sz = [1] * (n + 1)
    for i in range(n - 1, 0, -1):
        v = order[i]
        sz[parent[v]] += sz[v]

    # Doi goc
    ans = [0] * (n + 1)
    ans[1] = sum(depth)
    for i in range(1, n):
        v = order[i]
        ans[v] = ans[parent[v]] + n - 2 * sz[v]

    open("DISTSUM.OUT", "w").write(" ".join(map(str, ans[1:])) + "\n")


main()
