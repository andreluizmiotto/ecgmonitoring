file = open('Signal.txt', 'r')
for line in file:
    if (int(next(file)) != (int(line)+1)):
        print("Fora de sequência")        



        