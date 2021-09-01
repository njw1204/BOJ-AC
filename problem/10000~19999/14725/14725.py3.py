class Trie:
    def __init__(self, name, level):
        self.name = name
        self.level = level
        self.childs = []

    def get_name(self):
        return self.name

    def get_level(self):
        return self.level

    def add_child(self, node):
        self.childs.append(node)

    def get_childs(self):
        return sorted(self.childs)

    def find_child(self, name):
        for node in self.childs:
            if node.get_name() == name:
                return node
        return None

    def __lt__(self, other):
        return self.name < other.name

    def __str__(self):
        return '--' * self.level + self.name


def print_ans(root):
    if root.get_level() >= 0:
        print(root)
    for i in root.get_childs():
        print_ans(i)

n=int(input())
root=Trie('', -1)

for i in range(n):
    path = input().split()[1:]
    curr_root = root
    for name in path:
        find_result = curr_root.find_child(name)
        if find_result:
            curr_root = find_result
        else:
            new_node = Trie(name, curr_root.get_level() + 1)
            curr_root.add_child(new_node)
            curr_root = new_node

print_ans(root)