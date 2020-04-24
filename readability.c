#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int countLetters(string);
int countWords(string);
int countSentences(string);

int main(void)
{
    // get input
    string passage = get_string("Text: ");

    // find total counts
    int letters = countLetters(passage);
    int words = countWords(passage);
    int sentences = countSentences(passage);

    // calculate averages
    float averageWords = (float) words / (float) sentences;
    float averageLetters = (float) letters / (float) words;

    //calculate index
    float index = round((0.0588 * (averageLetters * 100)) - (0.296 * (100 / averageWords)) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

int countLetters(string passage)
{
    // get string length
    int length = strlen(passage);
    // establish count
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(passage[i]) != 0)
        {
            letters++;
        }
    }

    return letters;
}

int countWords(string passage)
{
    // get string length
    int length = strlen(passage);
    // establish count
    int words = 1;
    for (int i = 0; i < length; i++)
    {
        if (passage[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

int countSentences(string passage)
{
    // get string length
    int length = strlen(passage);
    // establish count
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (passage[i] == '!' || passage[i] == '?' || passage[i] == '.')
        {
            sentences++;
        }
    }

    return sentences;
}
