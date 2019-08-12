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
#include <IFSelect_Transformer.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_Selection.hxx>
#include <IFSelect_Modifier.hxx>
#include <Interface_Graph.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_CopyTool.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_TransformStandard.hxx>
#include <Standard_Type.hxx>
#include <IFSelect_SequenceOfGeneralModifier.hxx>
#include <Interface_CopyControl.hxx>

void bind_IFSelect_TransformStandard(py::module &mod){

py::class_<IFSelect_TransformStandard, opencascade::handle<IFSelect_TransformStandard>, IFSelect_Transformer> cls_IFSelect_TransformStandard(mod, "IFSelect_TransformStandard", "This class runs transformations made by Modifiers, as the ModelCopier does when it produces files (the same set of Modifiers can then be used, as to transform the starting Model, as at file sending time).");

// Constructors
cls_IFSelect_TransformStandard.def(py::init<>());

// Fields

// Methods
cls_IFSelect_TransformStandard.def("SetCopyOption", (void (IFSelect_TransformStandard::*)(const Standard_Boolean)) &IFSelect_TransformStandard::SetCopyOption, "Sets the Copy option to a new value : - True for StandardCopy - False for OnTheSpot", py::arg("option"));
cls_IFSelect_TransformStandard.def("CopyOption", (Standard_Boolean (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::CopyOption, "Returns the Copy option");
cls_IFSelect_TransformStandard.def("SetSelection", (void (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_TransformStandard::SetSelection, "Sets a Selection (or unsets if Null) This Selection then defines the list of entities on which the Modifiers will be applied If it is set, it has priority on Selections of Modifiers Else, for each Modifier its Selection is evaluated By default, all the Model is taken", py::arg("sel"));
cls_IFSelect_TransformStandard.def("Selection", (opencascade::handle<IFSelect_Selection> (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::Selection, "Returns the Selection, Null by default");
cls_IFSelect_TransformStandard.def("NbModifiers", (Standard_Integer (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::NbModifiers, "Returns the count of recorded Modifiers");
cls_IFSelect_TransformStandard.def("Modifier", (opencascade::handle<IFSelect_Modifier> (IFSelect_TransformStandard::*)(const Standard_Integer) const) &IFSelect_TransformStandard::Modifier, "Returns a Modifier given its rank in the list", py::arg("num"));
cls_IFSelect_TransformStandard.def("ModifierRank", (Standard_Integer (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Modifier> &) const) &IFSelect_TransformStandard::ModifierRank, "Returns the rank of a Modifier in the list, 0 if unknown", py::arg("modif"));
cls_IFSelect_TransformStandard.def("AddModifier", [](IFSelect_TransformStandard &self, const opencascade::handle<IFSelect_Modifier> & a0) -> Standard_Boolean { return self.AddModifier(a0); });
cls_IFSelect_TransformStandard.def("AddModifier", (Standard_Boolean (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Modifier> &, const Standard_Integer)) &IFSelect_TransformStandard::AddModifier, "Adds a Modifier to the list : - <atnum> = 0 (default) : at the end of the list - <atnum> > 0 : at rank <atnum> Returns True if done, False if <atnum> is out of range", py::arg("modif"), py::arg("atnum"));
cls_IFSelect_TransformStandard.def("RemoveModifier", (Standard_Boolean (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Modifier> &)) &IFSelect_TransformStandard::RemoveModifier, "Removes a Modifier from the list Returns True if done, False if <modif> not in the list", py::arg("modif"));
cls_IFSelect_TransformStandard.def("RemoveModifier", (Standard_Boolean (IFSelect_TransformStandard::*)(const Standard_Integer)) &IFSelect_TransformStandard::RemoveModifier, "Removes a Modifier from the list, given its rank Returns True if done, False if <num> is out of range", py::arg("num"));
cls_IFSelect_TransformStandard.def("Perform", (Standard_Boolean (IFSelect_TransformStandard::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_TransformStandard::Perform, "Performs the Standard Transformation, by calling Copy then ApplyModifiers (which can return an error status)", py::arg("G"), py::arg("protocol"), py::arg("checks"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("Copy", (void (IFSelect_TransformStandard::*)(const Interface_Graph &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::Copy, "This the first operation. It calls StandardCopy or OnTheSpot according the option", py::arg("G"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("StandardCopy", (void (IFSelect_TransformStandard::*)(const Interface_Graph &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::StandardCopy, "This is the standard action of Copy : its takes into account only the remaining entities (noted by Graph Status positive) and their proper dependances of course. Produces a new model.", py::arg("G"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("OnTheSpot", (void (IFSelect_TransformStandard::*)(const Interface_Graph &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::OnTheSpot, "This is the OnTheSpot action : each entity is bound with ... itself. The produced model is the same as the starting one.", py::arg("G"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("ApplyModifiers", (Standard_Boolean (IFSelect_TransformStandard::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::ApplyModifiers, "Applies the modifiers sequencially. For each one, prepares required data (if a Selection is associated as a filter). For the option OnTheSpot, it determines if the graph may be changed and updates <newmod> if required If a Modifier causes an error (check 'HasFailed'), ApplyModifier stops : the following Modifiers are ignored", py::arg("G"), py::arg("protocol"), py::arg("TC"), py::arg("checks"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("Updated", (Standard_Boolean (IFSelect_TransformStandard::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IFSelect_TransformStandard::Updated, "This methods allows to know what happened to a starting entity after the last Perform. It reads result from the map which was filled by Perform.", py::arg("entfrom"), py::arg("entto"));
cls_IFSelect_TransformStandard.def("Label", (TCollection_AsciiString (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::Label, "Returns a text which defines the way a Transformer works : 'On the spot edition' or 'Standard Copy' followed by '<nn> Modifiers'");
cls_IFSelect_TransformStandard.def_static("get_type_name_", (const char * (*)()) &IFSelect_TransformStandard::get_type_name, "None");
cls_IFSelect_TransformStandard.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_TransformStandard::get_type_descriptor, "None");
cls_IFSelect_TransformStandard.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::DynamicType, "None");

// Enums

}