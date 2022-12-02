from array import *

with open("input.txt") as file:
    lines = [line.rstrip() for line in file]

segments = array('i')
running_total = 0

for line in lines:
    if line == "":
        segments.append(running_total)
        running_total = 0
    else:
        running_total += int(line)

if running_total > 0:
    segments.append(running_total)

segments = sorted(segments, reverse=True)

print(max(segments))
print(segments[0] + segments[1] + segments[2])