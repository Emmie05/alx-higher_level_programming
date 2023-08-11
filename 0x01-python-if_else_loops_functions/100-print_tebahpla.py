#!/usr/bin/python3
for i in range(25, -1, -1):
    print("{:c}".format(ord('z') - i), end='')
    if i % 2 == 0:
        print("{:c}".format(ord('A') + i), end='')
