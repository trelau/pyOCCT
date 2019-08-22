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
#include <math_Function.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <FairCurve_BattenLaw.hxx>

void bind_FairCurve_BattenLaw(py::module &mod){

py::class_<FairCurve_BattenLaw, math_Function> cls_FairCurve_BattenLaw(mod, "FairCurve_BattenLaw", "This class compute the Heigth of an batten");

// Constructors
cls_FairCurve_BattenLaw.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Heigth"), py::arg("Slope"), py::arg("Sliding"));

// Fields

// Methods
// cls_FairCurve_BattenLaw.def_static("operator new_", (void * (*)(size_t)) &FairCurve_BattenLaw::operator new, "None", py::arg("theSize"));
// cls_FairCurve_BattenLaw.def_static("operator delete_", (void (*)(void *)) &FairCurve_BattenLaw::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_BattenLaw.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_BattenLaw::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_BattenLaw.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_BattenLaw::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_BattenLaw.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_BattenLaw::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_BattenLaw.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_BattenLaw::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_BattenLaw.def("SetSliding", (void (FairCurve_BattenLaw::*)(const Standard_Real)) &FairCurve_BattenLaw::SetSliding, "Change the value of sliding", py::arg("Sliding"));
cls_FairCurve_BattenLaw.def("SetHeigth", (void (FairCurve_BattenLaw::*)(const Standard_Real)) &FairCurve_BattenLaw::SetHeigth, "Change the value of Heigth at the middle point.", py::arg("Heigth"));
cls_FairCurve_BattenLaw.def("SetSlope", (void (FairCurve_BattenLaw::*)(const Standard_Real)) &FairCurve_BattenLaw::SetSlope, "Change the value of the geometric slope.", py::arg("Slope"));
cls_FairCurve_BattenLaw.def("Value", [](FairCurve_BattenLaw &self, const Standard_Real T, Standard_Real & THeigth){ Standard_Boolean rv = self.Value(T, THeigth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, THeigth); }, "computes the value of the heigth for the parameter T on the neutral fibber", py::arg("T"), py::arg("THeigth"));

// Enums

}