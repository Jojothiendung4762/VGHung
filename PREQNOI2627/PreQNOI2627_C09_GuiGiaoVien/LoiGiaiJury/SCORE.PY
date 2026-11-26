# Bai 3 - SCORE: Tro choi tinh diem (PreQNOI 2026-2027, Contest 09)
# Y tuong: gom cac gia tri bang nhau, quy hoach dong tren cac gia tri da sap xep.


def main():
    data = open("SCORE.INP", "rb").read().split()
    n = int(data[0])
    a = sorted(map(int, data[1:1 + n]))

    # Gom cac gia tri bang nhau
    value, gain = [], []
    for x in a:
        if value and value[-1] == x:
            gain[-1] += x
        else:
            value.append(x)
            gain.append(x)

    # f2 = f[j-2], f1 = f[j-1]
    f2, f1 = 0, 0
    for j in range(len(value)):
        if j >= 1 and value[j] == value[j - 1] + 1:
            cur = max(f1, f2 + gain[j])
        else:
            cur = f1 + gain[j]
        f2, f1 = f1, cur

    open("SCORE.OUT", "w").write("%d\n" % f1)


main()
