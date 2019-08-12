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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_Graph.hxx>
#include <Interface_HGraph.hxx>
#include <Standard_Transient.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Message_Messenger.hxx>
#include <Interface_CheckIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_GTool.hxx>
#include <Interface_CheckTool.hxx>

void bind_Interface_CheckTool(py::module &mod){

py::class_<Interface_CheckTool, std::unique_ptr<Interface_CheckTool, Deleter<Interface_CheckTool>>> cls_Interface_CheckTool(mod, "Interface_CheckTool", "Performs Checks on Entities, using General Service Library and Modules to work. Works on one Entity or on a complete Model");

// Constructors
cls_Interface_CheckTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("model"), py::arg("protocol"));
cls_Interface_CheckTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("model"));
cls_Interface_CheckTool.def(py::init<const Interface_Graph &>(), py::arg("graph"));
cls_Interface_CheckTool.def(py::init<const opencascade::handle<Interface_HGraph> &>(), py::arg("hgraph"));

// Fields

// Methods
// cls_Interface_CheckTool.def_static("operator new_", (void * (*)(size_t)) &Interface_CheckTool::operator new, "None", py::arg("theSize"));
// cls_Interface_CheckTool.def_static("operator delete_", (void (*)(void *)) &Interface_CheckTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_CheckTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_CheckTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_CheckTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_CheckTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_CheckTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_CheckTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_CheckTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_CheckTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_CheckTool.def("FillCheck", (void (Interface_CheckTool::*)(const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &)) &Interface_CheckTool::FillCheck, "Fills as required a Check with the Error and Warning messages produced by Checking a given Entity. For an Erroneous or Corrected Entity : Check build at Analyse time; else, Check computed for Entity (Verify integrity), can use a Graph as required to control context", py::arg("ent"), py::arg("sh"), py::arg("ach"));
cls_Interface_CheckTool.def("Print", (void (Interface_CheckTool::*)(const opencascade::handle<Interface_Check> &, const opencascade::handle<Message_Messenger> &) const) &Interface_CheckTool::Print, "Utility method which Prints the content of a Check", py::arg("ach"), py::arg("S"));
cls_Interface_CheckTool.def("Print", (void (Interface_CheckTool::*)(const Interface_CheckIterator &, const opencascade::handle<Message_Messenger> &) const) &Interface_CheckTool::Print, "Simply Lists all the Checks and the Content (messages) and the Entity, if there is, of each Check (if all Checks are OK, nothing is Printed)", py::arg("list"), py::arg("S"));
cls_Interface_CheckTool.def("Check", (opencascade::handle<Interface_Check> (Interface_CheckTool::*)(const Standard_Integer)) &Interface_CheckTool::Check, "Returns the Check associated to an Entity identified by its Number in a Model.", py::arg("num"));
cls_Interface_CheckTool.def("CheckSuccess", [](Interface_CheckTool &self) -> void { return self.CheckSuccess(); });
cls_Interface_CheckTool.def("CheckSuccess", (void (Interface_CheckTool::*)(const Standard_Boolean)) &Interface_CheckTool::CheckSuccess, "Checks if any Error has been detected (CheckList not empty) Returns normally if none, raises exception if some exists. It reuses the last computations from other checking methods, unless the argument <resest> is given True", py::arg("reset"));
cls_Interface_CheckTool.def("CompleteCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::CompleteCheckList, "Returns list of all 'remarkable' informations, which include : - GlobalCheck, if not empty - Error Checks, for all Errors (Verify + Analyse) - also Corrected Entities - and Unknown Entities : for those, each Unknown Entity is associated to an empty Check (it is neither an Error nor a Correction, but a remarkable information)");
cls_Interface_CheckTool.def("CheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::CheckList, "Returns list of all Errors detected Note that presence of Unknown Entities is not an error Cumulates : GlobalCheck if error + AnalyseCheckList + VerifyCheckList");
cls_Interface_CheckTool.def("AnalyseCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::AnalyseCheckList, "Returns list of errors dectected at Analyse time (syntactic) (note that GlobalCheck is not in this list)");
cls_Interface_CheckTool.def("VerifyCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::VerifyCheckList, "Returns list of integrity constraints errors (semantic) (note that GlobalCheck is not in this list)");
cls_Interface_CheckTool.def("WarningCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::WarningCheckList, "Returns list of Corrections (includes GlobalCheck if corrected)");
cls_Interface_CheckTool.def("UnknownEntities", (Interface_EntityIterator (Interface_CheckTool::*)()) &Interface_CheckTool::UnknownEntities, "Returns list of Unknown Entities Note that Error and Erroneous Entities are not considered as Unknown");

// Enums

}