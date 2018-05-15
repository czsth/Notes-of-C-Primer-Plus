#The Macro NDEBUG

What I want to mark down is the macro `NDEBUG` , as it was define in the header `assert.h` that:

```
#ifdef NDEBUG
	#define assert(condition) ((void)0)
#else
	#define assert(condition) /*implementation defined*/
#endif
```
Which meas, if defined `NDEBUG` before including `assert.h` , `assert()` dose nothing.