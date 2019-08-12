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
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Vec.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_LOD.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_Vrml_LOD(py::module &mod){

py::class_<Vrml_LOD, opencascade::handle<Vrml_LOD>, Standard_Transient> cls_Vrml_LOD(mod, "Vrml_LOD", "defines a LOD (level of detailization) node of VRML specifying properties of geometry and its appearance. This group node is used to allow applications to switch between various representations of objects automatically. The children of this node typically represent the same object or objects at the varying of Levels Of Detail (LOD), from highest detail to lowest.");

// Constructors
cls_Vrml_LOD.def(py::init<>());
cls_Vrml_LOD.def(py::init<const opencascade::handle<TColStd_HArray1OfReal> &, const gp_Vec &>(), py::arg("aRange"), py::arg("aCenter"));

// Fields

// Methods
cls_Vrml_LOD.def("SetRange", (void (Vrml_LOD::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Vrml_LOD::SetRange, "None", py::arg("aRange"));
cls_Vrml_LOD.def("Range", (opencascade::handle<TColStd_HArray1OfReal> (Vrml_LOD::*)() const) &Vrml_LOD::Range, "None");
cls_Vrml_LOD.def("SetCenter", (void (Vrml_LOD::*)(const gp_Vec &)) &Vrml_LOD::SetCenter, "None", py::arg("aCenter"));
cls_Vrml_LOD.def("Center", (gp_Vec (Vrml_LOD::*)() const) &Vrml_LOD::Center, "None");
cls_Vrml_LOD.def("Print", (Standard_OStream & (Vrml_LOD::*)(Standard_OStream &) const) &Vrml_LOD::Print, "None", py::arg("anOStream"));
cls_Vrml_LOD.def_static("get_type_name_", (const char * (*)()) &Vrml_LOD::get_type_name, "None");
cls_Vrml_LOD.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_LOD::get_type_descriptor, "None");
cls_Vrml_LOD.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_LOD::*)() const) &Vrml_LOD::DynamicType, "None");

// Enums

}