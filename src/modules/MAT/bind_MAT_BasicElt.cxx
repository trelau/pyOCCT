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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MAT_Arc.hxx>
#include <MAT_BasicElt.hxx>
#include <Standard_Type.hxx>

void bind_MAT_BasicElt(py::module &mod){

py::class_<MAT_BasicElt, opencascade::handle<MAT_BasicElt>, Standard_Transient> cls_MAT_BasicElt(mod, "MAT_BasicElt", "A BasicELt is associated to each elemtary constituant of the figure.");

// Constructors
cls_MAT_BasicElt.def(py::init<const Standard_Integer>(), py::arg("anInteger"));

// Fields

// Methods
cls_MAT_BasicElt.def("StartArc", (opencascade::handle<MAT_Arc> (MAT_BasicElt::*)() const) &MAT_BasicElt::StartArc, "Return <startArcLeft> or <startArcRight> corresponding to <aSide>.");
cls_MAT_BasicElt.def("EndArc", (opencascade::handle<MAT_Arc> (MAT_BasicElt::*)() const) &MAT_BasicElt::EndArc, "Return <endArcLeft> or <endArcRight> corresponding to <aSide>.");
cls_MAT_BasicElt.def("Index", (Standard_Integer (MAT_BasicElt::*)() const) &MAT_BasicElt::Index, "Return the <index> of <me> in Graph.TheBasicElts.");
cls_MAT_BasicElt.def("GeomIndex", (Standard_Integer (MAT_BasicElt::*)() const) &MAT_BasicElt::GeomIndex, "Return the <GeomIndex> of <me>.");
cls_MAT_BasicElt.def("SetStartArc", (void (MAT_BasicElt::*)(const opencascade::handle<MAT_Arc> &)) &MAT_BasicElt::SetStartArc, "None", py::arg("anArc"));
cls_MAT_BasicElt.def("SetEndArc", (void (MAT_BasicElt::*)(const opencascade::handle<MAT_Arc> &)) &MAT_BasicElt::SetEndArc, "None", py::arg("anArc"));
cls_MAT_BasicElt.def("SetIndex", (void (MAT_BasicElt::*)(const Standard_Integer)) &MAT_BasicElt::SetIndex, "None", py::arg("anInteger"));
cls_MAT_BasicElt.def("SetGeomIndex", (void (MAT_BasicElt::*)(const Standard_Integer)) &MAT_BasicElt::SetGeomIndex, "None", py::arg("anInteger"));
cls_MAT_BasicElt.def_static("get_type_name_", (const char * (*)()) &MAT_BasicElt::get_type_name, "None");
cls_MAT_BasicElt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_BasicElt::get_type_descriptor, "None");
cls_MAT_BasicElt.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_BasicElt::*)() const) &MAT_BasicElt::DynamicType, "None");

// Enums

}