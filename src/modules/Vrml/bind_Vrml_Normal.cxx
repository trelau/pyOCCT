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
#include <TColgp_HArray1OfVec.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Normal.hxx>
#include <Standard_Type.hxx>

void bind_Vrml_Normal(py::module &mod){

py::class_<Vrml_Normal, opencascade::handle<Vrml_Normal>, Standard_Transient> cls_Vrml_Normal(mod, "Vrml_Normal", "defines a Normal node of VRML specifying properties of geometry and its appearance. This node defines a set of 3D surface normal vectors to be used by vertex-based shape nodes (IndexedFaceSet, IndexedLineSet, PointSet) that follow it in the scene graph. This node does not produce a visible result during rendering; it simply replaces the current normals in the rendering state for subsequent nodes to use. This node contains one multiple-valued field that contains the normal vectors.");

// Constructors
cls_Vrml_Normal.def(py::init<const opencascade::handle<TColgp_HArray1OfVec> &>(), py::arg("aVector"));
cls_Vrml_Normal.def(py::init<>());

// Fields

// Methods
cls_Vrml_Normal.def("SetVector", (void (Vrml_Normal::*)(const opencascade::handle<TColgp_HArray1OfVec> &)) &Vrml_Normal::SetVector, "None", py::arg("aVector"));
cls_Vrml_Normal.def("Vector", (opencascade::handle<TColgp_HArray1OfVec> (Vrml_Normal::*)() const) &Vrml_Normal::Vector, "None");
cls_Vrml_Normal.def("Print", (Standard_OStream & (Vrml_Normal::*)(Standard_OStream &) const) &Vrml_Normal::Print, "None", py::arg("anOStream"));
cls_Vrml_Normal.def_static("get_type_name_", (const char * (*)()) &Vrml_Normal::get_type_name, "None");
cls_Vrml_Normal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_Normal::get_type_descriptor, "None");
cls_Vrml_Normal.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_Normal::*)() const) &Vrml_Normal::DynamicType, "None");

// Enums

}