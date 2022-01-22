# Demonstration of the python bindings for PRMan.
# https://renderman.pixar.com/resources/RenderMan_20/prmanForPython.html

import prman

# Access prman's procedures and definitions
ri = prman.Ri()


# Format the output for easier reading
ri.Option("rib", {"string asciistyle": "indented"})  

#ri.Begin('-')        # Echo rib, or
ri.Begin(ri.RENDER)   # render the scene

ri.Integrator("PxrVisualizer", "dl")
ri.Display("my_image", "framebuffer", "rgba")

ri.WorldBegin()
for n in range(1):
	# In effect this creates a new "group"
	ri.TransformBegin()

	# Add a sphere to the "group"
	ri.Sphere(1,-1,1,360)
	
	# Close the group
	ri.TransformEnd()

ri.WorldEnd()	
# Finally, tell prman we will not be adding anything
# more to the scene - Pixar's "prman" renderer will
# now render the scene or echo the rib statements.
ri.End()