
# Create a simple list and iterate it with loop.

ST = ["El", "Mike", "Lucas", "Dustin", "Will", "Hopper", "Steve"]
Dark = ["Mikkel", "Jonas", "Martha", "Bartosz", "Regina", "Ulrich", "Magnus", "Noah"]

# Iterating using indexed for loop 
for x in range(len(ST)): 
	print(ST[x], end=" ") 

print()

# Iterating using for_in loop
for character in Dark:
    print(character, end=" ")
