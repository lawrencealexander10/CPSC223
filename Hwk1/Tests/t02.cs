char *hdr = "Simple comments"; //1
int main() { //2
    int c; //3
    int getchar(void);          // Read a char from stdin //4
    int putchar(int);           /* Write a char to stdout */ //5
    int EOF = -1;               // End-of-file indicator; */ ends comment, not! //6
    while ((c = getchar()) != EOF)      /* Copy chars from stdin to stdout
                                             until an EOF is encountered.  */ //7
        putchar (c); //8
    /* And having copied the file
       from stdin to stdout, we now */ return 0; //9
}
