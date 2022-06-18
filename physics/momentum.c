#include <stdio.h>
#include <stdlib.h>
typedef struct s_object{
	int mass;
	int velocity;
} object;

void elastic_collision(object *obj1, object *obj2)
{
	int momentum1 = obj1->mass * obj1-> velocity;
	int momentum2 = obj2->mass * obj2-> velocity;
	obj2->velocity = momentum1 / obj2->mass;
	obj1->velocity = momentum2 / obj1->mass;
}

object *initialize(int mass, int vel)
{
	object *new = malloc(sizeof(object));
	new->mass = mass;
	new->velocity = vel;
	return new;
}

void print_status(object *obj)
{
	printf("mass = %i\n velocity = %i\n", obj->mass, obj->velocity);
}
int main()
{
	object *a1 = initialize(50, 4);
	object *a2 = initialize(100, 6);
	elastic_collision(a1, a2);
	print_status(a1);
	print_status(a2);

	return 0;
}
