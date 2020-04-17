#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void changeTColor(const char *color)
{
    if (strcmp(color, "red") == 0)     printf("%s", KRED);
    if (strcmp(color, "green") == 0)   printf("%s", KGRN);
    if (strcmp(color, "yellow") == 0)  printf("%s", KYEL);
    if (strcmp(color, "blue") == 0)    printf("%s", KBLU);
    if (strcmp(color, "magenta") == 0) printf("%s", KMAG);
    if (strcmp(color, "cyan") == 0)    printf("%s", KCYN);
    if (strcmp(color, "white") == 0)   printf("%s", KWHT);
    if (strcmp(color, "normal") == 0)  printf("%s", KNRM);
}