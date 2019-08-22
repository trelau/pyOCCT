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
#include <XSControl_WorkSession.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Interface_HGraph.hxx>
#include <STEPConstruct_Tool.hxx>

void bind_STEPConstruct_Tool(py::module &mod){

py::class_<STEPConstruct_Tool> cls_STEPConstruct_Tool(mod, "STEPConstruct_Tool", "Provides basic functionalities for tools which are intended for encoding/decoding specific STEP constructs");

// Constructors
cls_STEPConstruct_Tool.def(py::init<>());
cls_STEPConstruct_Tool.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Fields

// Methods
// cls_STEPConstruct_Tool.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Tool::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Tool.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Tool::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Tool.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Tool::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Tool.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Tool.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Tool.def("WS", (const opencascade::handle<XSControl_WorkSession> & (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::WS, "Returns currently loaded WorkSession");
cls_STEPConstruct_Tool.def("Model", (opencascade::handle<Interface_InterfaceModel> (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::Model, "Returns current model (Null if not loaded)");
cls_STEPConstruct_Tool.def("Graph", [](STEPConstruct_Tool &self) -> const Interface_Graph & { return self.Graph(); });
cls_STEPConstruct_Tool.def("Graph", (const Interface_Graph & (STEPConstruct_Tool::*)(const Standard_Boolean) const) &STEPConstruct_Tool::Graph, "Returns current graph (recomputing if necessary)", py::arg("recompute"));
cls_STEPConstruct_Tool.def("TransientProcess", (const opencascade::handle<Transfer_TransientProcess> & (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::TransientProcess, "Returns TransientProcess (reading; Null if not loaded)");
cls_STEPConstruct_Tool.def("FinderProcess", (const opencascade::handle<Transfer_FinderProcess> & (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::FinderProcess, "Returns FinderProcess (writing; Null if not loaded)");

// Enums

}