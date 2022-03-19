import sys
input = sys.stdin.readline

vowelTable = ['a', 'e', 'i', 'o', 'u']
consTable = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
             'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']

while True:
    word = input().strip()
    if word == 'end':
        break
    vowel = False
    secure = True
    vowCnt, consCnt = 0, 0

    for i in range(len(word)):
        if i > 0 and word[i-1] == word[i] and word[i] != 'e' and word[i] != 'o':
            secure = False
            break

        if not vowel and word[i] in vowelTable:
            vowel = True

        if word[i] in vowelTable:
            vowCnt += 1
            consCnt = 0
        else:
            consCnt += 1
            vowCnt = 0

        if consCnt == 3 or vowCnt == 3:
            secure = False
            break

    if not vowel:
        secure = False

    print('<{0}> is {1}.'.format(
        word, 'acceptable' if secure else 'not acceptable'))
