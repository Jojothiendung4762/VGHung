# Bai 3 - POSTER: Dan ap phich (PreQNOI 2026-2027, Contest 10)
# Y tuong: ngan xep chieu cao tang dan; gap lai chieu cao dang o dinh thi dung chung tam.


def main():
    data = open("POSTER.INP", "rb").read().split()
    n = int(data[0])
    st, posters = [], 0
    for i in range(n):
        h = int(data[2 + 2 * i])         # bo qua chieu rong data[1 + 2 * i]
        while st and st[-1] > h:
            st.pop()
        if st and st[-1] == h:
            continue
        st.append(h)
        posters += 1
    open("POSTER.OUT", "w").write("%d\n" % posters)


main()
