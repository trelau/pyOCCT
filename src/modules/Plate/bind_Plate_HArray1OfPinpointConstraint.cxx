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
#include <Plate_Array1OfPinpointConstraint.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Plate_HArray1OfPinpointConstraint.hxx>
#include <Standard_Type.hxx>

void bind_Plate_HArray1OfPinpointConstraint(py::module &mod){

py::class_<Plate_HArray1OfPinpointConstraint, opencascade::handle<Plate_HArray1OfPinpointConstraint>, Standard_Transient> cls_Plate_HArray1OfPinpointConstraint(mod, "Plate_HArray1OfPinpointConstraint", "None", py::multiple_inheritance());

// Constructors
cls_Plate_HArray1OfPinpointConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Plate_HArray1OfPinpointConstraint.def(py::init<const Standard_Integer, const Standard_Integer, const Plate_Array1OfPinpointConstraint::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Plate_HArray1OfPinpointConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_HArray1OfPinpointConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_HArray1OfPinpointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_HArray1OfPinpointConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_HArray1OfPinpointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_HArray1OfPinpointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_HArray1OfPinpointConstraint::operator delete, "None", py::arg(""), py::arg(""));
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Plate_HArray1OfPinpointConstraint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Plate_HArray1OfPinpointConstraint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Plate_HArray1OfPinpointConstraint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Plate_HArray1OfPinpointConstraint.def("Array1", (const Plate_Array1OfPinpointConstraint & (Plate_HArray1OfPinpointConstraint::*)() const) &Plate_HArray1OfPinpointConstraint::Array1, "None");
cls_Plate_HArray1OfPinpointConstraint.def("ChangeArray1", (Plate_Array1OfPinpointConstraint & (Plate_HArray1OfPinpointConstraint::*)()) &Plate_HArray1OfPinpointConstraint::ChangeArray1, "None");
cls_Plate_HArray1OfPinpointConstraint.def_static("get_type_name_", (const char * (*)()) &Plate_HArray1OfPinpointConstraint::get_type_name, "None");
cls_Plate_HArray1OfPinpointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Plate_HArray1OfPinpointConstraint::get_type_descriptor, "None");
cls_Plate_HArray1OfPinpointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (Plate_HArray1OfPinpointConstraint::*)() const) &Plate_HArray1OfPinpointConstraint::DynamicType, "None");

// Enums

}