/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

void bind_BRepFill_TransitionStyle(py::module &);
void bind_BRepFill_TypeOfContact(py::module &);
void bind_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape(py::module &);
void bind_BRepFill_DataMapIteratorOfDataMapOfShapeDataMapOfShapeListOfShape(py::module &);
void bind_BRepFill(py::module &);
void bind_BRepFill_LocationLaw(py::module &);
void bind_BRepFill_ACRLaw(py::module &);
void bind_BRepFill_MultiLine(py::module &);
void bind_BRepFill_ApproxSeewing(py::module &);
void bind_BRepFill_CompatibleWires(py::module &);
void bind_BRepFill_ComputeCLine(py::module &);
void bind_BRepFill_CurveConstraint(py::module &);
void bind_BRepFill_DataMapOfNodeDataMapOfShapeShape(py::module &);
void bind_BRepFill_DataMapIteratorOfDataMapOfNodeDataMapOfShapeShape(py::module &);
void bind_BRepFill_DataMapOfNodeShape(py::module &);
void bind_BRepFill_DataMapIteratorOfDataMapOfNodeShape(py::module &);
void bind_BRepFill_DataMapOfOrientedShapeListOfShape(py::module &);
void bind_BRepFill_DataMapIteratorOfDataMapOfOrientedShapeListOfShape(py::module &);
void bind_BRepFill_DataMapOfShapeHArray2OfShape(py::module &);
void bind_BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape(py::module &);
void bind_BRepFill_DataMapOfShapeSequenceOfPnt(py::module &);
void bind_BRepFill_DataMapIteratorOfDataMapOfShapeSequenceOfPnt(py::module &);
void bind_BRepFill_DataMapOfShapeSequenceOfReal(py::module &);
void bind_BRepFill_DataMapIteratorOfDataMapOfShapeSequenceOfReal(py::module &);
void bind_BRepFill_Draft(py::module &);
void bind_BRepFill_Edge3DLaw(py::module &);
void bind_BRepFill_DraftLaw(py::module &);
void bind_BRepFill_EdgeFaceAndOrder(py::module &);
void bind_BRepFill_EdgeOnSurfLaw(py::module &);
void bind_BRepFill_Evolved(py::module &);
void bind_BRepFill_FaceAndOrder(py::module &);
void bind_BRepFill_SequenceOfEdgeFaceAndOrder(py::module &);
void bind_BRepFill_SequenceOfFaceAndOrder(py::module &);
void bind_BRepFill_Filling(py::module &);
void bind_BRepFill_Generator(py::module &);
void bind_BRepFill_IndexedDataMapOfOrientedShapeListOfShape(py::module &);
void bind_BRepFill_OffsetWire(py::module &);
void bind_BRepFill_ListOfOffsetWire(py::module &);
void bind_BRepFill_ListIteratorOfListOfOffsetWire(py::module &);
void bind_BRepFill_SectionLaw(py::module &);
void bind_BRepFill_NSections(py::module &);
void bind_BRepFill_OffsetAncestors(py::module &);
void bind_BRepFill_Pipe(py::module &);
void bind_BRepFill_Section(py::module &);
void bind_BRepFill_SequenceOfSection(py::module &);
void bind_BRepFill_PipeShell(py::module &);
void bind_BRepFill_SectionPlacement(py::module &);
void bind_BRepFill_ShapeLaw(py::module &);
void bind_BRepFill_Sweep(py::module &);
void bind_BRepFill_TrimEdgeTool(py::module &);
void bind_BRepFill_TrimShellCorner(py::module &);
void bind_BRepFill_TrimSurfaceTool(py::module &);

PYBIND11_MODULE(BRepFill, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomFill");
py::module::import("OCCT.AppCont");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.AppParCurves");
py::module::import("OCCT.GeomPlate");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.MAT");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.BRepMAT2d");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Bisector");
py::module::import("OCCT.Law");
py::module::import("OCCT.BOPDS");

bind_BRepFill_TransitionStyle(mod);
bind_BRepFill_TypeOfContact(mod);
bind_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape(mod);
bind_BRepFill_DataMapIteratorOfDataMapOfShapeDataMapOfShapeListOfShape(mod);
bind_BRepFill(mod);
bind_BRepFill_LocationLaw(mod);
bind_BRepFill_ACRLaw(mod);
bind_BRepFill_MultiLine(mod);
bind_BRepFill_ApproxSeewing(mod);
bind_BRepFill_CompatibleWires(mod);
bind_BRepFill_ComputeCLine(mod);
bind_BRepFill_CurveConstraint(mod);
bind_BRepFill_DataMapOfNodeDataMapOfShapeShape(mod);
bind_BRepFill_DataMapIteratorOfDataMapOfNodeDataMapOfShapeShape(mod);
bind_BRepFill_DataMapOfNodeShape(mod);
bind_BRepFill_DataMapIteratorOfDataMapOfNodeShape(mod);
bind_BRepFill_DataMapOfOrientedShapeListOfShape(mod);
bind_BRepFill_DataMapIteratorOfDataMapOfOrientedShapeListOfShape(mod);
bind_BRepFill_DataMapOfShapeHArray2OfShape(mod);
bind_BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape(mod);
bind_BRepFill_DataMapOfShapeSequenceOfPnt(mod);
bind_BRepFill_DataMapIteratorOfDataMapOfShapeSequenceOfPnt(mod);
bind_BRepFill_DataMapOfShapeSequenceOfReal(mod);
bind_BRepFill_DataMapIteratorOfDataMapOfShapeSequenceOfReal(mod);
bind_BRepFill_Draft(mod);
bind_BRepFill_Edge3DLaw(mod);
bind_BRepFill_DraftLaw(mod);
bind_BRepFill_EdgeFaceAndOrder(mod);
bind_BRepFill_EdgeOnSurfLaw(mod);
bind_BRepFill_Evolved(mod);
bind_BRepFill_FaceAndOrder(mod);
bind_BRepFill_SequenceOfEdgeFaceAndOrder(mod);
bind_BRepFill_SequenceOfFaceAndOrder(mod);
bind_BRepFill_Filling(mod);
bind_BRepFill_Generator(mod);
bind_BRepFill_IndexedDataMapOfOrientedShapeListOfShape(mod);
bind_BRepFill_OffsetWire(mod);
bind_BRepFill_ListOfOffsetWire(mod);
bind_BRepFill_ListIteratorOfListOfOffsetWire(mod);
bind_BRepFill_SectionLaw(mod);
bind_BRepFill_NSections(mod);
bind_BRepFill_OffsetAncestors(mod);
bind_BRepFill_Pipe(mod);
bind_BRepFill_Section(mod);
bind_BRepFill_SequenceOfSection(mod);
bind_BRepFill_PipeShell(mod);
bind_BRepFill_SectionPlacement(mod);
bind_BRepFill_ShapeLaw(mod);
bind_BRepFill_Sweep(mod);
bind_BRepFill_TrimEdgeTool(mod);
bind_BRepFill_TrimShellCorner(mod);
bind_BRepFill_TrimSurfaceTool(mod);

}
