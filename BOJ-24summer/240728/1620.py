import sys

fin = sys.stdin.readline
fout = sys.stdout.write

NM = fin().rstrip()
N, M = NM.split()
N = int(N)
M = int(M)

dict1 = {}  # 이름 -> 번호
dict2 = {}  # 번호 -> 이름

for i in range(0, N):
    s = str(fin()).rstrip()
    dict1[s] = i+1
    dict2[i+1] = s

for i in range(0, M):
    q = fin().rstrip()

    try:
        fout(dict2[int(q)] + '\n')
    except ValueError:
        fout(str(dict1[q]) + '\n')
