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
#include <Interface_InterfaceModel.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <IGESData_GlobalSection.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_IGESModel(py::module &mod){

py::class_<IGESData_IGESModel, opencascade::handle<IGESData_IGESModel>, Interface_InterfaceModel> cls_IGESData_IGESModel(mod, "IGESData_IGESModel", "Defines the file header and entities for IGES files. These headers and entities result from a complete data translation using the IGES data exchange processor. Each entity is contained in a single model only and has a unique identifier. You can access this identifier using the method Number. Gives an access to the general data in the Start and the Global sections of an IGES file. The IGES file includes the following sections: -Start, -Global, -Directory Entry, -Parameter Data, -Terminate");

// Constructors
cls_IGESData_IGESModel.def(py::init<>());

// Fields

// Methods
cls_IGESData_IGESModel.def("ClearHeader", (void (IGESData_IGESModel::*)()) &IGESData_IGESModel::ClearHeader, "Erases all data specific to IGES file Header (Start + Global)");
cls_IGESData_IGESModel.def("DumpHeader", [](IGESData_IGESModel &self, const opencascade::handle<Message_Messenger> & a0) -> void { return self.DumpHeader(a0); });
cls_IGESData_IGESModel.def("DumpHeader", (void (IGESData_IGESModel::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESData_IGESModel::DumpHeader, "Prints the IGES file header (Start and Global Sections) to the log file. The integer parameter is intended to be used as a level indicator but is not used at present.", py::arg("S"), py::arg("level"));
cls_IGESData_IGESModel.def("StartSection", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESData_IGESModel::*)() const) &IGESData_IGESModel::StartSection, "Returns Model's Start Section (list of comment lines)");
cls_IGESData_IGESModel.def("NbStartLines", (Standard_Integer (IGESData_IGESModel::*)() const) &IGESData_IGESModel::NbStartLines, "Returns the count of recorded Start Lines");
cls_IGESData_IGESModel.def("StartLine", (Standard_CString (IGESData_IGESModel::*)(const Standard_Integer) const) &IGESData_IGESModel::StartLine, "Returns a line from the IGES file Start section by specifying its number. An empty string is returned if the number given is out of range, the range being from 1 to NbStartLines.", py::arg("num"));
cls_IGESData_IGESModel.def("ClearStartSection", (void (IGESData_IGESModel::*)()) &IGESData_IGESModel::ClearStartSection, "Clears the IGES file Start Section");
cls_IGESData_IGESModel.def("SetStartSection", [](IGESData_IGESModel &self, const opencascade::handle<TColStd_HSequenceOfHAsciiString> & a0) -> void { return self.SetStartSection(a0); });
cls_IGESData_IGESModel.def("SetStartSection", (void (IGESData_IGESModel::*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &, const Standard_Boolean)) &IGESData_IGESModel::SetStartSection, "Sets a new Start section from a list of strings. If copy is false, the Start section will be shared. Any modifications made to the strings later on, will have an effect on the Start section. If copy is true (default value), an independent copy of the strings is created and used as the Start section. Any modifications made to the strings later on, will have no effect on the Start section.", py::arg("list"), py::arg("copy"));
cls_IGESData_IGESModel.def("AddStartLine", [](IGESData_IGESModel &self, const Standard_CString a0) -> void { return self.AddStartLine(a0); });
cls_IGESData_IGESModel.def("AddStartLine", (void (IGESData_IGESModel::*)(const Standard_CString, const Standard_Integer)) &IGESData_IGESModel::AddStartLine, "Adds a new string to the existing Start section at the end if atnum is 0 or not given, or before atnumth line.", py::arg("line"), py::arg("atnum"));
cls_IGESData_IGESModel.def("GlobalSection", (const IGESData_GlobalSection & (IGESData_IGESModel::*)() const) &IGESData_IGESModel::GlobalSection, "Returns the Global section of the IGES file.");
cls_IGESData_IGESModel.def("SetGlobalSection", (void (IGESData_IGESModel::*)(const IGESData_GlobalSection &)) &IGESData_IGESModel::SetGlobalSection, "Sets the Global section of the IGES file.", py::arg("header"));
cls_IGESData_IGESModel.def("ApplyStatic", [](IGESData_IGESModel &self) -> Standard_Boolean { return self.ApplyStatic(); });
cls_IGESData_IGESModel.def("ApplyStatic", (Standard_Boolean (IGESData_IGESModel::*)(const Standard_CString)) &IGESData_IGESModel::ApplyStatic, "Sets some of the Global section parameters with the values defined by the translation parameters. param may be: - receiver (value read in XSTEP.iges.header.receiver), - author (value read in XSTEP.iges.header.author), - company (value read in XSTEP.iges.header.company). The default value for param is an empty string. Returns True when done and if param is given, False if param is unknown or empty. Note: Set the unit in the IGES file Global section via IGESData_BasicEditor class.", py::arg("param"));
cls_IGESData_IGESModel.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESData_IGESModel::*)(const Standard_Integer) const) &IGESData_IGESModel::Entity, "Returns an IGES entity given by its rank number.", py::arg("num"));
cls_IGESData_IGESModel.def("DNum", (Standard_Integer (IGESData_IGESModel::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_IGESModel::DNum, "Returns the equivalent DE Number for an Entity, i.e. 2*Number(ent)-1 , or 0 if <ent> is unknown from <me> This DE Number is used for File Writing for instance", py::arg("ent"));
cls_IGESData_IGESModel.def("GetFromAnother", (void (IGESData_IGESModel::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESData_IGESModel::GetFromAnother, "gets Header (GlobalSection) from another Model", py::arg("other"));
cls_IGESData_IGESModel.def("NewEmptyModel", (opencascade::handle<Interface_InterfaceModel> (IGESData_IGESModel::*)() const) &IGESData_IGESModel::NewEmptyModel, "Returns a New Empty Model, same type as <me> i.e. IGESModel");
cls_IGESData_IGESModel.def("VerifyCheck", (void (IGESData_IGESModel::*)(opencascade::handle<Interface_Check> &) const) &IGESData_IGESModel::VerifyCheck, "Checks that the IGES file Global section contains valid data that conforms to the IGES specifications.", py::arg("ach"));
cls_IGESData_IGESModel.def("SetLineWeights", (void (IGESData_IGESModel::*)(const Standard_Real)) &IGESData_IGESModel::SetLineWeights, "Sets LineWeights of contained Entities according header data (MaxLineWeight and LineWeightGrad) or to a default value for undefined weights", py::arg("defw"));
cls_IGESData_IGESModel.def("ClearLabels", (void (IGESData_IGESModel::*)()) &IGESData_IGESModel::ClearLabels, "erases specific labels, i.e. does nothing");
cls_IGESData_IGESModel.def("PrintLabel", (void (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESModel::PrintLabel, "Prints label specific to IGES norm for a given entity, i.e. its directory entry number (2*Number-1)", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESModel.def("PrintToLog", (void (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESModel::PrintToLog, "Prints label specific to IGES norm for a given -- -- entity, i.e. its directory entry number (2*Number-1) in the log file format.", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESModel.def("PrintInfo", (void (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESModel::PrintInfo, "Prints label specific to IGES norm for a given entity, i.e. its directory entry number (2*Number-1)", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESModel.def("StringLabel", (opencascade::handle<TCollection_HAsciiString> (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &) const) &IGESData_IGESModel::StringLabel, "Returns a string with the label attached to a given entity, i.e. a string 'Dnn' with nn = directory entry number (2*N-1)", py::arg("ent"));
cls_IGESData_IGESModel.def_static("get_type_name_", (const char * (*)()) &IGESData_IGESModel::get_type_name, "None");
cls_IGESData_IGESModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_IGESModel::get_type_descriptor, "None");
cls_IGESData_IGESModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_IGESModel::*)() const) &IGESData_IGESModel::DynamicType, "None");

// Enums

}