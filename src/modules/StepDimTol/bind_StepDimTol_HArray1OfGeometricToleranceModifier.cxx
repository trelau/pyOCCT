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
#include <StepDimTol_Array1OfGeometricToleranceModifier.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepDimTol_HArray1OfGeometricToleranceModifier.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_HArray1OfGeometricToleranceModifier(py::module &mod){

py::class_<StepDimTol_HArray1OfGeometricToleranceModifier, opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier>, Standard_Transient> cls_StepDimTol_HArray1OfGeometricToleranceModifier(mod, "StepDimTol_HArray1OfGeometricToleranceModifier", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfGeometricToleranceModifier::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const StepDimTol_Array1OfGeometricToleranceModifier &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("Array1", (const StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_HArray1OfGeometricToleranceModifier::*)() const) &StepDimTol_HArray1OfGeometricToleranceModifier::Array1, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("ChangeArray1", (StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_HArray1OfGeometricToleranceModifier::*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::ChangeArray1, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::get_type_name, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfGeometricToleranceModifier::*)() const) &StepDimTol_HArray1OfGeometricToleranceModifier::DynamicType, "None");

// Enums

}