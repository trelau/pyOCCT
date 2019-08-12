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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ShapeAspect(py::module &mod){

py::class_<StepRepr_ShapeAspect, opencascade::handle<StepRepr_ShapeAspect>, Standard_Transient> cls_StepRepr_ShapeAspect(mod, "StepRepr_ShapeAspect", "None");

// Constructors
cls_StepRepr_ShapeAspect.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ShapeAspect.def("Init", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical)) &StepRepr_ShapeAspect::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aOfShape"), py::arg("aProductDefinitional"));
cls_StepRepr_ShapeAspect.def("SetName", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspect::SetName, "None", py::arg("aName"));
cls_StepRepr_ShapeAspect.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::Name, "None");
cls_StepRepr_ShapeAspect.def("SetDescription", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspect::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_ShapeAspect.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::Description, "None");
cls_StepRepr_ShapeAspect.def("SetOfShape", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &StepRepr_ShapeAspect::SetOfShape, "None", py::arg("aOfShape"));
cls_StepRepr_ShapeAspect.def("OfShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::OfShape, "None");
cls_StepRepr_ShapeAspect.def("SetProductDefinitional", (void (StepRepr_ShapeAspect::*)(const StepData_Logical)) &StepRepr_ShapeAspect::SetProductDefinitional, "None", py::arg("aProductDefinitional"));
cls_StepRepr_ShapeAspect.def("ProductDefinitional", (StepData_Logical (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::ProductDefinitional, "None");
cls_StepRepr_ShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeAspect::get_type_name, "None");
cls_StepRepr_ShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeAspect::get_type_descriptor, "None");
cls_StepRepr_ShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::DynamicType, "None");

// Enums

}