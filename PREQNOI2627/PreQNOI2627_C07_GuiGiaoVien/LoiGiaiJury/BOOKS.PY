# BOOKS - loi giai day du (Python): hai con tro
def main():
    d = open("BOOKS.INP", "rb").read().split()
    n, t = int(d[0]), int(d[1]); a = list(map(int, d[2:2 + n]))
    s = 0; l = 0; best = 0
    for r in range(n):
        s += a[r]
        while s > t:
            s -= a[l]; l += 1
        if r - l + 1 > best: best = r - l + 1
    open("BOOKS.OUT", "w").write(str(best) + "\n")
main()
