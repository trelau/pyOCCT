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
#include <IFSelect_Dispatch.hxx>
#include <IFSelect_Selection.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_GeneralModifier(py::module &mod){

py::class_<IFSelect_GeneralModifier, opencascade::handle<IFSelect_GeneralModifier>, Standard_Transient> cls_IFSelect_GeneralModifier(mod, "IFSelect_GeneralModifier", "This class gives a frame for Actions which modify the effect of a Dispatch, i.e. : By Selections and Dispatches, an original Model can be splitted into one or more 'target' Models : these Models contain Entities copied from the original one (that is, a part of it). Basically, these dispatched Entities are copied as identical to their original counterparts. Also the copied Models reproduce the Header of the original one.");

// Fields

// Methods
cls_IFSelect_GeneralModifier.def("MayChangeGraph", (Standard_Boolean (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::MayChangeGraph, "Returns True if this modifier may change the graph of dependences (aknowledged at creation time)");
cls_IFSelect_GeneralModifier.def("SetDispatch", (void (IFSelect_GeneralModifier::*)(const opencascade::handle<IFSelect_Dispatch> &)) &IFSelect_GeneralModifier::SetDispatch, "Attaches to a Dispatch. If <disp> is Null, Resets it (to apply the Modifier on every Dispatch)", py::arg("disp"));
cls_IFSelect_GeneralModifier.def("Dispatch", (opencascade::handle<IFSelect_Dispatch> (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::Dispatch, "Returns the Dispatch to be matched, Null if not set");
cls_IFSelect_GeneralModifier.def("Applies", (Standard_Boolean (IFSelect_GeneralModifier::*)(const opencascade::handle<IFSelect_Dispatch> &) const) &IFSelect_GeneralModifier::Applies, "Returns True if a Model obtained from the Dispatch <disp> is to be treated (apart from the Selection criterium) If Dispatch(me) is Null, returns True. Else, checks <disp>", py::arg("disp"));
cls_IFSelect_GeneralModifier.def("SetSelection", (void (IFSelect_GeneralModifier::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_GeneralModifier::SetSelection, "Sets a Selection : a Model is treated if it contains one or more Entities designated by the Selection", py::arg("sel"));
cls_IFSelect_GeneralModifier.def("ResetSelection", (void (IFSelect_GeneralModifier::*)()) &IFSelect_GeneralModifier::ResetSelection, "Resets the Selection : this criterium is not longer active");
cls_IFSelect_GeneralModifier.def("HasSelection", (Standard_Boolean (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::HasSelection, "Returns True if a Selection is set as an additionnal criterium");
cls_IFSelect_GeneralModifier.def("Selection", (opencascade::handle<IFSelect_Selection> (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::Selection, "Returns the Selection, or a Null Handle if not set");
cls_IFSelect_GeneralModifier.def("Label", (TCollection_AsciiString (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::Label, "Returns a short text which defines the operation performed");
cls_IFSelect_GeneralModifier.def_static("get_type_name_", (const char * (*)()) &IFSelect_GeneralModifier::get_type_name, "None");
cls_IFSelect_GeneralModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_GeneralModifier::get_type_descriptor, "None");
cls_IFSelect_GeneralModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::DynamicType, "None");

// Enums

}