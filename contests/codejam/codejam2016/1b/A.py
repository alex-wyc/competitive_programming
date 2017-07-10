def get_number(freq):
    phone_number = []

    while freq['Z'] != 0:
        phone_number.append(0)
        freq['Z'] -= 1
        freq['E'] -= 1
        freq['R'] -= 1
        freq['O'] -= 1

    while freq['X'] != 0:
        phone_number.append(6)
        freq['S'] -= 1
        freq['I'] -= 1
        freq['X'] -= 1

    while freq['G'] != 0:
        phone_number.append(8)
        freq['E'] -= 1
        freq['I'] -= 1
        freq['G'] -= 1
        freq['H'] -= 1
        freq['T'] -= 1

    while freq['U'] != 0:
        phone_number.append(4)
        freq['F'] -= 1
        freq['O'] -= 1
        freq['U'] -= 1
        freq['R'] -= 1

    while freq['R'] != 0:
        phone_number.append(3)
        freq['T'] -= 1
        freq['H'] -= 1
        freq['R'] -= 1
        freq['E'] -= 1
        freq['E'] -= 1

    while freq['W'] != 0:
        phone_number.append(2)
        freq['T'] -= 1
        freq['W'] -= 1
        freq['O'] -= 1

    while freq['O'] != 0:
        phone_number.append(1)
        freq['O'] -= 1
        freq['N'] -= 1
        freq['E'] -= 1

    while freq['F'] != 0:
        phone_number.append(5)
        freq['F'] -= 1
        freq['I'] -= 1
        freq['V'] -= 1
        freq['E'] -= 1

    while freq['S'] != 0:
        phone_number.append(7)
        freq['S'] -= 1
        freq['E'] -= 1
        freq['V'] -= 1
        freq['E'] -= 1
        freq['N'] -= 1

    while freq['N'] != 0:
        phone_number.append(9)
        freq['N'] -= 2
        freq['I'] -= 1
        freq['E'] -= 1

    phone_number.sort()

    return "".join(map(str, phone_number))

if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(T):
        freq_dict = {}
        for j in range(ord('A'), ord('Z') + 1):
            freq_dict[chr(j)] = 0
        S = raw_input()
        for c in S:
            freq_dict[c] += 1

        n = get_number(freq_dict)
        print "Case #%d: %s" % ((i + 1), n)
