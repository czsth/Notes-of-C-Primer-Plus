#include <stdio.h>
struct point{
	double x, y;
};
void func(struct point a);

int main(int argc, char const *argv[])
{
	func((struct point){.x = 3, .y = 7});

	return 0;
}

void func(struct point a){
	printf("(%lf, %lf)\n", a.x, a.y);
}
