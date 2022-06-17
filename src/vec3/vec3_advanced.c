/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_advanced.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:06:03 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/17 14:08:48 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_v3	vec3_calc_reflection(t_v3 incoming, t_v3 normal)
{
	t_v3	refl;

	refl = vec3_sub(incoming,
			vec3_mul(vec3_mul(normal, vec3_dot(incoming, normal)), 2));
	return (refl);
}

/*
inline void Refract(
  VEC3 &out, const VEC3 &incidentVec, const VEC3 &normal, float eta)
{
  float N_dot_I = Dot(normal, incidentVec);
  float k = 1.f - eta * eta * (1.f - N_dot_I * N_dot_I);
  if (k < 0.f)
    out = VEC3(0.f, 0.f, 0.f);
  else
    out = eta * incidentVec - (eta * N_dot_I + sqrtf(k)) * normal;
}
*/
/*
Vec3 computeRefraction(const Vec3& I, const Vec3& N, const float &ior, Vec3& intersection) {
    Vec3 normal = N; normal.normalize();
    normal = normal;
    Vec3 incident = I; incident.normalize();
    float cosi = incident.dot(normal);
    float n1, n2;
    if (cosi > 0.0f) { 
        //Incident and normal have same direction, INSIDE sphere
        n1 = ior;
        n2 = 1.0f;
        normal = -normal;
    } else { 
        //Incident and normal have opposite direction, OUTSIDE sphere
        n1 = 1.0f;
        n2 = ior;
        cosi = -cosi;
    }

    float eta = n1 / n2;
    float k = 1.0f - (eta * eta) * (1.0f - cosi * cosi);

    if (k < 0.0f) {   
        //internal reflection
        Vec3 reflectionRay = computeReflection(incident, normal);
        intersection = intersection + (normal * BIAS);
        return reflectionRay;
    } else {
        Vec3 refractionVector = incident * eta + normal * (eta * cosi - sqrt(k));
        refractionVector.normalize();
        intersection = intersection - (normal * BIAS);
        return refractionVector;
    }
}
*/

t_v3	vec3_calc_refraction(t_v3 incoming, t_v3 normal, double strength)
{
	double	cosi;
	double	n1;
	double	n2;
	double	eta;
	double	k;
	t_v3	refr;

	cosi = vec3_dot(incoming, normal);
	if (cosi > 0.0f)
	{
		n1 = strength;
		n2 = 1.0;
		normal = vec3_inv(normal);
	}
	else
	{
		n1 = 1.0;
		n2 = strength;
		cosi = -cosi;
	}
	eta = n1 / n2;
	k = 1.0 - (eta * eta) * (1.0 - cosi * cosi);
	if (k < 0.0)
		refr = vec3_calc_reflection(incoming, normal);
	else
		refr = vec3_add( vec3_mul(incoming, eta), vec3_mul(normal, eta * cosi * sqrt(k)) );
	return (refr);
}

double	vec3_angle(t_v3 v1, t_v3 v2)
{
	return (acos(vec3_dot(v1, v2) / (vec3_length(v1) * vec3_length(v2))));
}

double	vec3_distance(t_v3 v1, t_v3 v2)
{
	return (vec3_length(vec3_sub(v1, v2)));
}

t_v3	vec3_project(t_v3 v1, t_v3 v2)
{
	return (vec3_mul(v2, vec3_dot(v1, v2) / vec3_dot(v2, v2)));
}
