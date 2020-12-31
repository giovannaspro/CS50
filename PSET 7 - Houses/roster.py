from cs50 import SQL
from sys import argv

#Checks if gives csv and txt files
if len(argv) != 2:
     print("Incorrect number of command-line arguments.")
     exit()
else:
    # Open db
    open("students.db","r").close()
    db = SQL("sqlite:///students.db")
    
    house_argv = argv[1]
    line = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last,first", house_argv)
    for row in line:
        print(row["first"], end = ' ')
        if row["middle"] != None: 
            print(row["middle"], end = ' ')
        print(row["last"], end = ',')
        print(f" born",row["birth"])