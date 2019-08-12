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
#include <IGESToBRep_ToolContainer.hxx>
#include <Standard_Handle.hxx>
#include <IGESToBRep_IGESBoundary.hxx>
#include <IGESControl_ToolContainer.hxx>
#include <Standard_Type.hxx>

void bind_IGESControl_ToolContainer(py::module &mod){

py::class_<IGESControl_ToolContainer, opencascade::handle<IGESControl_ToolContainer>, IGESToBRep_ToolContainer> cls_IGESControl_ToolContainer(mod, "IGESControl_ToolContainer", "None");

// Constructors
cls_IGESControl_ToolContainer.def(py::init<>());

// Fields

// Methods
cls_IGESControl_ToolContainer.def("IGESBoundary", (opencascade::handle<IGESToBRep_IGESBoundary> (IGESControl_ToolContainer::*)() const) &IGESControl_ToolContainer::IGESBoundary, "Returns IGESControl_IGESBoundary");
cls_IGESControl_ToolContainer.def_static("get_type_name_", (const char * (*)()) &IGESControl_ToolContainer::get_type_name, "None");
cls_IGESControl_ToolContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_ToolContainer::get_type_descriptor, "None");
cls_IGESControl_ToolContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_ToolContainer::*)() const) &IGESControl_ToolContainer::DynamicType, "None");

// Enums

}