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
#include <StepElement_ElementDescriptor.hxx>
#include <StepElement_ElementOrder.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.hxx>
#include <StepElement_Element2dShape.hxx>
#include <StepElement_Surface3dElementDescriptor.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_Surface3dElementDescriptor(py::module &mod){

py::class_<StepElement_Surface3dElementDescriptor, opencascade::handle<StepElement_Surface3dElementDescriptor>, StepElement_ElementDescriptor> cls_StepElement_Surface3dElementDescriptor(mod, "StepElement_Surface3dElementDescriptor", "Representation of STEP entity Surface3dElementDescriptor");

// Constructors
cls_StepElement_Surface3dElementDescriptor.def(py::init<>());

// Fields

// Methods
cls_StepElement_Surface3dElementDescriptor.def("Init", (void (StepElement_Surface3dElementDescriptor::*)(const StepElement_ElementOrder, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember> &, const StepElement_Element2dShape)) &StepElement_Surface3dElementDescriptor::Init, "Initialize all fields (own and inherited)", py::arg("aElementDescriptor_TopologyOrder"), py::arg("aElementDescriptor_Description"), py::arg("aPurpose"), py::arg("aShape"));
cls_StepElement_Surface3dElementDescriptor.def("Purpose", (opencascade::handle<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember> (StepElement_Surface3dElementDescriptor::*)() const) &StepElement_Surface3dElementDescriptor::Purpose, "Returns field Purpose");
cls_StepElement_Surface3dElementDescriptor.def("SetPurpose", (void (StepElement_Surface3dElementDescriptor::*)(const opencascade::handle<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember> &)) &StepElement_Surface3dElementDescriptor::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepElement_Surface3dElementDescriptor.def("Shape", (StepElement_Element2dShape (StepElement_Surface3dElementDescriptor::*)() const) &StepElement_Surface3dElementDescriptor::Shape, "Returns field Shape");
cls_StepElement_Surface3dElementDescriptor.def("SetShape", (void (StepElement_Surface3dElementDescriptor::*)(const StepElement_Element2dShape)) &StepElement_Surface3dElementDescriptor::SetShape, "Set field Shape", py::arg("Shape"));
cls_StepElement_Surface3dElementDescriptor.def_static("get_type_name_", (const char * (*)()) &StepElement_Surface3dElementDescriptor::get_type_name, "None");
cls_StepElement_Surface3dElementDescriptor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_Surface3dElementDescriptor::get_type_descriptor, "None");
cls_StepElement_Surface3dElementDescriptor.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_Surface3dElementDescriptor::*)() const) &StepElement_Surface3dElementDescriptor::DynamicType, "None");

// Enums

}