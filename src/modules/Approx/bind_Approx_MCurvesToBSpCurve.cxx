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
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Approx_MCurvesToBSpCurve.hxx>

void bind_Approx_MCurvesToBSpCurve(py::module &mod){

py::class_<Approx_MCurvesToBSpCurve, std::unique_ptr<Approx_MCurvesToBSpCurve, Deleter<Approx_MCurvesToBSpCurve>>> cls_Approx_MCurvesToBSpCurve(mod, "Approx_MCurvesToBSpCurve", "None");

// Constructors
cls_Approx_MCurvesToBSpCurve.def(py::init<>());

// Fields

// Methods
// cls_Approx_MCurvesToBSpCurve.def_static("operator new_", (void * (*)(size_t)) &Approx_MCurvesToBSpCurve::operator new, "None", py::arg("theSize"));
// cls_Approx_MCurvesToBSpCurve.def_static("operator delete_", (void (*)(void *)) &Approx_MCurvesToBSpCurve::operator delete, "None", py::arg("theAddress"));
// cls_Approx_MCurvesToBSpCurve.def_static("operator new[]_", (void * (*)(size_t)) &Approx_MCurvesToBSpCurve::operator new[], "None", py::arg("theSize"));
// cls_Approx_MCurvesToBSpCurve.def_static("operator delete[]_", (void (*)(void *)) &Approx_MCurvesToBSpCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_MCurvesToBSpCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_MCurvesToBSpCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_MCurvesToBSpCurve.def_static("operator delete_", (void (*)(void *, void *)) &Approx_MCurvesToBSpCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_MCurvesToBSpCurve.def("Reset", (void (Approx_MCurvesToBSpCurve::*)()) &Approx_MCurvesToBSpCurve::Reset, "None");
cls_Approx_MCurvesToBSpCurve.def("Append", (void (Approx_MCurvesToBSpCurve::*)(const AppParCurves_MultiCurve &)) &Approx_MCurvesToBSpCurve::Append, "None", py::arg("MC"));
cls_Approx_MCurvesToBSpCurve.def("Perform", (void (Approx_MCurvesToBSpCurve::*)()) &Approx_MCurvesToBSpCurve::Perform, "None");
cls_Approx_MCurvesToBSpCurve.def("Perform", (void (Approx_MCurvesToBSpCurve::*)(const AppParCurves_SequenceOfMultiCurve &)) &Approx_MCurvesToBSpCurve::Perform, "None", py::arg("TheSeq"));
cls_Approx_MCurvesToBSpCurve.def("Value", (const AppParCurves_MultiBSpCurve & (Approx_MCurvesToBSpCurve::*)() const) &Approx_MCurvesToBSpCurve::Value, "return the composite MultiCurves as a MultiBSpCurve.");
cls_Approx_MCurvesToBSpCurve.def("ChangeValue", (const AppParCurves_MultiBSpCurve & (Approx_MCurvesToBSpCurve::*)()) &Approx_MCurvesToBSpCurve::ChangeValue, "return the composite MultiCurves as a MultiBSpCurve.");

// Enums

}