char *hdr = "String or char constant within comment, not!"; //1
char  aardvark, //2
     *barnacle = /* " starts a string and     */ "barnacle", //3
     *cardinal = /* ' starts a char constant, */ "cardinal", //4
     *devilray = /* not!                      */ "devilray"; //5
