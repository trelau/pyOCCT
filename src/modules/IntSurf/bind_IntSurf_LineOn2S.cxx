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
#include <Standard_Transient.hxx>
#include <IntSurf_Allocator.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Standard_Type.hxx>
#include <IntSurf_SequenceOfPntOn2S.hxx>

void bind_IntSurf_LineOn2S(py::module &mod){

py::class_<IntSurf_LineOn2S, opencascade::handle<IntSurf_LineOn2S>, Standard_Transient> cls_IntSurf_LineOn2S(mod, "IntSurf_LineOn2S", "None");

// Constructors
cls_IntSurf_LineOn2S.def(py::init<>());
cls_IntSurf_LineOn2S.def(py::init<const IntSurf_Allocator &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_IntSurf_LineOn2S.def("Add", (void (IntSurf_LineOn2S::*)(const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::Add, "Adds a point in the line.", py::arg("P"));
cls_IntSurf_LineOn2S.def("NbPoints", (Standard_Integer (IntSurf_LineOn2S::*)() const) &IntSurf_LineOn2S::NbPoints, "Returns the number of points in the line.");
cls_IntSurf_LineOn2S.def("Value", (const IntSurf_PntOn2S & (IntSurf_LineOn2S::*)(const Standard_Integer) const) &IntSurf_LineOn2S::Value, "Returns the point of range Index in the line.", py::arg("Index"));
cls_IntSurf_LineOn2S.def("Reverse", (void (IntSurf_LineOn2S::*)()) &IntSurf_LineOn2S::Reverse, "Reverses the order of points of the line.");
cls_IntSurf_LineOn2S.def("Split", (opencascade::handle<IntSurf_LineOn2S> (IntSurf_LineOn2S::*)(const Standard_Integer)) &IntSurf_LineOn2S::Split, "Keeps in <me> the points 1 to Index-1, and returns the items Index to the end.", py::arg("Index"));
cls_IntSurf_LineOn2S.def("Value", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::Value, "Replaces the point of range Index in the line.", py::arg("Index"), py::arg("P"));
cls_IntSurf_LineOn2S.def("SetUV", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_LineOn2S::SetUV, "Sets the parametric coordinates on one of the surfaces of the point of range Index in the line.", py::arg("Index"), py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_LineOn2S.def("Clear", (void (IntSurf_LineOn2S::*)()) &IntSurf_LineOn2S::Clear, "None");
cls_IntSurf_LineOn2S.def("InsertBefore", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::InsertBefore, "None", py::arg("I"), py::arg("P"));
cls_IntSurf_LineOn2S.def("RemovePoint", (void (IntSurf_LineOn2S::*)(const Standard_Integer)) &IntSurf_LineOn2S::RemovePoint, "None", py::arg("I"));
cls_IntSurf_LineOn2S.def_static("get_type_name_", (const char * (*)()) &IntSurf_LineOn2S::get_type_name, "None");
cls_IntSurf_LineOn2S.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntSurf_LineOn2S::get_type_descriptor, "None");
cls_IntSurf_LineOn2S.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntSurf_LineOn2S::*)() const) &IntSurf_LineOn2S::DynamicType, "None");

// Enums

}