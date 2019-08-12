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
#include <StepElement_ElementOrder.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepElement_ElementDescriptor.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_ElementDescriptor(py::module &mod){

py::class_<StepElement_ElementDescriptor, opencascade::handle<StepElement_ElementDescriptor>, Standard_Transient> cls_StepElement_ElementDescriptor(mod, "StepElement_ElementDescriptor", "Representation of STEP entity ElementDescriptor");

// Constructors
cls_StepElement_ElementDescriptor.def(py::init<>());

// Fields

// Methods
cls_StepElement_ElementDescriptor.def("Init", (void (StepElement_ElementDescriptor::*)(const StepElement_ElementOrder, const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementDescriptor::Init, "Initialize all fields (own and inherited)", py::arg("aTopologyOrder"), py::arg("aDescription"));
cls_StepElement_ElementDescriptor.def("TopologyOrder", (StepElement_ElementOrder (StepElement_ElementDescriptor::*)() const) &StepElement_ElementDescriptor::TopologyOrder, "Returns field TopologyOrder");
cls_StepElement_ElementDescriptor.def("SetTopologyOrder", (void (StepElement_ElementDescriptor::*)(const StepElement_ElementOrder)) &StepElement_ElementDescriptor::SetTopologyOrder, "Set field TopologyOrder", py::arg("TopologyOrder"));
cls_StepElement_ElementDescriptor.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_ElementDescriptor::*)() const) &StepElement_ElementDescriptor::Description, "Returns field Description");
cls_StepElement_ElementDescriptor.def("SetDescription", (void (StepElement_ElementDescriptor::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementDescriptor::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_ElementDescriptor.def_static("get_type_name_", (const char * (*)()) &StepElement_ElementDescriptor::get_type_name, "None");
cls_StepElement_ElementDescriptor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_ElementDescriptor::get_type_descriptor, "None");
cls_StepElement_ElementDescriptor.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_ElementDescriptor::*)() const) &StepElement_ElementDescriptor::DynamicType, "None");

// Enums

}