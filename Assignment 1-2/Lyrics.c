#include <stdio.h>
#include <string.h>

int main()
{
    // Unit Test 1 Strings
    char songLine1[] = "Oh, well imagine";
    char songLine2[] = "As I'm pacing the pews in a church corridor";
    char songLine3[] = "And I can't help but to hear";
    char songLine4[] = "No, I can't help but to hear an exchanging of words...";

    // Unit Test 2 Strings
    char songLine5[] = "Oh-oh-oh-oh-oh,";
    char songLine6[] = "oh-oh-oh-oh,";
    char songLine7[] = "oh-oh-oh /";
    char songLine8[] = "Caught in a bad romance...";

    // Unit Test 3 Strings
    char songLine9[] = "Coming out of my cage";
    char songLine10[] = "And I've been doing just fine";
    char songLine11[] = "Gotta gotta be down";
    char songLine12[] = "Because I want it all";

    // Unit Test 4 Strings
    char songLine13[] = "Now, this is a story all about how";
    char songLine14[] = "My life got flipped-turned upside down";
    char songLine15[] = "And I'd like to take a minute";
    char songLine16[] = "Just sit right there";
    char songLine17[] = "I'll tell you how I became the prince of a town called Bel-Air";


    // Unit Test 1 Print
    printf("\n%s\n%s\n%s\n%s\n", songLine1, songLine2, songLine3, songLine4);

    // Unit Test 2 Print
    printf("\n%s\n%s\n%s\n%s\n", songLine5, songLine6, songLine7, songLine8);

    // Unit Test 3 Print
    printf("\n%s\n%s\n%s\n%s\n", songLine9, songLine10, songLine11, songLine12);

    // Unit Test 4 Print
    printf("\n%s\n%s\n%s\n%s\n%s\n", songLine13, songLine14, songLine15, songLine16, songLine17);

    return 0;
}
