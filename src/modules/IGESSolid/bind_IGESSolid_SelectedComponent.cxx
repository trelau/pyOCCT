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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESSolid_BooleanTree.hxx>
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESSolid_SelectedComponent.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_SelectedComponent(py::module &mod){

py::class_<IGESSolid_SelectedComponent, opencascade::handle<IGESSolid_SelectedComponent>, IGESData_IGESEntity> cls_IGESSolid_SelectedComponent(mod, "IGESSolid_SelectedComponent", "defines SelectedComponent, Type <182> Form Number <0> in package IGESSolid The Selected Component entity provides a means of selecting one component of a disjoint CSG solid");

// Constructors
cls_IGESSolid_SelectedComponent.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_SelectedComponent.def("Init", (void (IGESSolid_SelectedComponent::*)(const opencascade::handle<IGESSolid_BooleanTree> &, const gp_XYZ &)) &IGESSolid_SelectedComponent::Init, "This method is used to set the fields of the class SelectedComponent - anEntity : the Boolean tree entity - selectPnt : Point in or on the desired component", py::arg("anEntity"), py::arg("selectPnt"));
cls_IGESSolid_SelectedComponent.def("Component", (opencascade::handle<IGESSolid_BooleanTree> (IGESSolid_SelectedComponent::*)() const) &IGESSolid_SelectedComponent::Component, "returns the Boolean tree entity");
cls_IGESSolid_SelectedComponent.def("SelectPoint", (gp_Pnt (IGESSolid_SelectedComponent::*)() const) &IGESSolid_SelectedComponent::SelectPoint, "returns the point on/in the selected component");
cls_IGESSolid_SelectedComponent.def("TransformedSelectPoint", (gp_Pnt (IGESSolid_SelectedComponent::*)() const) &IGESSolid_SelectedComponent::TransformedSelectPoint, "returns the point on/in the selected component after applying TransformationMatrix");
cls_IGESSolid_SelectedComponent.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SelectedComponent::get_type_name, "None");
cls_IGESSolid_SelectedComponent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SelectedComponent::get_type_descriptor, "None");
cls_IGESSolid_SelectedComponent.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SelectedComponent::*)() const) &IGESSolid_SelectedComponent::DynamicType, "None");

// Enums

}