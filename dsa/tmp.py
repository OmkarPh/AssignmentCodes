

def first_non_repeating_character(str):
  char_counts = {}
  for i in range(len(str)):
    if str[i] in char_counts:
      char_counts[str[i]] += 1
    else:
      char_counts[str[i]] = 1

  for i in range(len(str)):
    if char_counts[str[i]] == 1:
      return str[i]
  return -1

def main():
  str = input()
  print(first_non_repeating_character(str))

if __name__ == "__main__":
  main()

  