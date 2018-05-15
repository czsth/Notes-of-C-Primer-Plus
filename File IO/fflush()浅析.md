#fflush()浅析
首先放上 `fflush()` 在 *cplusplus.com* 上的示例代码：
```
/* fflush example */
#include <stdio.h>
char mybuffer[80];
int main()
{
   FILE * pFile;
   pFile = fopen ("example.txt","r+");
   if (pFile == NULL) perror ("Error opening file");
   else {
     fputs ("test",pFile);
     fflush (pFile);    // flushing or repositioning required
     fgets (mybuffer,80,pFile);
     puts (mybuffer);
     fclose (pFile);
     return 0;
  }
}
```

此处之所以要用到 `fflush()` 是因为 `pFile` 作为一个 “update stream”（在文件打开时用了“r+”模式），在第10行进行了写操作后，缓冲区内存在”test“未被写入文件，如果此时紧接着进行读操作，程序 *似乎会出错（输出了一长串不存在的空格，文件里变成“test   (若干空格)”）* 。而 `fflush()` 在此处的作用就是将缓冲区数据写入文件，同时清空（刷新）缓冲区，这样就可以进行接下来的读操作了。

-----

**PS**: 

例1.我尝试用另一个指针也在 “r+” 模式下指向了同一文件（文件内容为”zzzzzzzz“）：

```
/* fflush example */
#include <stdio.h>
char mybuffer[80];
int main()
{
   FILE * pFile, *pf2;
   pf2 = fopen ("example.txt","r+");
   pFile = fopen ("example.txt","r+");
   if (pFile == NULL) perror ("Error opening file");
   else {
     fputs ("test",pFile);
     //fflush (pFile);    // flushing or repositioning required
     fgets (mybuffer,80,pf2);
     puts (mybuffer);
     fclose(pFile);
     fclose(pf2); 
     return 0;
  }
}
```
于是得到了这样的输出（记为输出一）：

```
zzzzzzzz\r
```
而再次打开 *example.txt* 则发现已经变为 “textzzzz”.

例2.将另一指针改为 “w+” 模式得到输出（注意另一指针赋值在原指针之前）（记为输出二）：

```
（若干空格）\r
```


由输出二可以断定：文件指针通过 `fopen()` 指向文件后并没有缓存操作，而是在进行IO操作时缓存区才被激活；那么，此时通过输出一，则更进一步验证了执行 `fputs()` 操作时数据并没有直接写入文件，而是停留在缓冲区中。实际上，例1中文件的修改是在 `fclose()` 时才进行的。