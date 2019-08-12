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
#include <TColStd_HArray1OfReal.hxx>
#include <StepBasic_EulerAngles.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_EulerAngles(py::module &mod){

py::class_<StepBasic_EulerAngles, opencascade::handle<StepBasic_EulerAngles>, Standard_Transient> cls_StepBasic_EulerAngles(mod, "StepBasic_EulerAngles", "Representation of STEP entity EulerAngles");

// Constructors
cls_StepBasic_EulerAngles.def(py::init<>());

// Fields

// Methods
cls_StepBasic_EulerAngles.def("Init", (void (StepBasic_EulerAngles::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepBasic_EulerAngles::Init, "Initialize all fields (own and inherited)", py::arg("aAngles"));
cls_StepBasic_EulerAngles.def("Angles", (opencascade::handle<TColStd_HArray1OfReal> (StepBasic_EulerAngles::*)() const) &StepBasic_EulerAngles::Angles, "Returns field Angles");
cls_StepBasic_EulerAngles.def("SetAngles", (void (StepBasic_EulerAngles::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepBasic_EulerAngles::SetAngles, "Set field Angles", py::arg("Angles"));
cls_StepBasic_EulerAngles.def_static("get_type_name_", (const char * (*)()) &StepBasic_EulerAngles::get_type_name, "None");
cls_StepBasic_EulerAngles.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_EulerAngles::get_type_descriptor, "None");
cls_StepBasic_EulerAngles.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_EulerAngles::*)() const) &StepBasic_EulerAngles::DynamicType, "None");

// Enums

}