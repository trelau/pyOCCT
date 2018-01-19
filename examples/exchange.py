from OCCT.BRep import BRep_Builder
from OCCT.BRepTools import BRepTools
from OCCT.STEPControl import STEPControl_Reader
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


def read_step(fn):
    """
    Read a STEP file and return the shape.
    """
    reader = STEPControl_Reader()
    reader.ReadFile(fn)
    reader.TransferRoots()
    return reader.OneShape()
