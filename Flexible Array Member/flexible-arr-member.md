#Flexible Array Member(C99)

In a structure, the **last member** can be a flexible array, which means its size(assigned in `[]`) can be empty, and depends on later assignment.
A structure with flexible array member is used by defining a pointor of it, and `malloc()` the size of the struct plus the size of array for it. Then, you are allowed to use the array with the size you have mallocated.

See `flex-arr-member.c` for details.

*PS: mind the difference between an array pointor member and a flexible member( for example, different structure size ).* 
