# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :

# A Binary Number Tree (BNT) is one of:
# - Number
# - (Binary-Number-Tree, Binary-Number-Tree)

# Definition of 3 trees.
tree1 = ((1, (2, 3)), 4)
tree2 = (4, (1, (3, 2)))
tree3 = (1, (2, (3, 4)))


def add_leaves(tree):
    """returns the sum of all the values of all leaves in tree
        BNT -> int"""
    if isinstance(tree, tuple):
        return add_leaves(tree[0]) + add_leaves(tree[1])
    else:
        return tree

# main program
print("The sum of all the values of all of tree1's leaves: %d" % add_leaves(tree1))
print("The sum of all the values of all of tree2's leaves: %d" % add_leaves(tree2))
print("The sum of all the values of all of tree3's leaves: %d" % add_leaves(tree3))
