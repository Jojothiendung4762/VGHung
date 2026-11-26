# Bai 4 - PRISON: Giam giu (PreQNOI 2026-2027, Contest 10)
# Y tuong: xet cac cap theo muc thu han giam dan, DSU co do lech (parity);
#          cap dau tien buoc phai o cung trai la dap an.
import sys


def main():
    data = open("PRISON.INP", "rb").read().split()
    n, m = int(data[0]), int(data[1])
    edges = []
    for i in range(m):
        a, b, c = int(data[2 + 3 * i]), int(data[3 + 3 * i]), int(data[4 + 3 * i])
        edges.append((c, a, b))
    edges.sort(reverse=True)

    parent = list(range(n + 1))
    diff = [0] * (n + 1)          # 0: cung trai voi cha, 1: khac trai

    def find_root(u):
        path = []
        while parent[u] != u:
            path.append(u)
            u = parent[u]
        root = u
        for v in reversed(path):  # tu dinh gan goc ra ngoai
            p = parent[v]
            if p != root:
                diff[v] ^= diff[p]
            parent[v] = root
        return root

    answer = 0
    for c, a, b in edges:
        ra, rb = find_root(a), find_root(b)
        if ra == rb:
            if diff[a] == diff[b]:
                answer = c
                break
        else:
            parent[ra] = rb
            diff[ra] = diff[a] ^ diff[b] ^ 1

    open("PRISON.OUT", "w").write("%d\n" % answer)


main()
