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
#include <math_FunctionWithDerivative.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <GeomFill_PlanFunc.hxx>

void bind_GeomFill_PlanFunc(py::module &mod){

py::class_<GeomFill_PlanFunc, std::unique_ptr<GeomFill_PlanFunc>, math_FunctionWithDerivative> cls_GeomFill_PlanFunc(mod, "GeomFill_PlanFunc", "None");

// Constructors
cls_GeomFill_PlanFunc.def(py::init<const gp_Pnt &, const gp_Vec &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("P"), py::arg("V"), py::arg("C"));

// Fields

// Methods
// cls_GeomFill_PlanFunc.def_static("operator new_", (void * (*)(size_t)) &GeomFill_PlanFunc::operator new, "None", py::arg("theSize"));
// cls_GeomFill_PlanFunc.def_static("operator delete_", (void (*)(void *)) &GeomFill_PlanFunc::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_PlanFunc.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_PlanFunc::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_PlanFunc.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_PlanFunc::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_PlanFunc.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_PlanFunc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_PlanFunc.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_PlanFunc::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_PlanFunc.def("Value", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_GeomFill_PlanFunc.def("Derivative", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
cls_GeomFill_PlanFunc.def("Values", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomFill_PlanFunc.def("D2", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D1, Standard_Real & D2){ self.D2(X, F, D1, D2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, D1, D2); }, "None", py::arg("X"), py::arg("F"), py::arg("D1"), py::arg("D2"));
cls_GeomFill_PlanFunc.def("DEDT", [](GeomFill_PlanFunc &self, const Standard_Real X, const gp_Vec & DP, const gp_Vec & DV, Standard_Real & DF){ self.DEDT(X, DP, DV, DF); return DF; }, "None", py::arg("X"), py::arg("DP"), py::arg("DV"), py::arg("DF"));
cls_GeomFill_PlanFunc.def("D2E", [](GeomFill_PlanFunc &self, const Standard_Real X, const gp_Vec & DP, const gp_Vec & D2P, const gp_Vec & DV, const gp_Vec & D2V, Standard_Real & DFDT, Standard_Real & D2FDT2, Standard_Real & D2FDTDX){ self.D2E(X, DP, D2P, DV, D2V, DFDT, D2FDT2, D2FDTDX); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(DFDT, D2FDT2, D2FDTDX); }, "None", py::arg("X"), py::arg("DP"), py::arg("D2P"), py::arg("DV"), py::arg("D2V"), py::arg("DFDT"), py::arg("D2FDT2"), py::arg("D2FDTDX"));

// Enums

}