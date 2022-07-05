# minirt
*The awesome, but mini, minirt!*

This project showcases how to create a simple ray-tracer in the C programming language. The main principle is simple:
For every pixel we cast a ray from the camera into the world, using equations to detect collision with predetermined objects. Then another ray is cast towards the lights to determine if the point of collision is lit and which color we should use to draw the pixel.

Ray-tracing has the potential to create very realistic images as it approximates the path a real photon could take. It is also incredibly handy to calculate reflections by ray-tracing.

minirt requires two submodules:
 * [MLX42](https://github.com/codam-coding-college/MLX42)
 * [libft](https://github.com/mjoosten42/libft)

## Compiling

Before being able to compile you need glfw, on Codam Mac's you can use Managed Software Center:

	Open MSC, search glfw and press install.

Or you can use Homebrew (the install.sh script does this for you):

	brew update
	brew install glfw

To compile in debug mode:
	
	make DEBUG=1

or if already made:

	make DEBUG=1 re

## Features:

### Camera

Every scene requires a camera. The camera is static and it's properties are determined in the scene file like this:

	C <position> <direction> <field_of_view>

**Example:**

	C 0,0,-10 0,0,1 90

### Unique shapes

There are 4 unique shapes to use with this raytracer: Sphere, plane, cylinder and cone.

(There are technically 5, considering the cylinder and cone also have a circle for their caps)

All shapes have their own intersection function.

In the scene files shapes are set up like this:

**Spheres:**

	sp <position> <diameter> <color> [material]

**Planes:**

	pl <position> <normal> <color> [material]

**Cylinders:**

	cy <position> <direction> <diameter> <height> <color> [material]

**Cones:**

	co <position> <direction> <diameter> <height> <color> [material]

**Examples:**

	sp 4,3,0       10       233,44,74   metal
	pl 0,-10,0     0,1,0    83,255,20
	cy 0,-6,0      0,1,1    5           20      120,120,120   glass
	co 0,12,0      0,-1,0   5           5       180,50,50     mirror

### Multiple spot lights

A simple feature to determine a pixel's color through multiple lights instead of one. The calculation is simple, it takes an equal fraction of every light.

In the scene files spot lights are set up like this:

	L <position> <intensity> <color>

Example of a green light:

	L 0,10,0 0.6 22,255,22

### Phong Lighting Model

The phong lighting model consists of three parts: Ambiant, diffuse and specular.

The ambient is the light that's always present in the scene, it simulates global illumination. In the scene files you can set the amount of ambient light like this:

	A <amount> <color>

Example for a rather red ambiance:

	A 0.35 255,66,66

Diffuse light is the amount of light an object gets from all light sources in the scene. Diffuse is calculated by the angle the ray has to make to get to the light. Higher angle means less light. Diffuse color mainly depends on the color of the object.

Specular light or reflection is the "shine" you get from the light reflecting on an object. The amount or spread of specular light depends on an object's material. It is calculated by determining the angle from the ray to the light and applying a quadratic function to it, which increases and/or decreases the size of the "shine" on the object. The specular color entirely depends on the color of the light.

Combining these three different forms of light is incredibly simple. You simply add them together:

	final_color = ambient + diffuse + specular

### Reflections

Reflections are relatively simple to calculate within a ray-tracer, you almost get them for free. Instead of stopping when you collide with an object that is reflective, you can instead calculate the angle of reflection and just continue casting the ray. This way the ray can "bounce" a lot of times and depending on the situation it can "bounce" indefinitely. To make sure the program doesn't stall we have set a limit on the amount of "bounces" a ray can do. (see include/config.h -> RAY_MAX_BOUNCES)

### Refraction

Realistic refraction is a bit more difficult to achieve considering the calculations are more complex than reflection, but the principle is simple. With refraction you calculate the angle of refraction through an equation and then, just like with reflections, just continue to cast the ray. This way the ray can continue to travel through an object that's refractive (like water or glass) while also simulating the effect of light bending through it.

### Multithreading

Ray-tracing calculations can be quite intensive. You have to cast a ray for every pixel and for every ray you have to do the collision calculations with additional reflection rays, refraction rays and rays to light-sources. Considering we do not use the GPU for the calculations it is incredible handy to utilize all cores of the CPU. This is why we implemented multi-threading. We simply split the load of all pixels across multiple threads. Every thread gets assigned an equal part of the screen to render. (number of threads can be changed in include/config.h -> NB_THREADS)

TODO:
 * Occasional vertical black line (planes colliding)