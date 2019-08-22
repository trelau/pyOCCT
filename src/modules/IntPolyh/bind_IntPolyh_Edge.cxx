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
#include <IntPolyh_Edge.hxx>

void bind_IntPolyh_Edge(py::module &mod){

py::class_<IntPolyh_Edge> cls_IntPolyh_Edge(mod, "IntPolyh_Edge", "The class represents the edge built between the two IntPolyh points. It is linked to two IntPolyh triangles.");

// Constructors
cls_IntPolyh_Edge.def(py::init<>());
cls_IntPolyh_Edge.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("theTriangle1"), py::arg("theTriangle2"));

// Fields

// Methods
// cls_IntPolyh_Edge.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_Edge::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_Edge.def_static("operator delete_", (void (*)(void *)) &IntPolyh_Edge::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_Edge.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_Edge::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_Edge.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_Edge::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_Edge.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_Edge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_Edge.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_Edge::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_Edge.def("FirstPoint", (Standard_Integer (IntPolyh_Edge::*)() const) &IntPolyh_Edge::FirstPoint, "Returns the first point");
cls_IntPolyh_Edge.def("SecondPoint", (Standard_Integer (IntPolyh_Edge::*)() const) &IntPolyh_Edge::SecondPoint, "Returns the second point");
cls_IntPolyh_Edge.def("FirstTriangle", (Standard_Integer (IntPolyh_Edge::*)() const) &IntPolyh_Edge::FirstTriangle, "Returns the first triangle");
cls_IntPolyh_Edge.def("SecondTriangle", (Standard_Integer (IntPolyh_Edge::*)() const) &IntPolyh_Edge::SecondTriangle, "Returns the second triangle");
cls_IntPolyh_Edge.def("SetFirstPoint", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetFirstPoint, "Sets the first point", py::arg("thePoint"));
cls_IntPolyh_Edge.def("SetSecondPoint", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetSecondPoint, "Sets the second point", py::arg("thePoint"));
cls_IntPolyh_Edge.def("SetFirstTriangle", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetFirstTriangle, "Sets the first triangle", py::arg("theTriangle"));
cls_IntPolyh_Edge.def("SetSecondTriangle", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetSecondTriangle, "Sets the second triangle", py::arg("theTriangle"));
cls_IntPolyh_Edge.def("Dump", (void (IntPolyh_Edge::*)(const Standard_Integer) const) &IntPolyh_Edge::Dump, "None", py::arg("v"));

// Enums

}