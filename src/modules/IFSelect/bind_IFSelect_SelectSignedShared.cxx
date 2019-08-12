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
#include <IFSelect_SelectExplore.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_Signature.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Interface_Graph.hxx>
#include <Interface_EntityIterator.hxx>
#include <IFSelect_SelectSignedShared.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectSignedShared(py::module &mod){

py::class_<IFSelect_SelectSignedShared, opencascade::handle<IFSelect_SelectSignedShared>, IFSelect_SelectExplore> cls_IFSelect_SelectSignedShared(mod, "IFSelect_SelectSignedShared", "In the graph, explore the Shareds of the input entities, until it encounters some which match a given Signature (for a limited level, filters the returned list) By default, fitted for any level");

// Constructors
cls_IFSelect_SelectSignedShared.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignedShared.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));
cls_IFSelect_SelectSignedShared.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean, const Standard_Integer>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"), py::arg("level"));

// Fields

// Methods
cls_IFSelect_SelectSignedShared.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::Signature, "Returns the used Signature, then it is possible to access it, modify it as required");
cls_IFSelect_SelectSignedShared.def("SignatureText", (const TCollection_AsciiString & (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::SignatureText, "Returns Text used to Sort Entity on its Signature");
cls_IFSelect_SelectSignedShared.def("IsExact", (Standard_Boolean (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::IsExact, "Returns True if match must be exact");
cls_IFSelect_SelectSignedShared.def("Explore", (Standard_Boolean (IFSelect_SelectSignedShared::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IFSelect_SelectSignedShared::Explore, "Explores an entity : its Shared entities <ent> to take if it matches the Signature At level max, filters the result. Else gives all Shareds", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IFSelect_SelectSignedShared.def("ExploreLabel", (TCollection_AsciiString (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::ExploreLabel, "Returns a text defining the criterium. (it refers to the text and exact flag to be matched, and is qualified by the Name provided by the Signature)");
cls_IFSelect_SelectSignedShared.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSignedShared::get_type_name, "None");
cls_IFSelect_SelectSignedShared.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSignedShared::get_type_descriptor, "None");
cls_IFSelect_SelectSignedShared.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::DynamicType, "None");

// Enums

}