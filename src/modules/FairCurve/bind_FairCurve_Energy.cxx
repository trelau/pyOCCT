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
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfXY.hxx>
#include <FairCurve_Energy.hxx>

void bind_FairCurve_Energy(py::module &mod){

py::class_<FairCurve_Energy, std::unique_ptr<FairCurve_Energy, Deleter<FairCurve_Energy>>, math_MultipleVarFunctionWithHessian> cls_FairCurve_Energy(mod, "FairCurve_Energy", "necessary methodes to compute the energy of an FairCurve.");

// Fields

// Methods
// cls_FairCurve_Energy.def_static("operator new_", (void * (*)(size_t)) &FairCurve_Energy::operator new, "None", py::arg("theSize"));
// cls_FairCurve_Energy.def_static("operator delete_", (void (*)(void *)) &FairCurve_Energy::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_Energy.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_Energy::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_Energy.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_Energy::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_Energy.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_Energy::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_Energy.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_Energy::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_Energy.def("NbVariables", (Standard_Integer (FairCurve_Energy::*)() const) &FairCurve_Energy::NbVariables, "returns the number of variables of the energy.");
cls_FairCurve_Energy.def("Value", [](FairCurve_Energy &self, const math_Vector & X, Standard_Real & E){ Standard_Boolean rv = self.Value(X, E); return std::tuple<Standard_Boolean, Standard_Real &>(rv, E); }, "computes the values of the Energys E for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("E"));
cls_FairCurve_Energy.def("Gradient", (Standard_Boolean (FairCurve_Energy::*)(const math_Vector &, math_Vector &)) &FairCurve_Energy::Gradient, "computes the gradient <G> of the energys for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("G"));
cls_FairCurve_Energy.def("Values", [](FairCurve_Energy &self, const math_Vector & X, Standard_Real & E, math_Vector & G){ Standard_Boolean rv = self.Values(X, E, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, E); }, "computes the Energy <E> and the gradient <G> of the energy for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("E"), py::arg("G"));
cls_FairCurve_Energy.def("Values", [](FairCurve_Energy &self, const math_Vector & X, Standard_Real & E, math_Vector & G, math_Matrix & H){ Standard_Boolean rv = self.Values(X, E, G, H); return std::tuple<Standard_Boolean, Standard_Real &>(rv, E); }, "computes the Energy <E>, the gradient <G> and the Hessian <H> of the energy for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("E"), py::arg("G"), py::arg("H"));
cls_FairCurve_Energy.def("Variable", (Standard_Boolean (FairCurve_Energy::*)(math_Vector &) const) &FairCurve_Energy::Variable, "compute the variables <X> wich correspond with the field <MyPoles>", py::arg("X"));
cls_FairCurve_Energy.def("Poles", (const opencascade::handle<TColgp_HArray1OfPnt2d> & (FairCurve_Energy::*)() const) &FairCurve_Energy::Poles, "return the poles");

// Enums

}