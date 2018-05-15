#FILE IO Advanced
|Function name|Description|
|-------------|-----------|
|`int ungetc(int c, FILE *fp)`|put `c` back to `instream`. (actually `c` is just simply put in the stream, no matter if is was in.)|
|`int fflush(FILE *fp)`|refers to *flushing a buffer*. (see *fflush()浅析*  and the examples for details)|
|`int setvbuf(FILE * fp, char * buf, int mode, size_t size`)| Substitute buffer with `buf` , which was declared in advance, whose size is `size`. If `buf` is `NULL` , a buffer of same size will be automatically generate by system. |
