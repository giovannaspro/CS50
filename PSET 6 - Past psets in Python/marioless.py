from cs50 import get_int

height = get_int("Height: ")

for i in range(1, height+1, 1):
    k = height - i
    space = ' '
    hashtag = "#" 
    print(f"{k * space + hashtag * i}", end="")
    print()