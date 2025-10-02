/* Wildcard Matching

Problem Statement
You are given a function,
    int Match(char* firstStr, char* secondStr);

The function accepts two strings as its arguments. Implement the function such that it returns 1 if the first string matches the second string using wildcard comparisons, otherwise returns 0.

Note:
    The first string will contain either of the following:
        a) Lowercase alphabets
        b) * (asterisk) - Matches with 0 or more occurrences of any character or set of characters
        c) ? (question mark) - Matches with any one character
    The second string will contain only lowercase English alphabets.

Example:
    Input:  a*b?d
            akjhlbcd
    Output: 1
    Explanation:    firstStr matches secondStr using wildcard comparisons, hence the answer is 1.
*/