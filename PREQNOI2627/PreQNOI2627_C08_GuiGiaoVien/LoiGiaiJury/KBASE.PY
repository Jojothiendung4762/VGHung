# KBASE - loi giai day du (Python): luy thua ma tran 2x2
MOD = 10**9 + 7
def mul(a, b):
    return [[(a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD, (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD],
            [(a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD, (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD]]
n, k = map(int, open("KBASE.INP").read().split())
q = (k - 1) % MOD
M = [[q, q], [1, 0]]; R = [[1, 0], [0, 1]]; e = n - 1
while e > 0:
    if e & 1: R = mul(R, M)
    M = mul(M, M); e >>= 1
x = R[0][0] * q % MOD; y = R[1][0] * q % MOD
open("KBASE.OUT", "w").write(str((x + y) % MOD) + "\n")
