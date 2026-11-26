# COINS - loi giai day du (Python)
def main():
    A, B, C, X = map(int, open("COINS.INP").read().split())
    ans = 0
    for a in range(0, min(A, X // 500) + 1):
        r = (X - 500 * a) // 50
        lo = 0 if r - C <= 0 else (r - C + 1) // 2
        hi = min(B, r // 2)
        if hi >= lo:
            ans += hi - lo + 1
    open("COINS.OUT", "w").write(str(ans) + "\n")
main()
