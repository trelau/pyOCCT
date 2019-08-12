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
#include <IFSelect_Signature.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SignMultiple.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_IFSelect_SignMultiple(py::module &mod){

py::class_<IFSelect_SignMultiple, opencascade::handle<IFSelect_SignMultiple>, IFSelect_Signature> cls_IFSelect_SignMultiple(mod, "IFSelect_SignMultiple", "Multiple Signature : ordered list of other Signatures It concatenates on a same line the result of its sub-items separated by sets of 3 blanks It is possible to define tabulations between sub-items Moreover, match rules are specific");

// Constructors
cls_IFSelect_SignMultiple.def(py::init<const Standard_CString>(), py::arg("name"));

// Fields

// Methods
cls_IFSelect_SignMultiple.def("Add", [](IFSelect_SignMultiple &self, const opencascade::handle<IFSelect_Signature> & a0) -> void { return self.Add(a0); });
cls_IFSelect_SignMultiple.def("Add", [](IFSelect_SignMultiple &self, const opencascade::handle<IFSelect_Signature> & a0, const Standard_Integer a1) -> void { return self.Add(a0, a1); });
cls_IFSelect_SignMultiple.def("Add", (void (IFSelect_SignMultiple::*)(const opencascade::handle<IFSelect_Signature> &, const Standard_Integer, const Standard_Boolean)) &IFSelect_SignMultiple::Add, "Adds a Signature. Width, if given, gives the tabulation If <maxi> is True, it is a forced tabulation (overlength is replaced by a final dot) If <maxi> is False, just 3 blanks follow an overlength", py::arg("subsign"), py::arg("width"), py::arg("maxi"));
cls_IFSelect_SignMultiple.def("Value", (Standard_CString (IFSelect_SignMultiple::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignMultiple::Value, "Concatenates the values of sub-signatures, with their tabulations", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignMultiple.def("Matches", (Standard_Boolean (IFSelect_SignMultiple::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IFSelect_SignMultiple::Matches, "Specialized Match Rule If <exact> is False, simply checks if at least one sub-item matches If <exact> is True, standard match with Value (i.e. tabulations must be respected)", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IFSelect_SignMultiple.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignMultiple::get_type_name, "None");
cls_IFSelect_SignMultiple.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignMultiple::get_type_descriptor, "None");
cls_IFSelect_SignMultiple.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignMultiple::*)() const) &IFSelect_SignMultiple::DynamicType, "None");

// Enums

}