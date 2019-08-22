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
#include <Geom2dInt_IntConicCurveOfGInter.hxx>
#include <Standard.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepClass_Edge.hxx>
#include <gp_Dir2d.hxx>
#include <BRepClass_Intersector.hxx>

void bind_BRepClass_Intersector(py::module &mod){

py::class_<BRepClass_Intersector, Geom2dInt_IntConicCurveOfGInter> cls_BRepClass_Intersector(mod, "BRepClass_Intersector", "Intersect an Edge with a segment. Implement the Intersector2d required by the classifier.");

// Constructors
cls_BRepClass_Intersector.def(py::init<>());

// Fields

// Methods
// cls_BRepClass_Intersector.def_static("operator new_", (void * (*)(size_t)) &BRepClass_Intersector::operator new, "None", py::arg("theSize"));
// cls_BRepClass_Intersector.def_static("operator delete_", (void (*)(void *)) &BRepClass_Intersector::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_Intersector.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_Intersector::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_Intersector.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_Intersector::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_Intersector.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_Intersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_Intersector.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_Intersector::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_Intersector.def("Perform", (void (BRepClass_Intersector::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real, const BRepClass_Edge &)) &BRepClass_Intersector::Perform, "Intersect the line segment and the edge.", py::arg("L"), py::arg("P"), py::arg("Tol"), py::arg("E"));
cls_BRepClass_Intersector.def("LocalGeometry", [](BRepClass_Intersector &self, const BRepClass_Edge & E, const Standard_Real U, gp_Dir2d & T, gp_Dir2d & N, Standard_Real & C){ self.LocalGeometry(E, U, T, N, C); return C; }, "Returns in <T>, <N> and <C> the tangent, normal and curvature of the edge <E> at parameter value <U>.", py::arg("E"), py::arg("U"), py::arg("T"), py::arg("N"), py::arg("C"));

// Enums

}