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
#include <Vrml_IndexedLineSet.hxx>
#include <Standard_Type.hxx>

void bind_Vrml_IndexedLineSet(py::module &mod){

py::class_<Vrml_IndexedLineSet, opencascade::handle<Vrml_IndexedLineSet>, Standard_Transient> cls_Vrml_IndexedLineSet(mod, "Vrml_IndexedLineSet", "defines a IndexedLineSet node of VRML specifying geometry shapes. This node represents a 3D shape formed by constructing polylines from vertices located at the current coordinates. IndexedLineSet uses the indices in its coordIndex field to specify the polylines. An index of -1 separates one polyline from the next (thus, a final -1 is optional). the current polyline has ended and the next one begins. Treatment of the current material and normal binding is as follows: The PER_PART binding specifies a material or normal for each segment of the line. The PER_FACE binding specifies a material or normal for each polyline. PER_VERTEX specifies a material or normal for each vertex. The corresponding _INDEXED bindings are the same, but use the materialIndex or normalIndex indices. The DEFAULT material binding is equal to OVERALL. The DEFAULT normal binding is equal to PER_VERTEX_INDEXED; if insufficient normals exist in the state, the lines will be drawn unlit. The same rules for texture coordinate generation as IndexedFaceSet are used.");

// Constructors
cls_Vrml_IndexedLineSet.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &>(), py::arg("aCoordIndex"), py::arg("aMaterialIndex"), py::arg("aNormalIndex"), py::arg("aTextureCoordIndex"));
cls_Vrml_IndexedLineSet.def(py::init<>());

// Fields

// Methods
cls_Vrml_IndexedLineSet.def("SetCoordIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetCoordIndex, "None", py::arg("aCoordIndex"));
cls_Vrml_IndexedLineSet.def("CoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const) &Vrml_IndexedLineSet::CoordIndex, "None");
cls_Vrml_IndexedLineSet.def("SetMaterialIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetMaterialIndex, "None", py::arg("aMaterialIndex"));
cls_Vrml_IndexedLineSet.def("MaterialIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const) &Vrml_IndexedLineSet::MaterialIndex, "None");
cls_Vrml_IndexedLineSet.def("SetNormalIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetNormalIndex, "None", py::arg("aNormalIndex"));
cls_Vrml_IndexedLineSet.def("NormalIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const) &Vrml_IndexedLineSet::NormalIndex, "None");
cls_Vrml_IndexedLineSet.def("SetTextureCoordIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetTextureCoordIndex, "None", py::arg("aTextureCoordIndex"));
cls_Vrml_IndexedLineSet.def("TextureCoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const) &Vrml_IndexedLineSet::TextureCoordIndex, "None");
cls_Vrml_IndexedLineSet.def("Print", (Standard_OStream & (Vrml_IndexedLineSet::*)(Standard_OStream &) const) &Vrml_IndexedLineSet::Print, "None", py::arg("anOStream"));
cls_Vrml_IndexedLineSet.def_static("get_type_name_", (const char * (*)()) &Vrml_IndexedLineSet::get_type_name, "None");
cls_Vrml_IndexedLineSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_IndexedLineSet::get_type_descriptor, "None");
cls_Vrml_IndexedLineSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_IndexedLineSet::*)() const) &Vrml_IndexedLineSet::DynamicType, "None");

// Enums

}