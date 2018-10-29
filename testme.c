#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function <-- you mean write
    //the numbers of characters you can print in ASCII are 32 to 127, I did some asking around and this is how you would randomize it for the correct number of ASCII characters
    char randomCharacters = rand() % (128-32) + 32;
    return randomCharacters;
}

char *inputString()
{
    // TODO: rewrite this function <-- you mean write
    //create a string of random length
    int stringLength = rand() % (15-3) + 3;
    char *randomString = malloc(stringLength * sizeof(char));

    //have the array be filled with characters
    int index;
    int randomCharacters;
    for(index = 0; index < (stringLength - 1); index++) {
      randomCharacters = inputChar();
      randomString[index] = randomCharacters;
    }
    randomString[stringLength] = '\0';
    return randomString;
}

//tests the random character generator! it does crazy stuff!
void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
