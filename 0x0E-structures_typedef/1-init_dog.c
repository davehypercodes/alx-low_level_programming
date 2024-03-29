#include "dog.h"

/**
 * init_dog - initialize a variable of type struct dog
 * @d: pointer to struct dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	/* check if d is not NULL */
	if (d != NULL)
	{
		/* initialize the members of the struct */
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

