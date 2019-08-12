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
#include <StepShape_DimensionalCharacteristic.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_ShapeDimensionRepresentation.hxx>
#include <StepShape_DimensionalCharacteristicRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_DimensionalCharacteristicRepresentation(py::module &mod){

py::class_<StepShape_DimensionalCharacteristicRepresentation, opencascade::handle<StepShape_DimensionalCharacteristicRepresentation>, Standard_Transient> cls_StepShape_DimensionalCharacteristicRepresentation(mod, "StepShape_DimensionalCharacteristicRepresentation", "Representation of STEP entity DimensionalCharacteristicRepresentation");

// Constructors
cls_StepShape_DimensionalCharacteristicRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepShape_DimensionalCharacteristicRepresentation.def("Init", (void (StepShape_DimensionalCharacteristicRepresentation::*)(const StepShape_DimensionalCharacteristic &, const opencascade::handle<StepShape_ShapeDimensionRepresentation> &)) &StepShape_DimensionalCharacteristicRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aDimension"), py::arg("aRepresentation"));
cls_StepShape_DimensionalCharacteristicRepresentation.def("Dimension", (StepShape_DimensionalCharacteristic (StepShape_DimensionalCharacteristicRepresentation::*)() const) &StepShape_DimensionalCharacteristicRepresentation::Dimension, "Returns field Dimension");
cls_StepShape_DimensionalCharacteristicRepresentation.def("SetDimension", (void (StepShape_DimensionalCharacteristicRepresentation::*)(const StepShape_DimensionalCharacteristic &)) &StepShape_DimensionalCharacteristicRepresentation::SetDimension, "Set field Dimension", py::arg("Dimension"));
cls_StepShape_DimensionalCharacteristicRepresentation.def("Representation", (opencascade::handle<StepShape_ShapeDimensionRepresentation> (StepShape_DimensionalCharacteristicRepresentation::*)() const) &StepShape_DimensionalCharacteristicRepresentation::Representation, "Returns field Representation");
cls_StepShape_DimensionalCharacteristicRepresentation.def("SetRepresentation", (void (StepShape_DimensionalCharacteristicRepresentation::*)(const opencascade::handle<StepShape_ShapeDimensionRepresentation> &)) &StepShape_DimensionalCharacteristicRepresentation::SetRepresentation, "Set field Representation", py::arg("Representation"));
cls_StepShape_DimensionalCharacteristicRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalCharacteristicRepresentation::get_type_name, "None");
cls_StepShape_DimensionalCharacteristicRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalCharacteristicRepresentation::get_type_descriptor, "None");
cls_StepShape_DimensionalCharacteristicRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalCharacteristicRepresentation::*)() const) &StepShape_DimensionalCharacteristicRepresentation::DynamicType, "None");

// Enums

}