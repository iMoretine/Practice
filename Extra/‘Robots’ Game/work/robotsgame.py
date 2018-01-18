import sys
import random


class RobotsGame:
    def __init__(self):
        self.robots_list = []
        self.heaps_list = []
        self.player = ()

    def generate_robots(self):
        self.robots_list.clear()
        self.heaps_list.clear()
        for i in range(10):
            x = int(random.random()*60)
            y = int(random.random()*30)
            while (x, y) in self.robots_list:
                x = int(random.random() * 60)
                y = int(random.random() * 30)
            self.robots_list.append((x, y))

    def update_robots(self):
        for i, robot in enumerate(self.robots_list):
            if robot[0] < self.player[0]:
                robot = (robot[0] + 1, robot[1])
            elif robot[0] > self.player[0]:
                robot = (robot[0] - 1, robot[1])
            else:
                robot = (robot[0], robot[1])

            if robot[1] < self.player[1]:
                robot = (robot[0], robot[1] + 1)
            elif robot[1] > self.player[1]:
                robot = (robot[0], robot[1] - 1)
            else:
                robot = (robot[0], robot[1])

            self.robots_list[i] = robot

        # lose
        for robot in self.robots_list:
            if robot == self.player:
                return "Lose"

        # crash
        for i, robot1 in enumerate(self.robots_list):
            for j, robot2 in enumerate(self.robots_list):
                if robot1 == robot2 and i != j and robot1 not in self.heaps_list:
                    self.heaps_list.append(robot1)
                    self.robots_list.remove(robot1)
                    self.robots_list.remove(robot2)

        # crash
        for robot in self.robots_list:
            for heap in self.heaps_list:
                if robot == heap:
                    self.robots_list.remove(robot)

        # win
        if len(self.robots_list) == 0:
            return "Win"

        return "Continue"

    def generate_player(self):
        x = int(random.random() * 60)
        y = int(random.random() * 30)
        while (x, y) in self.robots_list and (x, y) in self.heaps_list:
            x = int(random.random() * 60)
            y = int(random.random() * 30)
        self.player = (x, y)

    def update_player(self, op):
        temp_coord = self.player
        # up
        if op == 'i':
            temp_coord = (self.player[0], self.player[1] - 1)
        # left
        if op == 'j':
            temp_coord = (self.player[0] - 1, self.player[1])
        # right
        if op == 'l':
            temp_coord = (self.player[0] + 1, self.player[1])
        # down
        if op == 'k':
            temp_coord = (self.player[0], self.player[1] + 1)
        # up and left
        if op == 'u':
            temp_coord = (self.player[0] - 1, self.player[1] - 1)
        # up and right
        if op == 'o':
            temp_coord = (self.player[0] + 1, self.player[1] - 1)
        # down and left
        if op == 'n':
            temp_coord = (self.player[0] - 1, self.player[1] + 1)
        # down and right
        if op == 'm':
            temp_coord = (self.player[0] + 1, self.player[1] + 1)
        # does not move
        if op == '.':
            temp_coord = (self.player[0], self.player[1])
        # teleport
        if op == 't':
            self.generate_player()
            return

        # border
        if temp_coord[0] < 0 or temp_coord[0] >= 60 \
                or temp_coord[1] < 0 or temp_coord[1] >= 30 \
                or temp_coord in self.robots_list \
                or temp_coord in self.heaps_list:
            temp_coord = self.player

        self.player = temp_coord

    def display(self):
        # empty map
        game_map = []
        for i in range(30):
            game_map.append([' ' for j in range(60)])
        # robots
        for i in self.robots_list:
            game_map[i[1]][i[0]] = 'r'
        # heaps
        for i in self.heaps_list:
            game_map[i[1]][i[0]] = '*'
        # player
        game_map[self.player[1]][self.player[0]] = 'I'

        sys.stdout.flush()
        for i in range(62):
            print('-', end=' ')
        print()
        for line in game_map:
            print('|', end=' ')
            for i in line:
                print(i, end=' ')
            print('|')
        for i in range(62):
            print('-', end=' ')
        print()

    def get_option(self):
        print("Legend: r - robot, * - junk heap, I - you")
        print()

        print("Keys:")
        print("u - up and left, i - up, o - up and right")
        print("j - left, l - right")
        print("n - down and left, k - down, m - down and right")
        print(". - does not move")
        print("t - teleport")
        print()

        print("Input your option and press enter:")
        op = input()
        while op == "" or op[0] not in ['i', 'j', 'l', 'k', 'u', 'o', 'm', 'n', '.', 't']:
            print("Invalid option, input your option and press enter:")
            op = input()
        return op[0]

if __name__ == '__main__':
    rg = RobotsGame()
    rg.generate_robots()
    rg.generate_player()
    while True:
        rg.display()
        op = rg.get_option()
        rg.update_player(op)
        re = rg.update_robots()
        if re == "Win":
            print("You Win!")
            break
        if re == "Lose":
            print("You Lose!")
            break
    pass
