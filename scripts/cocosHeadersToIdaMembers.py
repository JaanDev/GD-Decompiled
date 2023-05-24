import re
from sys import stdin, stdout

lines = []

print("write STOP on the last line to process the text")

while True:
    line = input()
    if line == "STOP":
        break
    else:
        lines.append(line.strip())

# remove empty lines or rob's removed things
lines = [l for l in lines if l and not l.startswith("RT_REMOVE")]

# remove RT_ADD or HJ_ADD only leave members
p = re.compile(r"RT_ADD\((.+?)\)")
lines = [p.sub("\\1", l) for l in lines]

p = re.compile(r"HJ_ADD\((.+?)\)")
lines = [p.sub("\\1", l) for l in lines]

pattern = re.compile(r"[^\(\)]+\s+[\w\d*<>&]+;")

lines = [l for l in lines if pattern.match(l)]  # only members

# remove comments
p = re.compile(r"\s+?//.+")
lines = [p.sub("", l) for l in lines]

# replace long spaces with one
p = re.compile(r"\s+")
lines = [p.sub(" ", l) for l in lines]

print("/////////////////////////////////////")

print('\n'.join(lines))