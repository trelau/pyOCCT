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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_Point.hxx>

void bind_BOPDS_Point(py::module &mod){

py::class_<BOPDS_Point, std::unique_ptr<BOPDS_Point, Deleter<BOPDS_Point>>> cls_BOPDS_Point(mod, "BOPDS_Point", "The class BOPDS_Point is to store the information about intersection point");

// Constructors
cls_BOPDS_Point.def(py::init<>());

// Fields

// Methods
// cls_BOPDS_Point.def_static("operator new_", (void * (*)(size_t)) &BOPDS_Point::operator new, "None", py::arg("theSize"));
// cls_BOPDS_Point.def_static("operator delete_", (void (*)(void *)) &BOPDS_Point::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_Point.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_Point::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_Point.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_Point::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_Point.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_Point::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_Point.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_Point::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_Point.def("SetPnt", (void (BOPDS_Point::*)(const gp_Pnt &)) &BOPDS_Point::SetPnt, "Modifier Sets 3D point <thePnt>", py::arg("thePnt"));
cls_BOPDS_Point.def("Pnt", (const gp_Pnt & (BOPDS_Point::*)() const) &BOPDS_Point::Pnt, "Selector Returns 3D point");
cls_BOPDS_Point.def("SetPnt2D1", (void (BOPDS_Point::*)(const gp_Pnt2d &)) &BOPDS_Point::SetPnt2D1, "Modifier Sets 2D point on the first face <thePnt>", py::arg("thePnt"));
cls_BOPDS_Point.def("Pnt2D1", (const gp_Pnt2d & (BOPDS_Point::*)() const) &BOPDS_Point::Pnt2D1, "Selector Returns 2D point on the first face <thePnt>");
cls_BOPDS_Point.def("SetPnt2D2", (void (BOPDS_Point::*)(const gp_Pnt2d &)) &BOPDS_Point::SetPnt2D2, "Modifier Sets 2D point on the second face <thePnt>", py::arg("thePnt"));
cls_BOPDS_Point.def("Pnt2D2", (const gp_Pnt2d & (BOPDS_Point::*)() const) &BOPDS_Point::Pnt2D2, "Selector Returns 2D point on the second face <thePnt>");
cls_BOPDS_Point.def("SetIndex", (void (BOPDS_Point::*)(const Standard_Integer)) &BOPDS_Point::SetIndex, "Modifier Sets the index of the vertex <theIndex>", py::arg("theIndex"));
cls_BOPDS_Point.def("Index", (Standard_Integer (BOPDS_Point::*)() const) &BOPDS_Point::Index, "Selector Returns index of the vertex");

// Enums

}