#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceWord(const char *str, const char *placeholder, const char *newWord)
{
    char *resultString;
    int i, count = 0;
    int newWordLength = strlen(newWord);
    int placeholderLength = strlen(placeholder);

    // Lets count the number of times placeholder occurs in the string
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], placeholder) == &str[i]) // &str[i] : string str that starts at the position i points to
        {
            count++; // increment if word found

            // Jump over this word
            i += placeholderLength - 1; // -1 as our  for loop will increment it by 1 for the next iteration
        }
    }

    // i will be the length of the template
    // Making a new string to fit in the replaced words
    resultString = (char *)malloc(i + count * (newWordLength - placeholderLength) + 1); 
    // +1 to accommodate the null character as well

    i = 0;
    while (*str)
    {
        // Compare the substring with result
        if (strstr(str, placeholder) == str) // str is pointer to string; for 1st iteration it is &str[0], string that begins at index 0, and so on
        {
            strcpy(&resultString[i], newWord);
            i += newWordLength;
            str += placeholderLength;
        }
        else
        {
            resultString[i] = *str; // *(&str[0]) for 1st iteration
            i += 1;
            str += 1; // str = str+1 = &str[1]
        }
    }
    resultString[i] = '\0';
    return resultString;
}

int main()
{
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;
    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("genBill.txt", "w");
    char str[200]; // length of new string

    fgets(str, 200, ptr); // str will get contents of file pointed to by ptr, basically it has the template
    printf("------------------------------------");
    printf("BILL TEMPLATE");
    printf("------------------------------------\n");
    
    printf("%s\n", str);
    
    // Call the replaceWord function and generate newStr
    char *newStr;
    newStr = replaceWord(str, "{{item}}", "iPhone");
    newStr = replaceWord(newStr, "{{outlet}}", "Croma");
    newStr = replaceWord(newStr, "{{name}}", "Rishabh");
    
    printf("------------------------------------");
    printf("GENERATED BILL");
    printf("------------------------------------\n");
    
    printf("%s\n", newStr);
    
    fprintf(ptr2, "%s", newStr); // we want new string(newStr) in ptr2
    
    printf("------------------------------------");
    printf("MESSAGE");
    printf("------------------------------------\n");
    
    printf("The generated bill has been written to the file genBill.txt\n");

    fclose(ptr);
    fclose(ptr2);
    return 0;
}