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
#include <Interface_SignType.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_Signature.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_Signature(py::module &mod){

py::class_<IFSelect_Signature, opencascade::handle<IFSelect_Signature>, Interface_SignType> cls_IFSelect_Signature(mod, "IFSelect_Signature", "Signature provides the basic service used by the classes SelectSignature and Counter (i.e. Name, Value), which is : - for an entity in a model, give a characteristic string, its signature This string has not to be unique in the model, but gives a value for such or such important feature. Exemples : Dynamic Type; Category; etc");

// Fields

// Methods
cls_IFSelect_Signature.def("SetIntCase", (void (IFSelect_Signature::*)(const Standard_Boolean, const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &IFSelect_Signature::SetIntCase, "Sets the information data to tell 'integer cases' with possible min and max values To be called when creating", py::arg("hasmin"), py::arg("valmin"), py::arg("hasmax"), py::arg("valmax"));
cls_IFSelect_Signature.def("IsIntCase", [](IFSelect_Signature &self, Standard_Boolean & hasmin, Standard_Integer & valmin, Standard_Boolean & hasmax, Standard_Integer & valmax){ Standard_Boolean rv = self.IsIntCase(hasmin, valmin, hasmax, valmax); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Integer &, Standard_Boolean &, Standard_Integer &>(rv, hasmin, valmin, hasmax, valmax); }, "Tells if this Signature gives integer values and returns values from SetIntCase if True", py::arg("hasmin"), py::arg("valmin"), py::arg("hasmax"), py::arg("valmax"));
cls_IFSelect_Signature.def("AddCase", (void (IFSelect_Signature::*)(const Standard_CString)) &IFSelect_Signature::AddCase, "Adds a possible case To be called when creating, IF the list of possible cases for Value is known when starting For instance, for CDL types, rather do not fill this, but for a specific enumeration (such as a status), can be used", py::arg("acase"));
cls_IFSelect_Signature.def("CaseList", (opencascade::handle<TColStd_HSequenceOfAsciiString> (IFSelect_Signature::*)() const) &IFSelect_Signature::CaseList, "Returns the predefined list of possible cases, filled by AddCase Null Handle if no predefined list (hence, to be counted) Useful to filter on really possible vase, for instance, or for a help");
cls_IFSelect_Signature.def("Name", (Standard_CString (IFSelect_Signature::*)() const) &IFSelect_Signature::Name, "Returns an identification of the Signature (a word), given at initialization time Returns the Signature for a Transient object. It is specific of each sub-class of Signature. For a Null Handle, it should provide '' It can work with the model which contains the entity");
cls_IFSelect_Signature.def("Label", (TCollection_AsciiString (IFSelect_Signature::*)() const) &IFSelect_Signature::Label, "The label of a Signature uses its name as follow : 'Signature : <name>'");
cls_IFSelect_Signature.def("Matches", (Standard_Boolean (IFSelect_Signature::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IFSelect_Signature::Matches, "Tells if the value for <ent> in <model> matches a text, with a criterium <exact>. The default definition calls MatchValue Can be redefined", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IFSelect_Signature.def_static("MatchValue_", (Standard_Boolean (*)(const Standard_CString, const TCollection_AsciiString &, const Standard_Boolean)) &IFSelect_Signature::MatchValue, "Default procedure to tell if a value <val> matches a text with a criterium <exact>. <exact> = True requires equality, else only contained (no reg-exp)", py::arg("val"), py::arg("text"), py::arg("exact"));
cls_IFSelect_Signature.def_static("IntValue_", (Standard_CString (*)(const Standard_Integer)) &IFSelect_Signature::IntValue, "This procedure converts an Integer to a CString It is a convenient way when the value of a signature has the form of a simple integer value The value is to be used immediately (one buffer only, no copy)", py::arg("val"));
cls_IFSelect_Signature.def_static("get_type_name_", (const char * (*)()) &IFSelect_Signature::get_type_name, "None");
cls_IFSelect_Signature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Signature::get_type_descriptor, "None");
cls_IFSelect_Signature.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Signature::*)() const) &IFSelect_Signature::DynamicType, "None");

// Enums

}