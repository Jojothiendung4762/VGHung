# Bai 1 - DIGITS: Viet so (PreQNOI 2026-2027, Contest 10)
# Y tuong: cac so co d chu so nam trong [10^(d-1), 10^d - 1]; dem theo tung nhom.


def main():
    n = int(open("DIGITS.INP").read())
    answer, p, d = 0, 1, 1
    while p <= n:
        last = min(n, 10 * p - 1)
        answer += (last - p + 1) * d
        p *= 10
        d += 1
    open("DIGITS.OUT", "w").write("%d\n" % answer)


main()
