# Bai 2 - MARBLES: Chia bi (PreQNOI 2026-2027, Contest 09)
# Y tuong: chat nhi phan X nho nhat sao cho tong ceil(K_i / X) <= N.


def main():
    data = open("MARBLES.INP", "rb").read().split()
    n, m = int(data[0]), int(data[1])
    k = list(map(int, data[2:2 + m]))

    # Can duoi: tong ceil(K_i / X) >= tong K_i / X  =>  X >= tong K / N
    lo = max(1, (sum(k) + n - 1) // n)
    hi = max(k)
    while lo < hi:
        mid = (lo + hi) // 2
        need = sum((v + mid - 1) // mid for v in k)
        if need <= n:
            hi = mid
        else:
            lo = mid + 1

    open("MARBLES.OUT", "w").write("%d\n" % lo)


main()
