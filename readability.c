#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

//declare funtion beforehand
int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    // get input from user in a string
    string input = get_string("Text: ");

    // average number of letters per 100 words
    float L = ((float)count_letters(input) / (float)count_words(input)) * 100;

    // average number of sentences per 100 words
    float S = ((float)count_sentences(input) / (float)count_words(input)) * 100;

    // plug in to Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //print appropriate message
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index); // print a no decimal float to ensure correct rounding
    }
}

// function to return the number of letters (letters_count) in a string (input)
int count_letters(string input)
{
    // initialize letters count as 0
    int letters_count = 0;

    // for every character in the string
    for (int i = 0; i < strlen(input); i++)
    {
        // check if char is a letter
        if (isalpha(input[i]))
        {
            // add one to letters_count
            letters_count++;
        }
    }
    return letters_count;
}

// function to return the number of words (words_count) in a string(input)
// number of words should equal number of spaces according to assumptions in task description
int count_words(string input)
{
    // initialize word count as 0
    int word_count = 1;

    // for every character in the string
    for (int i = 0; i < strlen(input); i++)
    {
        // check if char is a space using ascii number
        if (input[i] == 32)
        {
            // add one to word_count
            word_count++;
        }
    }
    return word_count;
}

// function to return the number of sentences (sentence_count) in a string(input)
int count_sentences(string input)
{
    // initialize word count as 0
    int sentence_count = 0;

    // for every character in the string
    for (int i = 0; i < strlen(input); i++)
    {
        // check if char is a full stop, exclamation mark or question mark using ascii number
        if (input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
            // add one to word_count
            sentence_count++;
        }
    }
    return sentence_count;
}



