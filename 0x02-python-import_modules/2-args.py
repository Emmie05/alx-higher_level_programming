#!/usr/bin/python3
from sys import argv

num_args = len(argv) - 1
arg_string = "argument" if num_args == 1 else "arguments"

print("{} {}{}".format(num_args, arg_string, ":" if num_args > 0 else "."))
for i, arg in enumerate(argv[1:], start=1):
    print("{}: {}".format(i, arg))
