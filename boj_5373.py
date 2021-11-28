# w1 y2 b3 g4 r5 o6

def rotateArrClockwise(arr):
    ret = [[0]*3 for _ in range(3)]
    for i in range(3):
        for j in range(3):
            ret[j][2-i] = arr[i][j]
    return ret


def rotateArrAnticlockwise(arr):
    ret = [[0]*3 for _ in range(3)]
    for i in range(3):
        for j in range(3):
            ret[2-j][i] = arr[i][j]
    return ret


class Cube():
    def __init__(self):
        self.up = [[0]*3 for _ in range(3)]
        self.down = [[1]*3 for _ in range(3)]
        self.right = [[2]*3 for _ in range(3)]
        self.left = [[3]*3 for _ in range(3)]
        self.front = [[4]*3 for _ in range(3)]
        self.back = [[5]*3 for _ in range(3)]

    def showUpside(self):
        lookup = 'wybgro'
        for i in range(3):
            for j in range(3):
                print(lookup[self.up[i][j]], end='')
            print()

    def rotateHandler(self, cmd):
        if cmd[0] == 'U':
            self.rotateUp(cmd[1])
        elif cmd[0] == 'D':
            self.rotateDown(cmd[1])
        elif cmd[0] == 'L':
            self.rotateLeft(cmd[1])
        elif cmd[0] == 'R':
            self.rotateRight(cmd[1])
        elif cmd[0] == 'F':
            self.rotateFront(cmd[1])
        elif cmd[0] == 'B':
            self.rotateBack(cmd[1])

    def rotateUp(self, way):
        tmp = [*self.front[0]]
        if way == '+':
            for i in range(3):
                self.front[0][i] = self.right[0][i]
                self.right[0][i] = self.back[0][i]
                self.back[0][i] = self.left[0][i]
                self.left[0][i] = tmp[i]
            self.up = rotateArrClockwise(self.up)
        else:
            for i in range(3):
                self.front[0][i] = self.left[0][i]
                self.left[0][i] = self.back[0][i]
                self.back[0][i] = self.right[0][i]
                self.right[0][i] = tmp[i]
            self.up = rotateArrAnticlockwise(self.up)

    def rotateDown(self, way):
        tmp = [*self.front[2]]
        if way == '+':
            for i in range(3):
                self.front[2][i] = self.left[2][i]
                self.left[2][i] = self.back[2][i]
                self.back[2][i] = self.right[2][i]
                self.right[2][i] = tmp[i]
            self.down = rotateArrClockwise(self.down)
        else:
            for i in range(3):
                self.front[2][i] = self.right[2][i]
                self.right[2][i] = self.back[2][i]
                self.back[2][i] = self.left[2][i]
                self.left[2][i] = tmp[i]
            self.down = rotateArrAnticlockwise(self.down)

    def rotateLeft(self, way):
        tmp = [self.up[0][0], self.up[1][0], self.up[2][0]]
        if way == '+':
            for i in range(3):
                self.up[i][0] = self.back[2-i][2]
                self.back[2-i][2] = self.down[2-i][2]
                self.down[2-i][2] = self.front[i][0]
                self.front[i][0] = tmp[i]
            self.left = rotateArrClockwise(self.left)
        else:
            for i in range(3):
                self.up[i][0] = self.front[i][0]
                self.front[i][0] = self.down[2-i][2]
                self.down[2-i][2] = self.back[2-i][2]
                self.back[2-i][2] = tmp[i]
            self.left = rotateArrAnticlockwise(self.left)

    def rotateRight(self, way):
        tmp = [self.up[0][2], self.up[1][2], self.up[2][2]]
        if way == '+':
            for i in range(3):
                self.up[i][2] = self.front[i][2]
                self.front[i][2] = self.down[2-i][0]
                self.down[2-i][0] = self.back[2-i][0]
                self.back[2-i][0] = tmp[i]
            self.right = rotateArrClockwise(self.right)
        else:
            for i in range(3):
                self.up[i][2] = self.back[2-i][0]
                self.back[2-i][0] = self.down[2-i][0]
                self.down[2-i][0] = self.front[i][2]
                self.front[i][2] = tmp[i]
            self.right = rotateArrAnticlockwise(self.right)

    def rotateFront(self, way):
        tmp = [*self.up[2]]
        if way == '+':
            for i in range(3):
                self.up[2][i] = self.left[2-i][2]
                self.left[2-i][2] = self.down[2][i]
                self.down[2][i] = self.right[i][0]
                self.right[i][0] = tmp[i]
            self.front = rotateArrClockwise(self.front)
        else:
            for i in range(3):
                self.up[2][i] = self.right[i][0]
                self.right[i][0] = self.down[2][i]
                self.down[2][i] = self.left[2-i][2]
                self.left[2-i][2] = tmp[i]
            self.front = rotateArrAnticlockwise(self.front)

    def rotateBack(self, way):
        tmp = [*self.up[0]]
        if way == '+':
            for i in range(3):
                self.up[0][i] = self.right[i][2]
                self.right[i][2] = self.down[0][i]
                self.down[0][i] = self.left[2-i][0]
                self.left[2-i][0] = tmp[i]
            self.back = rotateArrClockwise(self.back)
        else:
            for i in range(3):
                self.up[0][i] = self.left[2-i][0]
                self.left[2-i][0] = self.down[0][i]
                self.down[0][i] = self.right[i][2]
                self.right[i][2] = tmp[i]
            self.back = rotateArrAnticlockwise(self.back)


for _ in range(int(input())):
    n = int(input())
    rots = list(input().split())
    cube = Cube()
    for rot in rots:
        cube.rotateHandler(rot)
    cube.showUpside()
