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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <ShapeFix_ShapeTolerance.hxx>

void bind_ShapeFix_ShapeTolerance(py::module &mod){

py::class_<ShapeFix_ShapeTolerance, std::unique_ptr<ShapeFix_ShapeTolerance, Deleter<ShapeFix_ShapeTolerance>>> cls_ShapeFix_ShapeTolerance(mod, "ShapeFix_ShapeTolerance", "Modifies tolerances of sub-shapes (vertices, edges, faces)");

// Constructors
cls_ShapeFix_ShapeTolerance.def(py::init<>());

// Fields

// Methods
// cls_ShapeFix_ShapeTolerance.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_ShapeTolerance::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_ShapeTolerance.def_static("operator delete_", (void (*)(void *)) &ShapeFix_ShapeTolerance::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_ShapeTolerance.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_ShapeTolerance::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_ShapeTolerance.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_ShapeTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_ShapeTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_ShapeTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_ShapeTolerance.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_ShapeTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_ShapeTolerance.def("LimitTolerance", [](ShapeFix_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return self.LimitTolerance(a0, a1); });
cls_ShapeFix_ShapeTolerance.def("LimitTolerance", [](ShapeFix_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2) -> Standard_Boolean { return self.LimitTolerance(a0, a1, a2); });
cls_ShapeFix_ShapeTolerance.def("LimitTolerance", (Standard_Boolean (ShapeFix_ShapeTolerance::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const TopAbs_ShapeEnum) const) &ShapeFix_ShapeTolerance::LimitTolerance, "Limits tolerances in a shape as follows : tmin = tmax -> as SetTolerance (forces) tmin = 0 -> maximum tolerance will be <tmax> tmax = 0 or not given (more generally, tmax < tmin) -> <tmax> ignored, minimum will be <tmin> else, maximum will be <max> and minimum will be <min> styp = VERTEX : only vertices are set styp = EDGE : only edges are set styp = FACE : only faces are set styp = WIRE : to have edges and their vertices set styp = other value : all (vertices,edges,faces) are set Returns True if at least one tolerance of the sub-shape has been modified", py::arg("shape"), py::arg("tmin"), py::arg("tmax"), py::arg("styp"));
cls_ShapeFix_ShapeTolerance.def("SetTolerance", [](ShapeFix_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); });
cls_ShapeFix_ShapeTolerance.def("SetTolerance", (void (ShapeFix_ShapeTolerance::*)(const TopoDS_Shape &, const Standard_Real, const TopAbs_ShapeEnum) const) &ShapeFix_ShapeTolerance::SetTolerance, "Sets (enforces) tolerances in a shape to the given value styp = VERTEX : only vertices are set styp = EDGE : only edges are set styp = FACE : only faces are set styp = WIRE : to have edges and their vertices set styp = other value : all (vertices,edges,faces) are set", py::arg("shape"), py::arg("preci"), py::arg("styp"));

// Enums

}