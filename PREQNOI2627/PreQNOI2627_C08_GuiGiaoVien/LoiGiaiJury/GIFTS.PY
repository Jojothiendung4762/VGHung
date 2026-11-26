# GIFTS - loi giai day du (Python)
def main():
    d = open("GIFTS.INP", "rb").read().split()
    W, n = int(d[0]), int(d[1])
    p = sorted(map(int, d[2:2 + n]))
    i, j, ans = 0, n - 1, 0
    while i <= j:
        if i < j and p[i] + p[j] <= W: i += 1
        j -= 1; ans += 1
    open("GIFTS.OUT", "w").write(str(ans) + "\n")
main()
