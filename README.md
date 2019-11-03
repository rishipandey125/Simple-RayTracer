# RayTracer
RayTracer built from scratch in C++ implementing phong shading and shadows on spheres. I developed this project to learn more about computer graphics in film. 

![Cover](/imgs/cover.png)

# Cartesian Coordinate System, Sphere Objects, Point Lights and Shading
Sphere objects and point lights can move along the xyz axes.
+x -> moving right,
+y -> moving up,
+z -> out of the screen.
In the context of the project, spheres have a radius, cartesian center point, and color.
Point lights are represented as a point object. 
Shading of the spheres is done using the phong shading model where ks = 0.2 and n = 200 for specular lighting. These values can be modified based on the desired look.
Shadows are calculated using the discriminant method. 

# More Complex Scene
Let's add a few more spheres to create a more complex scene. The spheres in this scene all have the same radius, but differ in depth. The point light in this scene is left of the front center sphere at point (600,800,400).
The (width,height,depth) of the scene is (1500,1000,-1500).

![b1](/imgs/b1.png)

# Transforming Spheres
We can make this scene more interesting by raising two spheres, and casting more shadows. 
This next render has the teal and red spheres shrinking by 25% and moving up 200 units. 

![b2](/imgs/b2.png)

Yay! However, it is hard to see the orange sphere as it is cast in the shadow of the red sphere. Let's move it right 100 units, so it is still partially visible in the scene. 

![b3](/imgs/b3.png)

Let's move the blue sphere back some more in the scene, about 600 units.

![b4](/imgs/b4.png)

Lastly for fun we can add another point light to the scene to increase the brightness of each sphere and create some more complex shadows. Second point light at (900,800,400).

![b5](/imgs/b5.png)

Cool stuff! Excited to add more to this project (animations, reflections, shaders etc.) and learn more about building a career in film and animation. 
