#!/usr/bin/python3.8
import dis
import hidden_4


def print_hidden_names(module):
    for name in dir(module):
        if not name.startswith('__'):
            print(name)


print_hidden_names(hidden_4)
