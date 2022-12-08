def bubblesort_three(items):
    if items[0] > items[1]:
        temp = items[0]
        items[0] = items[1]
        items[1] = temp

    if items[1] > items[2]:
        temp = items[1]
        items[1] = items[2]
        items[2] = temp

    if items[0] > items[1]:
        temp = items[0]
        items[0] = items[1]
        items[1] = temp

    return

def main():
    input_file = open("input", "r")

    overall_max = 0
    top_three = [0,0,0]
    current_elf = 0
    for line in input_file:

        if line == "\n":
            # end of elf
            # compare to max
            if current_elf > overall_max:
                overall_max = current_elf

            if current_elf > top_three[0]:
                top_three[0] = current_elf
                bubblesort_three(top_three)

            #either way, reset current_elf to zero
            print(current_elf)
            current_elf = 0
        else:
            current_elf += int(line)

    """
    print(line)
    print(int(line))
    print(int(line)+69)
    """

    print("FINAL LARGEST ELF")
    print(overall_max)
    print("TOP THREE ELVES")
    print(top_three, " = ", top_three[0] + top_three[1] + top_three[2])

main()
