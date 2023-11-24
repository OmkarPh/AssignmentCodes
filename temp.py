# Amazon developers are building a prototype for a regex generator for the given strings. For the prototype version, the regex consists of uppercase English letters, '[' and ']'. Here, a string of characters enclosed in square brackets '[' and ']' matches any of the one characters in that string. Also, the string of characters enclosed within '[' and ']' consists of uppercase English letters only with no repetition.

# For example,

# • "[ABBR]ABC" is not a valid regex as B occurs twice between square brackets.

# • "[]ABC", "A[A][", "][" and "]ABC" are also not valid regexes as brackets must contain some string, and brackets should also form a balanced bracket sequence.

# • "[ABC]BC[A]" is a valid regex and matches with "BBCA" and "ABCA", but not with "ABBCA". • "[ABCZ][Q]" is a valid regex and matches with "AQ", "BQ", "CQ", "ZQ" but not with "DQ" or "ZC

# • "[A][B][C][D]" is a valid regex and matches only with the string "ABCD"

# Given 3 strings a, b, and cof length n, find the longest regex that matches both the strings a and b but does not match with the string c. If no such regex exists output -1. If multiple such regexes exist output the lexicographically smallest one.

# Note:
# • The length of a regex is the number of characters in it, i.e. including uppercase English alphabets, 'T' and ']'.

# • A string p is lexicographically smaller than string q, if p is a prefix of q, is not equal to q or there exists i, such that p,<q, and for all j</it is satisfied that p₁ = q. Note that while comparing p and q we consider their ASCII values, i.e. '[' and ']' are greater than any uppercase English letters. For example, "ABC" is lexicographically smaller than "BCD" and "ABCDE" but larger than "AAC" and "AACDE".

# • The answer string, which is to be returned can turn out to be in the order of 106 for larger n's.

# Example

# a = "AB", b = "BD", c= "CD",

# Regex "[ABDEFGHIJKLMNOPQRSTUVWXYZ][ABCDEFGHIJKLMNOPQRSTUVWXYZ]" matches with strings "AB" and "BD", but not with string "CD".

# Function Description

# Complete the function getLongestRegex in the editor below. getLongestRegex has the following parameters:

# a: a string

# b: a string

# c: a string

# Returns

# string. the longest lexicographically smallest regex matching a and b but not c, if no such regex exists return -1 as a string.

# Constraints

# • 1≤ns 105

# • a, b, and c consists of uppercase English letters only.

# Input Format For Custom Testing

# The first line contains a string, a.

# The second line contains a string, b.

# The last line contains a string, c.

# Sample Case 0

# Sample Input For Custom Testing

# STDIN

# FUNCTION

# AERB

# a = "AERB"

# ATRC

# b = "ATRC"

# AGCB

# C = "AGCB"

# Sample Output

# [ABCDEFGHIJKLMNOPQRSTUVWXYZ] [ABCDEFGHIJKLMNOPQRSTUVWXYZ] [ABDEFGHIJKLMNOPQRSTUVWXYZ] [ABCDEFGHIJKLMNOPQRSTUVWXYZ]

# And the most optimal python code is:



def getLongestRegex(a, b, c):
    targetidx = -1
    for i in range(len(c)):
        if a[i] != c[i] and b[i] != c[i]:
            if targetidx == -1:
                targetidx = i
            elif c[i] <= c[targetidx]:
                targetidx = i

    if targetidx == -1:
        return "-1"

    result = ""
    for i in range(len(c)):
        if i == targetidx:
            result += "["
            # append "ABCDEFGHIJKLMNOPQRSTUVWXYZ" one by one, but ignore, c[i]
            for j in range(ord('A'), ord('Z')+1):
                if chr(j) != c[targetidx]:
                    result += chr(j)
            result += "]"
        else:
            result += "[ABCDEFGHIJKLMNOPQRSTUVWXYZ]"
    
    return result


a = "AERB"
b = "ATRC"
c = "AGCB"
print(getLongestRegex(a, b, c))
print()


a = "AB"
b = "BD"
c= "CD"
print(getLongestRegex(a, b, c))
print()


a = "ABC"
b = "ABC"
c = "ABC"
print(getLongestRegex(a, b, c))
print()

a="XZBYNZVAODK"
b="KHPKKPFQPOR"
c="SHHKKZVQPDJ"
print(getLongestRegex(a, b, c))
print()
