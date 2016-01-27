char *hdr = "Code, string, and char constant; no comments"; //1
int main() //2
{
    char c = '!'; //3
    int greet (char *, char); //4
    greet ("Hello world%c\n", c); //5
    return 0; //6
}
