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

void bind_BRepExtrema_SupportType(py::module &);
void bind_BRepExtrema_SolutionElem(py::module &);
void bind_BRepExtrema_SeqOfSolution(py::module &);
void bind_BRepExtrema_DistanceSS(py::module &);
void bind_BRepExtrema_DistShapeShape(py::module &);
void bind_BRepExtrema_ElementFilter(py::module &);
void bind_BRepExtrema_ExtCC(py::module &);
void bind_BRepExtrema_ExtCF(py::module &);
void bind_BRepExtrema_ExtFF(py::module &);
void bind_BRepExtrema_ExtPC(py::module &);
void bind_BRepExtrema_ExtPF(py::module &);
void bind_BRepExtrema_MapOfIntegerPackedMapOfInteger(py::module &);
void bind_BRepExtrema_ShapeList(py::module &);
void bind_BRepExtrema_TriangleSet(py::module &);
void bind_BRepExtrema_MapOfIntegerPackedMapOfInteger(py::module &);
void bind_BRepExtrema_OverlapTool(py::module &);
void bind_BRepExtrema_Poly(py::module &);
void bind_BRepExtrema_SelfIntersection(py::module &);
void bind_BRepExtrema_ShapeProximity(py::module &);
void bind_BRepExtrema_UnCompatibleShape(py::module &);

PYBIND11_MODULE(BRepExtrema, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.Precision");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.BVH");

bind_BRepExtrema_SupportType(mod);
bind_BRepExtrema_SolutionElem(mod);
bind_BRepExtrema_SeqOfSolution(mod);
bind_BRepExtrema_DistanceSS(mod);
bind_BRepExtrema_DistShapeShape(mod);
bind_BRepExtrema_ElementFilter(mod);
bind_BRepExtrema_ExtCC(mod);
bind_BRepExtrema_ExtCF(mod);
bind_BRepExtrema_ExtFF(mod);
bind_BRepExtrema_ExtPC(mod);
bind_BRepExtrema_ExtPF(mod);
bind_BRepExtrema_MapOfIntegerPackedMapOfInteger(mod);
bind_BRepExtrema_ShapeList(mod);
bind_BRepExtrema_TriangleSet(mod);
bind_BRepExtrema_MapOfIntegerPackedMapOfInteger(mod);
bind_BRepExtrema_OverlapTool(mod);
bind_BRepExtrema_Poly(mod);
bind_BRepExtrema_SelfIntersection(mod);
bind_BRepExtrema_ShapeProximity(mod);
bind_BRepExtrema_UnCompatibleShape(mod);

}
