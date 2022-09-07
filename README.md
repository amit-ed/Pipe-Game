<h1>Pipe Game</h1>
<h4>By Amit Ein-Dor</h4>

<h2>General ideas and goals</h2>
A Pipe game which draw every pipe connected to the source
when the water get to the destination the level is over.
the problem is detecting all of the pipes connected to the source,
using the exception methods, iterator and sfml learned in class.

<h2>Files</h2>
<ul>
	<li>Controller - the operative class</li>
	<li>Object - any kind of pipe\source\destination, all the objects printed on the screen inherit from the basic object.</li>
	<li>Board - read from the file and convert the data to an array of objects</li>
	<li>Graph - another databes, holds objects and for each object hold a list of his neighbors to represent a graph, needed for algorithms.</li>
	<li>Textures - singelton, holds all the textures needed for the game</li>
</ul>

<h2>objects</h2>
<ul>
	<li>Rotatable - all objects that can be rotated inherit from it</li>
	<li>Blank - just take a spot on the screen, water dont flow through (can't connect to anyone)</li>
	<li>Pipe\Curved_pipe\Trai_pipe - kind of objects. (water flow through them)</li>
	<li>Source - everything connected to this object get water</li>
	<li>destination - when water flow to the dest the level is over</li>
</ul>

<h2>Data structures</h2>
<ul>
	<li>The Board object creates and holds a vector of Objects. the controller hold this vector and print it each round.</li>
	<li>Graph - a graph of Objects, represented by unordered map, the key is the Object
and every object has its list of neighbors 
(which are other objects that connected to this object and water can flow through).
</li>
</ul>

<h2>Algorithems that are worth mentioning</h2>
<p>DFS on the graph:</p>
<ul>
	<li>converting each valid route into a neighbor list (as stated before).</li>
	<li>by using RTTI I start the DFS only from a source object.</li>
	<li>the DFS will activate water flow through all of the objects that their 
     (graph)distance from the source isnt infinity (connect all object in route).</li>
	</ul>

<h2>Other notes</h2>
<ul>
	<li>the draw functions cannot be const because the tap_counter's draw cannot be const.</li>
	<li>you have to put a "map.txt" file that contain the maps, map size and list of neighbors is'nt needed.</li>
	<li>the log.txt file incase of a failure will be opened inside the out file.</li>
</ul>
