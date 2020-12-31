from sys import argv
import csv
from collections import defaultdict

#Checks if gives csv and txt files
if len(argv) != 3:
     print("Incorrect number of command-line arguments.")
else:
    # Create dictionary
    sequence = defaultdict(list)
    dna_revealed = {}
    
    #Open the DNA sequence and read
    with open(argv[2]) as f:
        dna_sequence = f.read()
    
    #Open the csv file and read
    with open(argv[1], newline='') as csvfile:
        people = csv.DictReader(csvfile)
        # First row of the csv file
        strs = people.fieldnames[1:]
        # Creates dictionary
        for row in people:
            for field in strs:
                sequence[field].append(row[field])
    
    # Take the list of strs and make a dictionary with no value
    # This dictionary will save the values of strs found on dna_sequence
    for i in strs:
        dna_revealed[i] = None
    
    #For each STR, compute the longest run of consecutive repeats in the DNA sequence
    # Look through dna_revealed
    for keys in dna_revealed:
        current_run = 0
        longest_run = 0
        size = len(keys)
        i = 0
        # Look through dna_sequence
        while i < len(dna_sequence):
            tmp = dna_sequence[i:(i+size)]
            if tmp == keys:
                current_run += 1
                # Don't let compar out of lenght
                if ((i+size) <= len(dna_sequence)):
                    i = i + size
                    continue
            # If there is already a bigger run
            else:
                if current_run > longest_run:
                    longest_run = current_run
            # Set current_run to zero again and increment i to keep looping
            current_run = 0
            i += 1
        dna_revealed[keys] = longest_run
    
    # Compare the STR counts against each row in the csv file
    # Opening again the csvfile
    with open(argv[1], newline = '') as csvfile:
        people2 = csv.DictReader(csvfile)
        # Check each row of the csvfile
        for row in people2:
            count = 0
            # For each str in the result of the longest run of consecutive repeats
            for strs in dna_revealed:
                # Compare the number of the str in dna_revealed and in each person of the csvfile
                if dna_revealed[strs] == int(row[strs]):
                    count += 1
                # If the number of str in a person is the same as in the dna text, there is a match!
                if count == len(dna_revealed):
                    print(row['name'])
                    # The only way I found to end the code
                    exit()
        # If the number of str in a person is different as in the dna text, there is no match!
        else:
            print("No match.")