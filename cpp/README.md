### Coming soon!

I'm working on converting all of the Python code into C++ Code.

See [tests.cpp](tests/tests.cpp) for progress (and broken stuff).

### Some Notes

* Need to restructure the way I store Games vs. Teams. They are both nodes.
This will solve some conflicts in [adj_list.cpp](includes/adj_list.cpp).

* Need to redo the [file_io.cpp](includes/file_io.cpp) to comply with standard C++ file I/O.

* Need to fix [graph.cpp](includes/graph.cpp) using std::map<> instead of Dict + string[]. This will make many things ([graph.cpp](includes/graph.cpp), [borie_rating_algorithm.cpp](includes/borie_rating_algorithm.cpp)) simpler.