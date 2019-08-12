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

void bind_BRepOffsetAPI_DraftAngle(py::module &);
void bind_BRepOffsetAPI_FindContigousEdges(py::module &);
void bind_BRepOffsetAPI_MakeDraft(py::module &);
void bind_BRepOffsetAPI_MakeEvolved(py::module &);
void bind_BRepOffsetAPI_MakeFilling(py::module &);
void bind_BRepOffsetAPI_MakeOffset(py::module &);
void bind_BRepOffsetAPI_MakeOffsetShape(py::module &);
void bind_BRepOffsetAPI_MakePipe(py::module &);
void bind_BRepOffsetAPI_MakePipeShell(py::module &);
void bind_BRepOffsetAPI_MakeThickSolid(py::module &);
void bind_BRepOffsetAPI_SequenceOfSequenceOfShape(py::module &);
void bind_BRepOffsetAPI_MiddlePath(py::module &);
void bind_BRepOffsetAPI_NormalProjection(py::module &);
void bind_BRepOffsetAPI_SequenceOfSequenceOfReal(py::module &);
void bind_BRepOffsetAPI_Sewing(py::module &);
void bind_BRepOffsetAPI_ThruSections(py::module &);

PYBIND11_MODULE(BRepOffsetAPI, mod) {

py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.Draft");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepFill");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepOffset");
py::module::import("OCCT.BRepPrimAPI");
py::module::import("OCCT.GeomFill");
py::module::import("OCCT.Law");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.BRepAlgo");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Approx");

bind_BRepOffsetAPI_DraftAngle(mod);
bind_BRepOffsetAPI_FindContigousEdges(mod);
bind_BRepOffsetAPI_MakeDraft(mod);
bind_BRepOffsetAPI_MakeEvolved(mod);
bind_BRepOffsetAPI_MakeFilling(mod);
bind_BRepOffsetAPI_MakeOffset(mod);
bind_BRepOffsetAPI_MakeOffsetShape(mod);
bind_BRepOffsetAPI_MakePipe(mod);
bind_BRepOffsetAPI_MakePipeShell(mod);
bind_BRepOffsetAPI_MakeThickSolid(mod);
bind_BRepOffsetAPI_SequenceOfSequenceOfShape(mod);
bind_BRepOffsetAPI_MiddlePath(mod);
bind_BRepOffsetAPI_NormalProjection(mod);
bind_BRepOffsetAPI_SequenceOfSequenceOfReal(mod);
bind_BRepOffsetAPI_Sewing(mod);
bind_BRepOffsetAPI_ThruSections(mod);

}
