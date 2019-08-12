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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_DimTol.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_DimTol(py::module &mod){

py::class_<XCAFDoc_DimTol, opencascade::handle<XCAFDoc_DimTol>, TDF_Attribute> cls_XCAFDoc_DimTol(mod, "XCAFDoc_DimTol", "attribute to store dimension and tolerance");

// Constructors
cls_XCAFDoc_DimTol.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_DimTol.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_DimTol::GetID, "None");
cls_XCAFDoc_DimTol.def_static("Set_", (opencascade::handle<XCAFDoc_DimTol> (*)(const TDF_Label &, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_DimTol::Set, "None", py::arg("label"), py::arg("kind"), py::arg("aVal"), py::arg("aName"), py::arg("aDescription"));
cls_XCAFDoc_DimTol.def("Set", (void (XCAFDoc_DimTol::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_DimTol::Set, "None", py::arg("kind"), py::arg("aVal"), py::arg("aName"), py::arg("aDescription"));
cls_XCAFDoc_DimTol.def("GetKind", (Standard_Integer (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetKind, "None");
cls_XCAFDoc_DimTol.def("GetVal", (opencascade::handle<TColStd_HArray1OfReal> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetVal, "None");
cls_XCAFDoc_DimTol.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetName, "None");
cls_XCAFDoc_DimTol.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetDescription, "None");
cls_XCAFDoc_DimTol.def("ID", (const Standard_GUID & (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::ID, "None");
cls_XCAFDoc_DimTol.def("Restore", (void (XCAFDoc_DimTol::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_DimTol::Restore, "None", py::arg("With"));
cls_XCAFDoc_DimTol.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::NewEmpty, "None");
cls_XCAFDoc_DimTol.def("Paste", (void (XCAFDoc_DimTol::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_DimTol::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_DimTol.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_DimTol::get_type_name, "None");
cls_XCAFDoc_DimTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_DimTol::get_type_descriptor, "None");
cls_XCAFDoc_DimTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::DynamicType, "None");

// Enums

}