from OCCT.BRep import BRep_Builder
from OCCT.BRepTools import BRepTools
from OCCT.TopoDS import TopoDS_Shape


def write_brep(shape, fn):
    """
    Write a BREP file using the shape.
    """
    BRepTools.Write_(shape, fn)


def read_brep(fn):
    """
    Read a BREP file and return the shape.
    """
    shape = TopoDS_Shape()
    builder = BRep_Builder()
    BRepTools.Read_(shape, fn, builder)
    return shape
