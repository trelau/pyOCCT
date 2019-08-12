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

void bind_BRepOffset_Type(py::module &);
void bind_BRepOffset_Status(py::module &);
void bind_BRepOffset_Mode(py::module &);
void bind_BRepOffset_Error(py::module &);
void bind_BRepOffsetSimple_Status(py::module &);
void bind_BRepOffset_Interval(py::module &);
void bind_BRepOffset_ListOfInterval(py::module &);
void bind_BRepOffset_ListIteratorOfListOfInterval(py::module &);
void bind_BRepOffset_DataMapOfShapeListOfInterval(py::module &);
void bind_BRepOffset_DataMapIteratorOfDataMapOfShapeListOfInterval(py::module &);
void bind_BRepOffset_Analyse(py::module &);
void bind_BRepOffset_Offset(py::module &);
void bind_BRepOffset_DataMapOfShapeOffset(py::module &);
void bind_BRepOffset_DataMapIteratorOfDataMapOfShapeOffset(py::module &);
void bind_BRepOffset(py::module &);
void bind_BRepOffset_MakeLoops(py::module &);
void bind_BRepOffset_MakeOffset(py::module &);
void bind_BRepOffset_MakeSimpleOffset(py::module &);
void bind_BRepOffset_DataMapOfShapeMapOfShape(py::module &);
void bind_BRepOffset_DataMapIteratorOfDataMapOfShapeMapOfShape(py::module &);
void bind_BRepOffset_Inter2d(py::module &);
void bind_BRepOffset_Inter3d(py::module &);
void bind_BRepOffset_SimpleOffset(py::module &);
void bind_BRepOffset_Tool(py::module &);

PYBIND11_MODULE(BRepOffset, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepAlgo");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.ShapeBuild");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");

bind_BRepOffset_Type(mod);
bind_BRepOffset_Status(mod);
bind_BRepOffset_Mode(mod);
bind_BRepOffset_Error(mod);
bind_BRepOffsetSimple_Status(mod);
bind_BRepOffset_Interval(mod);
bind_BRepOffset_ListOfInterval(mod);
bind_BRepOffset_ListIteratorOfListOfInterval(mod);
bind_BRepOffset_DataMapOfShapeListOfInterval(mod);
bind_BRepOffset_DataMapIteratorOfDataMapOfShapeListOfInterval(mod);
bind_BRepOffset_Analyse(mod);
bind_BRepOffset_Offset(mod);
bind_BRepOffset_DataMapOfShapeOffset(mod);
bind_BRepOffset_DataMapIteratorOfDataMapOfShapeOffset(mod);
bind_BRepOffset(mod);
bind_BRepOffset_MakeLoops(mod);
bind_BRepOffset_MakeOffset(mod);
bind_BRepOffset_MakeSimpleOffset(mod);
bind_BRepOffset_DataMapOfShapeMapOfShape(mod);
bind_BRepOffset_DataMapIteratorOfDataMapOfShapeMapOfShape(mod);
bind_BRepOffset_Inter2d(mod);
bind_BRepOffset_Inter3d(mod);
bind_BRepOffset_SimpleOffset(mod);
bind_BRepOffset_Tool(mod);

}
