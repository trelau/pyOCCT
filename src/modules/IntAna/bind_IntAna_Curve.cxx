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
#include <gp_Cylinder.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Cone.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Ax3.hxx>
#include <IntAna_Curve.hxx>

void bind_IntAna_Curve(py::module &mod){

py::class_<IntAna_Curve, std::unique_ptr<IntAna_Curve>> cls_IntAna_Curve(mod, "IntAna_Curve", "Definition of a parametric Curve which is the result of the intersection between two quadrics.");

// Constructors
cls_IntAna_Curve.def(py::init<>());

// Fields

// Methods
// cls_IntAna_Curve.def_static("operator new_", (void * (*)(size_t)) &IntAna_Curve::operator new, "None", py::arg("theSize"));
// cls_IntAna_Curve.def_static("operator delete_", (void (*)(void *)) &IntAna_Curve::operator delete, "None", py::arg("theAddress"));
// cls_IntAna_Curve.def_static("operator new[]_", (void * (*)(size_t)) &IntAna_Curve::operator new[], "None", py::arg("theSize"));
// cls_IntAna_Curve.def_static("operator delete[]_", (void (*)(void *)) &IntAna_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna_Curve.def_static("operator delete_", (void (*)(void *, void *)) &IntAna_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna_Curve.def("SetCylinderQuadValues", (void (IntAna_Curve::*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &IntAna_Curve::SetCylinderQuadValues, "Sets the parameters used to compute Points and Derivative on the curve.", py::arg("Cylinder"), py::arg("Qxx"), py::arg("Qyy"), py::arg("Qzz"), py::arg("Qxy"), py::arg("Qxz"), py::arg("Qyz"), py::arg("Qx"), py::arg("Qy"), py::arg("Qz"), py::arg("Q1"), py::arg("Tol"), py::arg("DomInf"), py::arg("DomSup"), py::arg("TwoZForATheta"), py::arg("ZIsPositive"));
cls_IntAna_Curve.def("SetConeQuadValues", (void (IntAna_Curve::*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &IntAna_Curve::SetConeQuadValues, "Sets the parameters used to compute Points and Derivative on the curve.", py::arg("Cone"), py::arg("Qxx"), py::arg("Qyy"), py::arg("Qzz"), py::arg("Qxy"), py::arg("Qxz"), py::arg("Qyz"), py::arg("Qx"), py::arg("Qy"), py::arg("Qz"), py::arg("Q1"), py::arg("Tol"), py::arg("DomInf"), py::arg("DomSup"), py::arg("TwoZForATheta"), py::arg("ZIsPositive"));
cls_IntAna_Curve.def("IsOpen", (Standard_Boolean (IntAna_Curve::*)() const) &IntAna_Curve::IsOpen, "Returns TRUE if the curve is not infinite at the last parameter or at the first parameter of the domain.");
cls_IntAna_Curve.def("Domain", [](IntAna_Curve &self, Standard_Real & Theta1, Standard_Real & Theta2){ self.Domain(Theta1, Theta2); return std::tuple<Standard_Real &, Standard_Real &>(Theta1, Theta2); }, "Returns the paramatric domain of the curve.", py::arg("Theta1"), py::arg("Theta2"));
cls_IntAna_Curve.def("IsConstant", (Standard_Boolean (IntAna_Curve::*)() const) &IntAna_Curve::IsConstant, "Returns TRUE if the function is constant.");
cls_IntAna_Curve.def("IsFirstOpen", (Standard_Boolean (IntAna_Curve::*)() const) &IntAna_Curve::IsFirstOpen, "Returns TRUE if the domain is open at the beginning.");
cls_IntAna_Curve.def("IsLastOpen", (Standard_Boolean (IntAna_Curve::*)() const) &IntAna_Curve::IsLastOpen, "Returns TRUE if the domain is open at the end.");
cls_IntAna_Curve.def("Value", (gp_Pnt (IntAna_Curve::*)(const Standard_Real)) &IntAna_Curve::Value, "Returns the point at parameter Theta on the curve.", py::arg("Theta"));
cls_IntAna_Curve.def("D1u", (Standard_Boolean (IntAna_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &)) &IntAna_Curve::D1u, "Returns the point and the first derivative at parameter Theta on the curve.", py::arg("Theta"), py::arg("P"), py::arg("V"));
cls_IntAna_Curve.def("FindParameter", [](IntAna_Curve &self, const gp_Pnt & P, Standard_Real & Para){ Standard_Boolean rv = self.FindParameter(P, Para); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Para); }, "Tries to find the parameter of the point P on the curve. If the method returns False, the 'projection' is impossible, and the value of Para is not significant. If the method returns True, Para is the parameter of the nearest intersection between the curve and the iso-theta containing P.", py::arg("P"), py::arg("Para"));
cls_IntAna_Curve.def("SetIsFirstOpen", (void (IntAna_Curve::*)(const Standard_Boolean)) &IntAna_Curve::SetIsFirstOpen, "If flag is True, the Curve is not defined at the first parameter of its domain.", py::arg("Flag"));
cls_IntAna_Curve.def("SetIsLastOpen", (void (IntAna_Curve::*)(const Standard_Boolean)) &IntAna_Curve::SetIsLastOpen, "If flag is True, the Curve is not defined at the first parameter of its domain.", py::arg("Flag"));
cls_IntAna_Curve.def("InternalUVValue", [](IntAna_Curve &self, const Standard_Real Param, Standard_Real & U, Standard_Real & V, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & Co, Standard_Real & Si, Standard_Real & Di){ self.InternalUVValue(Param, U, V, A, B, C, Co, Si, Di); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U, V, A, B, C, Co, Si, Di); }, "Protected function.", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("Co"), py::arg("Si"), py::arg("Di"));
cls_IntAna_Curve.def("SetDomain", (void (IntAna_Curve::*)(const Standard_Real, const Standard_Real)) &IntAna_Curve::SetDomain, "None", py::arg("Theta1"), py::arg("Theta2"));

// Enums

}