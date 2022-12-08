def main():
    input_file = open("input", "r")

    overall_max = 0
    current_elf = 0
    for line in input_file:

        if line == "\n":
            # end of elf
            # compare to max
            if current_elf > overall_max:
                overall_max = current_elf

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

main()
