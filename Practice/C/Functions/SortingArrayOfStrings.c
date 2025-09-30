//============================================================================
// Name        : SortingArrayOfStrings.c
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/sorting-array-of-strings/problem
//============================================================================
/* Description: 
Given an array of strings, you need to implement a sorting_sort function which
sorts the strings according to a comparison function, i.e, you need to implement the function :
void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b)){
    
}
The arguments passed to this function are:
an array of strings : 
length of string array: 
pointer to the string comparison function: 
You also need to implement the following four string comparison functions:

 int lexicographic_sort(char*, char*) to sort the strings in lexicographically non-decreasing order.
 int lexicographic_sort_reverse(char*, char*) to sort the strings in lexicographically non-increasing order.
 int sort_by_number_of_distinct_characters(char*, char*) to sort the strings in non-decreasing order of
 the number of distinct characters present in them.
 If two strings have the same number of distinct characters present in them, then the lexicographically
 smaller string should appear first.
 int sort_by_length(char*, char*) to sort the strings in non-decreasing order of their lengths.
 If two strings have the same length, then the lexicographically smaller string should appear first.

Input Format:
You just need to complete the function string\_sort and implement the four string comparison functions.

Constraints:
 1 <= No. of Strings <= 50 
 1 <= Total Length of all the strings <= 2500 
You have to write your own sorting function and you cannot use the inbuilt qsort function
The strings consists of lower-case English Alphabets only.

Output Format:
The locked code-stub will check the logic of your code.
The output consists of the strings sorted according to the four comparsion functions in the order
mentioned in the problem statement.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b){
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b){
    return strcmp(b, a);
    
}
int characters_count(const char *s){
    int n = 0;
    int count[128] = {0};
    if (NULL == s){
        return -1;
    }
    while(*s != '\0'){
        if (!count[*s]){
            count[*s]++;
            n++;
        }
        s++;
    }
    return n;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){
    int con = characters_count(a) - characters_count(b);
    return (con ? con : lexicographic_sort(a, b));
}

int sort_by_length(const char* a, const char* b) {
    int len = strlen(a) - strlen(b);
    return (len ? len : lexicographic_sort(a, b));
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int mid = len / 2;
    int con = 0;
    while(!con){
        con = 1;
        for(int i = 0; i < len - 1; i++){
            if(cmp_func(arr[i], arr[i + 1]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                con = 0;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
