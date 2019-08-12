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
#include <IFSelect_IntParam.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectRange.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectRange(py::module &mod){

py::class_<IFSelect_SelectRange, opencascade::handle<IFSelect_SelectRange>, IFSelect_SelectExtract> cls_IFSelect_SelectRange(mod, "IFSelect_SelectRange", "A SelectRange keeps or rejects a sub-set of the input set, that is the Entities of which rank in the iteration list is in a given range (for instance form 2nd to 6th, etc...)");

// Constructors
cls_IFSelect_SelectRange.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectRange.def("SetRange", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &, const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetRange, "Sets a Range for numbers, with a lower and a upper limits Error if rankto is lower then rankfrom", py::arg("rankfrom"), py::arg("rankto"));
cls_IFSelect_SelectRange.def("SetOne", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetOne, "Sets a unique number (only one Entity will be sorted as True)", py::arg("rank"));
cls_IFSelect_SelectRange.def("SetFrom", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetFrom, "Sets a Lower limit but no upper limit", py::arg("rankfrom"));
cls_IFSelect_SelectRange.def("SetUntil", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetUntil, "Sets an Upper limit but no lower limit (equivalent to lower 1)", py::arg("rankto"));
cls_IFSelect_SelectRange.def("HasLower", (Standard_Boolean (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::HasLower, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectRange.def("Lower", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::Lower, "Returns Lower limit (if there is; else, value is senseless)");
cls_IFSelect_SelectRange.def("LowerValue", (Standard_Integer (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::LowerValue, "Returns Value of Lower Limit (0 if none is defined)");
cls_IFSelect_SelectRange.def("HasUpper", (Standard_Boolean (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::HasUpper, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectRange.def("Upper", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::Upper, "Returns Upper limit (if there is; else, value is senseless)");
cls_IFSelect_SelectRange.def("UpperValue", (Standard_Integer (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::UpperValue, "Returns Value of Upper Limit (0 if none is defined)");
cls_IFSelect_SelectRange.def("Sort", (Standard_Boolean (IFSelect_SelectRange::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectRange::Sort, "Returns True for an Entity of which occurence number in the iteration is inside the selected Range (considers <rank>)", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectRange.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::ExtractLabel, "Returns a text defining the criterium : following cases, ' From .. Until ..' or 'From ..' or 'Until ..' or 'Rank no ..'");
cls_IFSelect_SelectRange.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectRange::get_type_name, "None");
cls_IFSelect_SelectRange.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectRange::get_type_descriptor, "None");
cls_IFSelect_SelectRange.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::DynamicType, "None");

// Enums

}