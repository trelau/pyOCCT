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

void bind_LocOpe_Operation(py::module &);
void bind_LocOpe_Gluer(py::module &);
void bind_LocOpe_Spliter(py::module &);
void bind_LocOpe_WiresOnShape(py::module &);
void bind_LocOpe(py::module &);
void bind_LocOpe_BuildShape(py::module &);
void bind_LocOpe_BuildWires(py::module &);
void bind_LocOpe_SequenceOfLin(py::module &);
void bind_LocOpe_SequenceOfCirc(py::module &);
void bind_LocOpe_CSIntersector(py::module &);
void bind_LocOpe_PntFace(py::module &);
void bind_LocOpe_SequenceOfPntFace(py::module &);
void bind_LocOpe_CurveShapeIntersector(py::module &);
void bind_LocOpe_DataMapOfShapePnt(py::module &);
void bind_LocOpe_DataMapIteratorOfDataMapOfShapePnt(py::module &);
void bind_LocOpe_DPrism(py::module &);
void bind_LocOpe_FindEdges(py::module &);
void bind_LocOpe_FindEdgesInFace(py::module &);
void bind_LocOpe_GeneratedShape(py::module &);
void bind_LocOpe_Generator(py::module &);
void bind_LocOpe_GluedShape(py::module &);
void bind_LocOpe_LinearForm(py::module &);
void bind_LocOpe_Pipe(py::module &);
void bind_LocOpe_Prism(py::module &);
void bind_LocOpe_Revol(py::module &);
void bind_LocOpe_RevolutionForm(py::module &);
void bind_LocOpe_SplitDrafts(py::module &);
void bind_LocOpe_SplitShape(py::module &);

PYBIND11_MODULE(LocOpe, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepFill");

bind_LocOpe_Operation(mod);
bind_LocOpe_Gluer(mod);
bind_LocOpe_Spliter(mod);
bind_LocOpe_WiresOnShape(mod);
bind_LocOpe(mod);
bind_LocOpe_BuildShape(mod);
bind_LocOpe_BuildWires(mod);
bind_LocOpe_SequenceOfLin(mod);
bind_LocOpe_SequenceOfCirc(mod);
bind_LocOpe_CSIntersector(mod);
bind_LocOpe_PntFace(mod);
bind_LocOpe_SequenceOfPntFace(mod);
bind_LocOpe_CurveShapeIntersector(mod);
bind_LocOpe_DataMapOfShapePnt(mod);
bind_LocOpe_DataMapIteratorOfDataMapOfShapePnt(mod);
bind_LocOpe_DPrism(mod);
bind_LocOpe_FindEdges(mod);
bind_LocOpe_FindEdgesInFace(mod);
bind_LocOpe_GeneratedShape(mod);
bind_LocOpe_Generator(mod);
bind_LocOpe_GluedShape(mod);
bind_LocOpe_LinearForm(mod);
bind_LocOpe_Pipe(mod);
bind_LocOpe_Prism(mod);
bind_LocOpe_Revol(mod);
bind_LocOpe_RevolutionForm(mod);
bind_LocOpe_SplitDrafts(mod);
bind_LocOpe_SplitShape(mod);

}
