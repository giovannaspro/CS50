from cs50 import get_string
text = get_string("Text: ")
n_letter = 0
n_word = 1
n_sentence = 0
nothing = 0
for i in range(len(text)):
    if text[i].isalpha():
        n_letter += 1
    elif text[i].isspace():
        n_word += 1
    elif (text[i] == '.' or text[i] == '!' or text[i] == '?'):
        n_sentence += 1
    else:
        nothing += 1
#Do readability
L = float(n_letter / n_word * 100)
S = float(n_sentence / n_word * 100)
index = round((float)(0.0588 * L - 0.296 * S - 15.8))
if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", index)