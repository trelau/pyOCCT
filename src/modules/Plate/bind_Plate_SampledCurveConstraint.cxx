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
#include <Standard.hxx>
#include <Plate_SequenceOfPinpointConstraint.hxx>
#include <Standard_TypeDef.hxx>
#include <Plate_LinearXYZConstraint.hxx>
#include <Plate_SampledCurveConstraint.hxx>

void bind_Plate_SampledCurveConstraint(py::module &mod){

py::class_<Plate_SampledCurveConstraint, std::unique_ptr<Plate_SampledCurveConstraint, Deleter<Plate_SampledCurveConstraint>>> cls_Plate_SampledCurveConstraint(mod, "Plate_SampledCurveConstraint", "define m PinPointConstraint driven by m unknown");

// Constructors
cls_Plate_SampledCurveConstraint.def(py::init<const Plate_SequenceOfPinpointConstraint &, const Standard_Integer>(), py::arg("SOPPC"), py::arg("n"));

// Fields

// Methods
// cls_Plate_SampledCurveConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_SampledCurveConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_SampledCurveConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_SampledCurveConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_SampledCurveConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_SampledCurveConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_SampledCurveConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_SampledCurveConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_SampledCurveConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_SampledCurveConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_SampledCurveConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_SampledCurveConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_SampledCurveConstraint.def("LXYZC", (const Plate_LinearXYZConstraint & (Plate_SampledCurveConstraint::*)() const) &Plate_SampledCurveConstraint::LXYZC, "None");

// Enums

}