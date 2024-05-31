#include <stdlib.h>
#include <stdio.h>

#include "stringbuffer.h"

void test_append_characters_to_empty_string() {
    char *expected = "hello world!";
    char *word = "hello world!";
    stringbuffer sb = stringbuffer_empty();
    printf("empty > ");
    stringbuffer_dump(sb);    
    for (unsigned int i=0; word[i]!='\0'; i++) {
        printf("append '%c' > ", word[i]);
        sb = stringbuffer_append(sb, word[i]);
        stringbuffer_dump(sb);     
    }
    printf("\nexpected > %s\n", expected);
    sb = stringbuffer_destroy(sb);
}


void test_replace_characters_to_not_empty_string() {
    char *expected = "Kutcher, Christopher A";
    char *word = "kutcher, christopher a";
    stringbuffer sb = stringbuffer_create(word);
    printf("create \"%s\" > ", word);
    stringbuffer_dump(sb); 
    char c = 'K';
    unsigned int index = 0u;
    sb = stringbuffer_replace(sb, c, index);
    printf("replace %c %u > ", c, index);
    stringbuffer_dump(sb); 
    c = 'C';
    index = 9u;
    sb = stringbuffer_replace(sb, c, index);
    printf("replace %c %u > ", c, index);
    stringbuffer_dump(sb); 
    c = 'A';
    index = 21u;
    sb = stringbuffer_replace(sb, c, index);
    printf("replace %c %u > ", c, index);
    stringbuffer_dump(sb); 
    printf("\nexpected > %s\n", expected);
    sb = stringbuffer_destroy(sb);
}


void test_remove_whitespace_characters_to_not_empty_string() {
    char *expected = "GenerativeAIIsTheNextStepInArtificialIntelligence.";
    char *word = " Generative AI Is The Next Step In Artificial Intelligence. ";
    unsigned int indexes[]={0, 10, 12, 14, 17, 21, 25, 27, 37, 50};
    stringbuffer sb = stringbuffer_create(word);
    printf("create \"%s\" > ", word);
    stringbuffer_dump(sb);
    unsigned int length = 10;
    for (unsigned int i=0; i<length; i++) {
        printf("remove %u > ", indexes[i]);
        sb = stringbuffer_remove(sb, indexes[i]);
        stringbuffer_dump(sb);     
    }
    printf("\nexpected > %s\n", expected);
    sb = stringbuffer_destroy(sb);
}


void test_get_character_array_and_length_from_not_empty_string() {
    char *expected = "Algorithmic complexity is concerned about how fast or slow particular algorithm performs.";
    char *word = "Algorithmic complexity is concerned about how fast or slow particular algorithm performs.";
    stringbuffer sb = stringbuffer_create(word);
    printf("create \"%s\" > ", word);
    stringbuffer_dump(sb);
    unsigned int length = stringbuffer_length(sb);
    printf("length > %u\n", length);
    char *array = stringbuffer_to_string(sb);
    printf("to_string > %s\n", array);
    printf("\nexpected > %s\n", expected);
    sb = stringbuffer_destroy(sb);    
    free(array);
    array = NULL;
}

void test_get_characters_from_not_empty_string() {
    char *word = "kutcher, christopher a";
    stringbuffer sb = stringbuffer_create(word);
    printf("create \"%s\" > ", word);
    stringbuffer_dump(sb); 
    char expected = 'k';
    unsigned int index = 0u;
    char c = stringbuffer_char_at(sb, index);
    printf("char_at %u > %c\n", index, c);
    printf("expected > %c\n\n", expected);
    expected = 'c';
    index = 9u;
    c = stringbuffer_char_at(sb, index);
    printf("char_at %u > %c\n", index, c);
    printf("expected > %c\n\n", expected);
    expected = 'a';
    index = 21u;
    c = stringbuffer_char_at(sb, index);
    printf("char_at %u > %c\n", index, c);
    printf("expected > %c\n\n", expected);
    sb = stringbuffer_destroy(sb);
}


int main(void) {

    // test 1
    printf("Running test 'Append several characters to the empty stringbuffer'\n\n");
    test_append_characters_to_empty_string();
    // test 2
    printf("\nRunning test 'Replace several characters to the not empty stringbuffer'\n\n");
    test_replace_characters_to_not_empty_string();
    // test 3
    printf("\nRunning test 'Remove whitespace characters to the not empty stringbuffer'\n\n");
    test_remove_whitespace_characters_to_not_empty_string();
    // test 4
    printf("\nRunning test 'Get the character array and lenght from the not empty stringbuffer'\n\n");
    test_get_character_array_and_length_from_not_empty_string();
    // test 5
    printf("\nRunning test 'Get several characters from the not empty stringbuffer'\n\n");
    test_get_characters_from_not_empty_string();

    return EXIT_SUCCESS; 
}
