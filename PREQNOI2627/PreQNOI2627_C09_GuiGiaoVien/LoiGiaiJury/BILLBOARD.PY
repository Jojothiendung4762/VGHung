# Bai 1 - BILLBOARD: Bang quang cao (PreQNOI 2026-2027, Contest 09)
# Y tuong: phan nhin thay = dien tich bang - phan chung voi xe tai.


def area(r):
    x1, y1, x2, y2 = r
    return (x2 - x1) * (y2 - y1)


def intersect_area(a, b):
    w = min(a[2], b[2]) - max(a[0], b[0])
    h = min(a[3], b[3]) - max(a[1], b[1])
    if w <= 0 or h <= 0:
        return 0
    return w * h


def main():
    v = list(map(int, open("BILLBOARD.INP").read().split()))
    board1, board2, truck = v[0:4], v[4:8], v[8:12]
    answer = (area(board1) - intersect_area(board1, truck)) + \
             (area(board2) - intersect_area(board2, truck))
    open("BILLBOARD.OUT", "w").write("%d\n" % answer)


main()
