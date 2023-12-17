with open("fortnite_mega.txt", "w") as file:
    for _ in range(100000):
        file.write("fortnite " * 10 + "\n")
'''
with open("fortnite_mega_oneline.txt", "w") as file:
    file.write(" ".join(["fortnite"] * 100000))
'''