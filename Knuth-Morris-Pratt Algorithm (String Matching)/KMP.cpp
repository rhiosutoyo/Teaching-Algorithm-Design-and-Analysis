/*
   source:
   https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*/

// C++ program for implementation of KMP pattern searching algorithm
#include <bits/stdc++.h>

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	// find the string length of string "txt" and pattern "pat"
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix values for pattern
	// lps = longest proper prefix
	// For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. Proper prefixes are “”, “A” and “AB”.
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	// send the pattern, length of pattern, and lps array
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0 .. M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		// example:
		// pattern: AA
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		// pattern: AB
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver program to test above function
int main()
{
	// example from slide "COMP6049 Pert 19-20"
	char txt[] = "ABABCABCABABABD";
	char pat[] = "ABABD";

	KMPSearch(pat, txt);

	return 0;
}

