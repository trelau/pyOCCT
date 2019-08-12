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
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_IndexedFaceSet.hxx>
#include <Standard_Type.hxx>

void bind_Vrml_IndexedFaceSet(py::module &mod){

py::class_<Vrml_IndexedFaceSet, opencascade::handle<Vrml_IndexedFaceSet>, Standard_Transient> cls_Vrml_IndexedFaceSet(mod, "Vrml_IndexedFaceSet", "defines a IndexedFaceSet node of VRML specifying geometry shapes. This node represents a 3D shape formed by constructing faces (polygons) from vertices located at the current coordinates. IndexedFaceSet uses the indices in its coordIndex to define polygonal faces. An index of -1 separates faces (so a -1 at the end of the list is optional).");

// Constructors
cls_Vrml_IndexedFaceSet.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &>(), py::arg("aCoordIndex"), py::arg("aMaterialIndex"), py::arg("aNormalIndex"), py::arg("aTextureCoordIndex"));
cls_Vrml_IndexedFaceSet.def(py::init<>());

// Fields

// Methods
cls_Vrml_IndexedFaceSet.def("SetCoordIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetCoordIndex, "None", py::arg("aCoordIndex"));
cls_Vrml_IndexedFaceSet.def("CoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const) &Vrml_IndexedFaceSet::CoordIndex, "None");
cls_Vrml_IndexedFaceSet.def("SetMaterialIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetMaterialIndex, "None", py::arg("aMaterialIndex"));
cls_Vrml_IndexedFaceSet.def("MaterialIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const) &Vrml_IndexedFaceSet::MaterialIndex, "None");
cls_Vrml_IndexedFaceSet.def("SetNormalIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetNormalIndex, "None", py::arg("aNormalIndex"));
cls_Vrml_IndexedFaceSet.def("NormalIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const) &Vrml_IndexedFaceSet::NormalIndex, "None");
cls_Vrml_IndexedFaceSet.def("SetTextureCoordIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetTextureCoordIndex, "None", py::arg("aTextureCoordIndex"));
cls_Vrml_IndexedFaceSet.def("TextureCoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const) &Vrml_IndexedFaceSet::TextureCoordIndex, "None");
cls_Vrml_IndexedFaceSet.def("Print", (Standard_OStream & (Vrml_IndexedFaceSet::*)(Standard_OStream &) const) &Vrml_IndexedFaceSet::Print, "None", py::arg("anOStream"));
cls_Vrml_IndexedFaceSet.def_static("get_type_name_", (const char * (*)()) &Vrml_IndexedFaceSet::get_type_name, "None");
cls_Vrml_IndexedFaceSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_IndexedFaceSet::get_type_descriptor, "None");
cls_Vrml_IndexedFaceSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_IndexedFaceSet::*)() const) &Vrml_IndexedFaceSet::DynamicType, "None");

// Enums

}