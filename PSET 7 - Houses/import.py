from cs50 import SQL
from sys import argv
import csv

#Checks if gives csv and txt files
if len(argv) != 2:
     print("Incorrect number of command-line arguments.")
     exit()
else:
    # Open db
    open("students.db","w").close()
    db = SQL("sqlite:///students.db")
    
    # Create table called `characters`, and specify the columns we want, 
    # all of which will be text except `birth` 
    db.execute("CREATE TABLE students(first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")
    
    #Open the csv file and read
    with open(argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            name = row["name"].split()
            first = name[0]
            if len(name) == 3:
                middle = name[1]
                last = name[2]
            if len(name) == 2:
                middle = None
                last = name[1]
            house = row["house"]
            birth = int(row["birth"])
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?,?)", first, middle, last, house, birth)