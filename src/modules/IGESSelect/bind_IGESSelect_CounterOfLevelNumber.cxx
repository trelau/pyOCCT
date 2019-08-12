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
#include <IFSelect_SignCounter.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Message_Messenger.hxx>
#include <IGESSelect_CounterOfLevelNumber.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_IGESSelect_CounterOfLevelNumber(py::module &mod){

py::class_<IGESSelect_CounterOfLevelNumber, opencascade::handle<IGESSelect_CounterOfLevelNumber>, IFSelect_SignCounter> cls_IGESSelect_CounterOfLevelNumber(mod, "IGESSelect_CounterOfLevelNumber", "This class gives information about Level Number. It counts entities according level number, considering also the multiple level (see the class LevelList) for which an entity is attached to each of the listed levels.");

// Constructors
cls_IGESSelect_CounterOfLevelNumber.def(py::init<>());
cls_IGESSelect_CounterOfLevelNumber.def(py::init<const Standard_Boolean>(), py::arg("withmap"));
cls_IGESSelect_CounterOfLevelNumber.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("withmap"), py::arg("withlist"));

// Fields

// Methods
cls_IGESSelect_CounterOfLevelNumber.def("Clear", (void (IGESSelect_CounterOfLevelNumber::*)()) &IGESSelect_CounterOfLevelNumber::Clear, "Resets already memorized informations : also numeric data");
cls_IGESSelect_CounterOfLevelNumber.def("AddSign", (void (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IGESSelect_CounterOfLevelNumber::AddSign, "Adds an entity by considering its lrvrl number(s) A level is added both in numeric and alphanumeric form, i.e. LevelList gives 'LEVEL LIST', others (no level or positive level) displays level number on 7 digits (C : %7d) Remark : an entity attached to a Level List is added for ' LEVEL LIST', and for each of its constituant levels", py::arg("ent"), py::arg("model"));
cls_IGESSelect_CounterOfLevelNumber.def("AddLevel", (void (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &IGESSelect_CounterOfLevelNumber::AddLevel, "The internal action to record a new level number, positive, null (no level) or negative (level list)", py::arg("ent"), py::arg("level"));
cls_IGESSelect_CounterOfLevelNumber.def("HighestLevel", (Standard_Integer (IGESSelect_CounterOfLevelNumber::*)() const) &IGESSelect_CounterOfLevelNumber::HighestLevel, "Returns the highest value found for a level number");
cls_IGESSelect_CounterOfLevelNumber.def("NbTimesLevel", (Standard_Integer (IGESSelect_CounterOfLevelNumber::*)(const Standard_Integer) const) &IGESSelect_CounterOfLevelNumber::NbTimesLevel, "Returns the number of times a level is used, 0 if it has not been recorded at all <level> = 0 counts entities attached to no level <level> < 0 counts entities attached to a LevelList", py::arg("level"));
cls_IGESSelect_CounterOfLevelNumber.def("Levels", (opencascade::handle<TColStd_HSequenceOfInteger> (IGESSelect_CounterOfLevelNumber::*)() const) &IGESSelect_CounterOfLevelNumber::Levels, "Returns the ordered list of used positive Level numbers");
cls_IGESSelect_CounterOfLevelNumber.def("Sign", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_CounterOfLevelNumber::Sign, "Determines and returns the value of the signature for an entity as an HAsciiString. Redefined, gives the same result as AddSign, see this method ('LEVEL LIST' or 'nnnnnnn')", py::arg("ent"), py::arg("model"));
cls_IGESSelect_CounterOfLevelNumber.def("PrintCount", (void (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Message_Messenger> &) const) &IGESSelect_CounterOfLevelNumber::PrintCount, "Prints the counts of items (not the list) then the Highest Level Number recorded", py::arg("S"));
cls_IGESSelect_CounterOfLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_CounterOfLevelNumber::get_type_name, "None");
cls_IGESSelect_CounterOfLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_CounterOfLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_CounterOfLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_CounterOfLevelNumber::*)() const) &IGESSelect_CounterOfLevelNumber::DynamicType, "None");

// Enums

}