# Bài 1 - LÁT SÂN (TILES) - lời giải đầy đủ bằng Python
n, m, a = map(int, open("TILES.INP").read().split())
open("TILES.OUT", "w").write(str(((n + a - 1) // a) * ((m + a - 1) // a)) + "\n")
