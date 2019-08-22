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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepDS_Point.hxx>

void bind_TopOpeBRepDS_Point(py::module &mod){

py::class_<TopOpeBRepDS_Point> cls_TopOpeBRepDS_Point(mod, "TopOpeBRepDS_Point", "A Geom point and a tolerance.");

// Constructors
cls_TopOpeBRepDS_Point.def(py::init<>());
cls_TopOpeBRepDS_Point.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("P"), py::arg("T"));
cls_TopOpeBRepDS_Point.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_TopOpeBRepDS_Point.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Point::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Point.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Point::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Point.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Point::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Point.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Point::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Point.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Point::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Point.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Point::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Point.def("IsEqual", (Standard_Boolean (TopOpeBRepDS_Point::*)(const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_Point::IsEqual, "None", py::arg("other"));
cls_TopOpeBRepDS_Point.def("Point", (const gp_Pnt & (TopOpeBRepDS_Point::*)() const) &TopOpeBRepDS_Point::Point, "None");
cls_TopOpeBRepDS_Point.def("ChangePoint", (gp_Pnt & (TopOpeBRepDS_Point::*)()) &TopOpeBRepDS_Point::ChangePoint, "None");
cls_TopOpeBRepDS_Point.def("Tolerance", (Standard_Real (TopOpeBRepDS_Point::*)() const) &TopOpeBRepDS_Point::Tolerance, "None");
cls_TopOpeBRepDS_Point.def("Tolerance", (void (TopOpeBRepDS_Point::*)(const Standard_Real)) &TopOpeBRepDS_Point::Tolerance, "None", py::arg("Tol"));
cls_TopOpeBRepDS_Point.def("Keep", (Standard_Boolean (TopOpeBRepDS_Point::*)() const) &TopOpeBRepDS_Point::Keep, "None");
cls_TopOpeBRepDS_Point.def("ChangeKeep", (void (TopOpeBRepDS_Point::*)(const Standard_Boolean)) &TopOpeBRepDS_Point::ChangeKeep, "None", py::arg("B"));

// Enums

}