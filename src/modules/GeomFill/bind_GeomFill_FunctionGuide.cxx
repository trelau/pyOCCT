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
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_XYZ.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Vec.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <GeomFill_FunctionGuide.hxx>

void bind_GeomFill_FunctionGuide(py::module &mod){

py::class_<GeomFill_FunctionGuide, math_FunctionSetWithDerivatives> cls_GeomFill_FunctionGuide(mod, "GeomFill_FunctionGuide", "None");

// Constructors
cls_GeomFill_FunctionGuide.def(py::init<const opencascade::handle<GeomFill_SectionLaw> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("Guide"));
cls_GeomFill_FunctionGuide.def(py::init<const opencascade::handle<GeomFill_SectionLaw> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("S"), py::arg("Guide"), py::arg("ParamOnLaw"));

// Fields

// Methods
// cls_GeomFill_FunctionGuide.def_static("operator new_", (void * (*)(size_t)) &GeomFill_FunctionGuide::operator new, "None", py::arg("theSize"));
// cls_GeomFill_FunctionGuide.def_static("operator delete_", (void (*)(void *)) &GeomFill_FunctionGuide::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_FunctionGuide.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_FunctionGuide::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_FunctionGuide.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_FunctionGuide::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_FunctionGuide.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_FunctionGuide::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_FunctionGuide.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_FunctionGuide::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_FunctionGuide.def("SetParam", (void (GeomFill_FunctionGuide::*)(const Standard_Real, const gp_Pnt &, const gp_XYZ &, const gp_XYZ &)) &GeomFill_FunctionGuide::SetParam, "None", py::arg("Param"), py::arg("Centre"), py::arg("Dir"), py::arg("XDir"));
cls_GeomFill_FunctionGuide.def("NbVariables", (Standard_Integer (GeomFill_FunctionGuide::*)() const) &GeomFill_FunctionGuide::NbVariables, "returns the number of variables of the function.");
cls_GeomFill_FunctionGuide.def("NbEquations", (Standard_Integer (GeomFill_FunctionGuide::*)() const) &GeomFill_FunctionGuide::NbEquations, "returns the number of equations of the function.");
cls_GeomFill_FunctionGuide.def("Value", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, math_Vector &)) &GeomFill_FunctionGuide::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_GeomFill_FunctionGuide.def("Derivatives", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, math_Matrix &)) &GeomFill_FunctionGuide::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_GeomFill_FunctionGuide.def("Values", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, math_Vector &, math_Matrix &)) &GeomFill_FunctionGuide::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomFill_FunctionGuide.def("DerivT", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, const gp_XYZ &, const gp_XYZ &, math_Vector &)) &GeomFill_FunctionGuide::DerivT, "returns the values <F> of the T derivatives for the parameter Param .", py::arg("X"), py::arg("DCentre"), py::arg("DDir"), py::arg("DFDT"));
// cls_GeomFill_FunctionGuide.def("Deriv2T", (Standard_Boolean (GeomFill_FunctionGuide::*)(const gp_XYZ &, const gp_XYZ &, math_Vector &, math_Vector &)) &GeomFill_FunctionGuide::Deriv2T, "returns the values <F> of the T2 derivatives for the parameter Param . returns the values <D> of the TX derivatives for the parameter Param . returns Boolean is static; returns the values <T> of the X2 derivatives for the parameter Param . returns Boolean is static;", py::arg("DCentre"), py::arg("DDir"), py::arg("DFDT"), py::arg("D2FT"));

// Enums

}