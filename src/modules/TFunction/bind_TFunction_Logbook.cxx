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
#include <Standard_Handle.hxx>
#include <TFunction_Logbook.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>

void bind_TFunction_Logbook(py::module &mod){

py::class_<TFunction_Logbook, opencascade::handle<TFunction_Logbook>, TDF_Attribute> cls_TFunction_Logbook(mod, "TFunction_Logbook", "This class contains information which is written and read during the solving process. Information is divided in three groups.");

// Constructors
cls_TFunction_Logbook.def(py::init<>());

// Fields

// Methods
cls_TFunction_Logbook.def_static("Set_", (opencascade::handle<TFunction_Logbook> (*)(const TDF_Label &)) &TFunction_Logbook::Set, "Finds or Creates a TFunction_Logbook attribute at the root label accessed by <Access>. Returns the attribute.", py::arg("Access"));
cls_TFunction_Logbook.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Logbook::GetID, "Returns the GUID for logbook attribute.");
cls_TFunction_Logbook.def("Clear", (void (TFunction_Logbook::*)()) &TFunction_Logbook::Clear, "Clears this logbook to its default, empty state.");
cls_TFunction_Logbook.def("IsEmpty", (Standard_Boolean (TFunction_Logbook::*)() const) &TFunction_Logbook::IsEmpty, "None");
cls_TFunction_Logbook.def("SetTouched", (void (TFunction_Logbook::*)(const TDF_Label &)) &TFunction_Logbook::SetTouched, "Sets the label L as a touched label in this logbook. In other words, L is understood to have been modified by the end user.", py::arg("L"));
cls_TFunction_Logbook.def("SetImpacted", [](TFunction_Logbook &self, const TDF_Label & a0) -> void { return self.SetImpacted(a0); });
cls_TFunction_Logbook.def("SetImpacted", (void (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean)) &TFunction_Logbook::SetImpacted, "Sets the label L as an impacted label in this logbook. This method is called by execution of the function driver.", py::arg("L"), py::arg("WithChildren"));
cls_TFunction_Logbook.def("SetValid", [](TFunction_Logbook &self, const TDF_Label & a0) -> void { return self.SetValid(a0); });
cls_TFunction_Logbook.def("SetValid", (void (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean)) &TFunction_Logbook::SetValid, "Sets the label L as a valid label in this logbook.", py::arg("L"), py::arg("WithChildren"));
cls_TFunction_Logbook.def("SetValid", (void (TFunction_Logbook::*)(const TDF_LabelMap &)) &TFunction_Logbook::SetValid, "None", py::arg("Ls"));
cls_TFunction_Logbook.def("IsModified", [](TFunction_Logbook &self, const TDF_Label & a0) -> Standard_Boolean { return self.IsModified(a0); });
cls_TFunction_Logbook.def("IsModified", (Standard_Boolean (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean) const) &TFunction_Logbook::IsModified, "Returns True if the label L is touched or impacted. This method is called by <TFunction_FunctionDriver::MustExecute>. If <WithChildren> is set to true, the method checks all the sublabels of <L> too.", py::arg("L"), py::arg("WithChildren"));
cls_TFunction_Logbook.def("GetTouched", (const TDF_LabelMap & (TFunction_Logbook::*)() const) &TFunction_Logbook::GetTouched, "Returns the map of touched labels in this logbook. A touched label is the one modified by the end user.");
cls_TFunction_Logbook.def("GetImpacted", (const TDF_LabelMap & (TFunction_Logbook::*)() const) &TFunction_Logbook::GetImpacted, "Returns the map of impacted labels contained in this logbook.");
cls_TFunction_Logbook.def("GetValid", (const TDF_LabelMap & (TFunction_Logbook::*)() const) &TFunction_Logbook::GetValid, "Returns the map of valid labels in this logbook.");
cls_TFunction_Logbook.def("GetValid", (void (TFunction_Logbook::*)(TDF_LabelMap &) const) &TFunction_Logbook::GetValid, "None", py::arg("Ls"));
cls_TFunction_Logbook.def("Done", (void (TFunction_Logbook::*)(const Standard_Boolean)) &TFunction_Logbook::Done, "Sets status of execution.", py::arg("status"));
cls_TFunction_Logbook.def("IsDone", (Standard_Boolean (TFunction_Logbook::*)() const) &TFunction_Logbook::IsDone, "Returns status of execution.");
cls_TFunction_Logbook.def("ID", (const Standard_GUID & (TFunction_Logbook::*)() const) &TFunction_Logbook::ID, "Returns the ID of the attribute.");
cls_TFunction_Logbook.def("Restore", (void (TFunction_Logbook::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Logbook::Restore, "Undos (and redos) the attribute.", py::arg("with"));
cls_TFunction_Logbook.def("Paste", (void (TFunction_Logbook::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TFunction_Logbook::Paste, "Pastes the attribute to another label.", py::arg("into"), py::arg("RT"));
cls_TFunction_Logbook.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Logbook::*)() const) &TFunction_Logbook::NewEmpty, "Returns a new empty instance of the attribute.");
cls_TFunction_Logbook.def("Dump", (Standard_OStream & (TFunction_Logbook::*)(Standard_OStream &) const) &TFunction_Logbook::Dump, "Prints th data of the attributes (touched, impacted and valid labels).", py::arg("anOS"));

// Enums

}