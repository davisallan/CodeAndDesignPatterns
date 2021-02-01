/*
* File Name: my_lab2exe_B.c
* Lab # and Assignment #: Lab 2 Exercise B
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: 
*/
int my_strcmp(const char* str1, const char* str2);
/*  Duplicates strcmp from <string.h>, except it returns the ASCII value difference of
 *  the first two characters that are different.
 *  REQUIRES
 *      str1 points to the beginning of a string.
 *      str2 points to the beginning of a string.
 *  PROMISES
 *      Returns 0 if the strings are identical, otherwise, returns the ASCII value
 *      difference of the first two characters that are different
 */

int my_strlen(const char *s);
/*  Duplicates strlen from <string.h>, except return type is int.
 *  REQUIRES
 *     s points to the beginning of a string.
 *  PROMISES
 *     Returns the number of chars in the string, not including the
 *     terminating null.
 */

void my_strncat(char *dest, const char *source, int n);
/*  Duplicates strncat from <string.h>, except return type is void.
 *  
 *  REQUIRES
 *      dest points to the beginning of a string
 *      source points to the beginning of a string
 *      n is the upper bound of how many characters should be copied
 * 
 *  PROMISES
 *      Concatenates the number of characters from source to the end of the
 *      destination string
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char *str3 = "-toe";

    /* point 1 */
    char str5[] = "ticket";
    char my_string[100] = "";
    int bytes;
    int length;

    /* using my_strlen C libarary function */
    length = (int)my_strlen(my_string);
    printf("\nLine 1: my_string length is %d.", length);

    /* using sizeof operator */
    bytes = sizeof(my_string);
    printf("\nLine 2: my_string size is %d bytes.", bytes);

    /* using strcpy C libarary function */
    strcpy(my_string, str1);
    printf("\nLine 3: my_string contains: %s", my_string);

    length = (int)my_strlen(my_string);
    printf("\nLine 4: my_string length is %d.", length);

    my_string[0] = '\0';
    printf("\nLine 5: my_string contains:\"%s\"", my_string);

    length = (int)my_strlen(my_string);
    printf("\nLine 6: my_string length is %d.", length);

    bytes = sizeof(my_string);
    printf("\nLine 7: my_string size is still %d bytes.", bytes);

    /* strncat append the first 3 characters of str5 to the end of my_string */
    my_strncat(my_string, str5, 3);
    printf("\nLine 8: my_string contains:\"%s\"", my_string);

    length = (int)my_strlen(my_string);
    printf("\nLine 9: my_string length is %d.", length);

    my_strncat(my_string, str2, 4);
    printf("\nLine 10: my_string contains:\"%s\"", my_string);

    /* strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
    my_strncat(my_string, str3, 6);
    printf("\nLine 11: my_string contains:\"%s\"", my_string);

    length = (int)my_strlen(my_string);
    printf("\nLine 12; my_string has %d characters.", length);

    printf("\n\nUsing my_strcmp - replicates C library function: ");

    printf("\n\"ABCD\" is less than \"ABCDE\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABCDE"));
    printf("\n\"ABCD\" is less than \"ABND\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABND"));
    printf("\n\"ABCD\" is equal than \"ABCD\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABCD"));
    printf("\n\"ABCD\" is less than \"ABCd\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABCd"));
    printf("\n\"Orange\" is greater than \"Apple\" ... my_strcmp returns: %d\n",
           my_strcmp("Orange", "Apple"));

    return 0;
}

int my_strlen(const char *s) {

    int length = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        length += 1;
        i++;
    }
    return i;
}

void my_strncat(char *dest, const char *source, int n) {
    int i = 0;
    //loop to find index of null character in destination string
    while (dest[i] != '\0')
    {
        i++;
    }
    //copying source string to destination string
    for (int j = 0; j < n; j++) {
        if (source[j] == '\0') {
            dest[i] = source[j];
            break;
        }
        dest[i] = source[j];
        i++;
    }
    //adding in final null character to the end of the new string
    dest[i] = '\0';
}

int my_strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0') {
            break;
        }
        i++;
    }
    return str1[i] - str2[i];
}