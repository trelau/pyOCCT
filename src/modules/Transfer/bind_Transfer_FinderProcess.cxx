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
#include <Transfer_ProcessForFinder.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Transfer_TransientMapper.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_Finder.hxx>
#include <Message_Messenger.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_FinderProcess(py::module &mod){

py::class_<Transfer_FinderProcess, opencascade::handle<Transfer_FinderProcess>, Transfer_ProcessForFinder> cls_Transfer_FinderProcess(mod, "Transfer_FinderProcess", "Adds specific features to the generic definition : PrintTrace is adapted");

// Constructors
cls_Transfer_FinderProcess.def(py::init<>());
cls_Transfer_FinderProcess.def(py::init<const Standard_Integer>(), py::arg("nb"));

// Fields

// Methods
cls_Transfer_FinderProcess.def("SetModel", (void (Transfer_FinderProcess::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Transfer_FinderProcess::SetModel, "Sets an InterfaceModel, which can be used during transfer for instance if a context must be managed, it is in the Model", py::arg("model"));
cls_Transfer_FinderProcess.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_FinderProcess::*)() const) &Transfer_FinderProcess::Model, "Returns the Model which can be used for context");
cls_Transfer_FinderProcess.def("NextMappedWithAttribute", (Standard_Integer (Transfer_FinderProcess::*)(const Standard_CString, const Standard_Integer) const) &Transfer_FinderProcess::NextMappedWithAttribute, "In the list of mapped items (between 1 and NbMapped), searches for the first mapped item which follows <num0> (not included) and which has an attribute named <name> The considered Attributes are those brought by Finders,i.e. by Input data. While NextItemWithAttribute works on Result data (Binders)", py::arg("name"), py::arg("num0"));
cls_Transfer_FinderProcess.def("TransientMapper", (opencascade::handle<Transfer_TransientMapper> (Transfer_FinderProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_FinderProcess::TransientMapper, "Returns a TransientMapper for a given Transient Object Either <obj> is already mapped, then its Mapper is returned Or it is not, then a new one is created then returned, BUT it is not mapped here (use Bind or FindElseBind to do this)", py::arg("obj"));
cls_Transfer_FinderProcess.def("PrintTrace", (void (Transfer_FinderProcess::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Message_Messenger> &) const) &Transfer_FinderProcess::PrintTrace, "Specific printing to trace a Finder (by its method ValueType)", py::arg("start"), py::arg("S"));
cls_Transfer_FinderProcess.def("PrintStats", (void (Transfer_FinderProcess::*)(const Standard_Integer, const opencascade::handle<Message_Messenger> &) const) &Transfer_FinderProcess::PrintStats, "Prints statistics on a given output, according mode", py::arg("mode"), py::arg("S"));
cls_Transfer_FinderProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_FinderProcess::get_type_name, "None");
cls_Transfer_FinderProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_FinderProcess::get_type_descriptor, "None");
cls_Transfer_FinderProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_FinderProcess::*)() const) &Transfer_FinderProcess::DynamicType, "None");

// Enums

}