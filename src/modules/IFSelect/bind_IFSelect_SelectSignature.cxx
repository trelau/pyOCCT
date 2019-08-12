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
#include <IFSelect_SelectExtract.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_Signature.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SignCounter.hxx>
#include <Standard_Transient.hxx>
#include <Interface_Graph.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_SelectSignature.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_IFSelect_SelectSignature(py::module &mod){

py::class_<IFSelect_SelectSignature, opencascade::handle<IFSelect_SelectSignature>, IFSelect_SelectExtract> cls_IFSelect_SelectSignature(mod, "IFSelect_SelectSignature", "A SelectSignature sorts the Entities on a Signature Matching. The signature to match is given at creation time. Also, the required match is given at creation time : exact (IsEqual) or contains (the Type's Name must contain the criterium Text)");

// Constructors
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const TCollection_AsciiString &>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const TCollection_AsciiString &, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_SignCounter> &, const Standard_CString>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_SignCounter> &, const Standard_CString, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));

// Fields

// Methods
cls_IFSelect_SelectSignature.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::Signature, "Returns the used Signature, then it is possible to access it, modify it as required. Can be null, hence see Counter");
cls_IFSelect_SelectSignature.def("Counter", (opencascade::handle<IFSelect_SignCounter> (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::Counter, "Returns the used SignCounter. Can be used as alternative for Signature");
cls_IFSelect_SelectSignature.def("SortInGraph", (Standard_Boolean (IFSelect_SelectSignature::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &) const) &IFSelect_SelectSignature::SortInGraph, "Returns True for an Entity (model->Value(num)) of which the signature matches the text given as creation time May also work with a Counter from the Graph", py::arg("rank"), py::arg("ent"), py::arg("G"));
cls_IFSelect_SelectSignature.def("Sort", (Standard_Boolean (IFSelect_SelectSignature::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectSignature::Sort, "Not called, defined only to remove a deferred method here", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectSignature.def("SignatureText", (const TCollection_AsciiString & (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::SignatureText, "Returns Text used to Sort Entity on its Signature or SignCounter");
cls_IFSelect_SelectSignature.def("IsExact", (Standard_Boolean (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::IsExact, "Returns True if match must be exact");
cls_IFSelect_SelectSignature.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::ExtractLabel, "Returns a text defining the criterium. (it refers to the text and exact flag to be matched, and is qualified by the Name provided by the Signature)");
cls_IFSelect_SelectSignature.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSignature::get_type_name, "None");
cls_IFSelect_SelectSignature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSignature::get_type_descriptor, "None");
cls_IFSelect_SelectSignature.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::DynamicType, "None");

// Enums

}