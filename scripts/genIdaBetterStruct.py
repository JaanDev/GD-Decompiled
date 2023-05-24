size = int(input("Input requied class size(hex): "), 16)
base = int(input("Input base class size(hex): "), 16)

for i in range(0, size-base, 4):
    print(f"_DWORD dword{hex(i + base)[2:].upper()};")
