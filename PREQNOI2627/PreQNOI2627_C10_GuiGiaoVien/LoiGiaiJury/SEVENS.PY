# Bai 2 - SEVENS: Nhom so bay (PreQNOI 2026-2027, Contest 10)
# Y tuong: doan [l, r] chia het cho 7 <=> P[r] = P[l-1] (tong tien to mod 7).


def main():
    data = open("SEVENS.INP", "rb").read().split()
    n = int(data[0])
    first = [-1] * 7
    first[0] = 0
    prefix, best = 0, 0
    for i in range(1, n + 1):
        prefix = (prefix + int(data[i])) % 7
        if first[prefix] == -1:
            first[prefix] = i
        elif i - first[prefix] > best:
            best = i - first[prefix]
    open("SEVENS.OUT", "w").write("%d\n" % best)


main()
