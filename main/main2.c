#include "vec3.h"

#include <stdio.h>

int	main(void)
{


	t_v3	normal;

	normal = vec3_norm(vec3(-1,0,-1));

	double	lat;
	double	lon;

	lat = vec3_get_latitude(normal);
	lon = vec3_get_longitude(normal);

	printf("lat: %.3f, lon: %.3f\n", lat, lon);

	return (0);
}