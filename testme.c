#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function <-- you mean write
    //the numbers of characters you can print in ASCII are 32 to 128, this is how you randomize it for c in the testme() function
    char randomCharacters = rand() % (126-32) + 32;
    return randomCharacters;
}

char *inputString()
{
    // TODO: rewrite this function <-- you mean write
    //create a string of random length
    char *randomString = malloc(6 *sizeof(char));
    int index = 0;

    char randomCharacters[] = {'r', 'e', 's', 't', '\0'};

    //this loop loops 7 times to make a string from random characters r, e, s, t and a terminating null
    for(index = 0; index < 6; index++)
    {
        randomString[index] = randomCharacters[rand() % 5];
    }

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