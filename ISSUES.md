# Known Issues
This is a summary of some known issues:

* Methods like `ShapeAnalysis_FreeBounds::ConnectEdgesToWires` take in a
  `TopTools_HSequenceOfShape` which is modified on the C++ side to contain the
  resulting wires. In the source, they use
  `owires = new TopTools_HSequenceOfShape` to I think clear the list. At this
  point I think this breaks the associativity to the Python variable as the
  provided variable is not changed. For now, this is avoided by using a lambda
  function in the bindings and the resulting wires are returned rather than
  modified as an input.
