# BFS-Map-Routes
A simple implementation of Breadth-First Search to find routes on a map, written in C++.

Running the executable form command line: BFS \<filename\> \<base\> \<destination\>
  
The data file should contain one-way routes in the following fomat:
\<base\> \<destination\> \<distance\> \<displacement\>

Each line represents a new route

Example:

Oradea Zerind 71 374

Oradea Sibiu 151 253

Zerind Oradea 71 380

Zerind Arad 75 366

...

You can also add routes that are not traversable, which is identified by a negative distance value.
