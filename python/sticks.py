#!/usr/bin/env python3
import random

sticks = 21

print("There are 21 sticks, you can take 1-4 number of sticks at a time.")
print("Whoever will take the last stick will loose")

while True:
    print("Sticks left: ", sticks)
    if sticks == 1:
        print("Computer took the last stick, you win")
        break
    sticks_taken = random.randint(1, 4)
    print("Computer took: ", sticks_taken, "\n")
    print("You took: ", (5 - sticks_taken), "\n")
    sticks -= 5
