# minirt
The awesome, but mini, minirt!

## Compiling:
	
Before being able to compile you need glfw, on Codam Mac's you can use Managed Software Center:

	Open MSC, search glfw and press install.

Or you can use Homebrew:

	brew update
	brew install glfw

To compile in debug mode:
	
	make DEBUG=1

or if already made:

	make DEBUG=1 re


## Features:
### Unique shapes

There are 4 unique shapes to use with this raytracer: Sphere, plane, cylinder and cone.

(There are technically 5, considering the cylinder and cone also have a circle for their caps)

All shapes have their own intersection function.

In the scene files shapes are set up like this:

Spheres:

	sp <position> <diameter> <color> [material]

Planes:

	pl <position> <normal> <color> [material]

Cylinders:

	cy <position> <direction> <diameter> <height> <color> [material]

Cones:

	co <position> <direction> <diameter> <height> <color> [material]

Examples:

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

TODO:
 * Occasional vertical black line (planes colliding)