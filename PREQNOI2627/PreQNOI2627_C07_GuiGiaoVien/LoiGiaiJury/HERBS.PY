# HERBS - loi giai day du (Python)
def main():
    d = list(map(int, open("HERBS.INP").read().split()))
    T, M = d[0], d[1]
    t = d[2:2 + 2 * M:2]; v = d[3:3 + 2 * M:2]
    S = sum(v)
    if T <= 100000:
        f = [0] * (T + 1)
        for ti, vi in zip(t, v):
            if ti > T: continue
            # f_moi[j] = max(f[j], f[j - ti] + vi) voi j >= ti (dung ban sao cu)
            f[ti:] = [max(x, y + vi) for x, y in zip(f[ti:], f[:T + 1 - ti])]
        ans = f[T]
    elif S <= 100000:
        INF = float("inf")
        g = [0] + [INF] * S
        for ti, vi in zip(t, v):
            g[vi:] = [min(x, y + ti) for x, y in zip(g[vi:], g[:S + 1 - vi])]
        ans = max(s for s in range(S + 1) if g[s] <= T)
    else:
        ans = 0
        for mask in range(1 << M):
            st = sv = 0
            for i in range(M):
                if mask >> i & 1:
                    st += t[i]; sv += v[i]
            if st <= T and sv > ans: ans = sv
    open("HERBS.OUT", "w").write(str(ans) + "\n")
main()
