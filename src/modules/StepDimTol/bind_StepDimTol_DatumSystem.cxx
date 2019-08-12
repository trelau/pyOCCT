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
#include <StepRepr_ShapeAspect.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepDimTol_HArray1OfDatumReferenceCompartment.hxx>
#include <Standard_TypeDef.hxx>
#include <StepDimTol_DatumReferenceCompartment.hxx>
#include <StepDimTol_DatumSystem.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_DatumSystem(py::module &mod){

py::class_<StepDimTol_DatumSystem, opencascade::handle<StepDimTol_DatumSystem>, StepRepr_ShapeAspect> cls_StepDimTol_DatumSystem(mod, "StepDimTol_DatumSystem", "Representation of STEP entity DatumSystem");

// Constructors
cls_StepDimTol_DatumSystem.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_DatumSystem.def("Init", (void (StepDimTol_DatumSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> &)) &StepDimTol_DatumSystem::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theConstituents"));
cls_StepDimTol_DatumSystem.def("Constituents", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> (StepDimTol_DatumSystem::*)()) &StepDimTol_DatumSystem::Constituents, "Returns field Constituents");
cls_StepDimTol_DatumSystem.def("SetConstituents", (void (StepDimTol_DatumSystem::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> &)) &StepDimTol_DatumSystem::SetConstituents, "Set field Constituents", py::arg("theConstituents"));
cls_StepDimTol_DatumSystem.def("NbConstituents", (Standard_Integer (StepDimTol_DatumSystem::*)() const) &StepDimTol_DatumSystem::NbConstituents, "Returns number of Constituents");
cls_StepDimTol_DatumSystem.def("ConstituentsValue", (opencascade::handle<StepDimTol_DatumReferenceCompartment> (StepDimTol_DatumSystem::*)(const Standard_Integer) const) &StepDimTol_DatumSystem::ConstituentsValue, "Returns Constituents with the given number", py::arg("num"));
cls_StepDimTol_DatumSystem.def("ConstituentsValue", (void (StepDimTol_DatumSystem::*)(const Standard_Integer, const opencascade::handle<StepDimTol_DatumReferenceCompartment> &)) &StepDimTol_DatumSystem::ConstituentsValue, "Sets Constituents with given number", py::arg("num"), py::arg("theItem"));
cls_StepDimTol_DatumSystem.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumSystem::get_type_name, "None");
cls_StepDimTol_DatumSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumSystem::get_type_descriptor, "None");
cls_StepDimTol_DatumSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumSystem::*)() const) &StepDimTol_DatumSystem::DynamicType, "None");

// Enums

}