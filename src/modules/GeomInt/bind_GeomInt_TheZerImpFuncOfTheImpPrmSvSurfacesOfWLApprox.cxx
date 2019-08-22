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
#include <Adaptor3d_HSurface.hxx>
#include <IntSurf_Quadric.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.hxx>

void bind_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox(py::module &mod){

py::class_<GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox, math_FunctionSetWithDerivatives> cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox(mod, "GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox", "None");

// Constructors
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def(py::init<>());
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_Quadric &>(), py::arg("PS"), py::arg("IS"));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def(py::init<const IntSurf_Quadric &>(), py::arg("IS"));

// Fields

// Methods
// cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Set", (void (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Set, "None", py::arg("PS"));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("SetImplicitSurface", (void (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)(const IntSurf_Quadric &)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::SetImplicitSurface, "None", py::arg("IS"));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Set", (void (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)(const Standard_Real)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Set, "None", py::arg("Tolerance"));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("NbVariables", (Standard_Integer (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::NbVariables, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("NbEquations", (Standard_Integer (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::NbEquations, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Value", (Standard_Boolean (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)(const math_Vector &, math_Vector &)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Value, "None", py::arg("X"), py::arg("F"));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Derivatives", (Standard_Boolean (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)(const math_Vector &, math_Matrix &)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Values", (Standard_Boolean (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)(const math_Vector &, math_Vector &, math_Matrix &)) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Root", (Standard_Real (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Root, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Tolerance", (Standard_Real (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Tolerance, "Returns the value Tol so that if Abs(Func.Root())<Tol the function is considered null.");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Point", (const gp_Pnt & (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Point, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("IsTangent", (Standard_Boolean (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)()) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::IsTangent, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Direction3d", (const gp_Vec & (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)()) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Direction3d, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("Direction2d", (const gp_Dir2d & (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)()) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::Direction2d, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("PSurface", (const opencascade::handle<Adaptor3d_HSurface> & (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::PSurface, "None");
cls_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.def("ISurface", (const IntSurf_Quadric & (GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox::ISurface, "None");

// Enums

}