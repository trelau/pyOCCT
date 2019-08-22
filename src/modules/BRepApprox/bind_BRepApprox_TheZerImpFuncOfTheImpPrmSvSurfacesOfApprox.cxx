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
#include <BRepAdaptor_Surface.hxx>
#include <IntSurf_Quadric.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.hxx>

void bind_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox(py::module &mod){

py::class_<BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox, math_FunctionSetWithDerivatives> cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox(mod, "BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox", "None");

// Constructors
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def(py::init<>());
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def(py::init<const BRepAdaptor_Surface &, const IntSurf_Quadric &>(), py::arg("PS"), py::arg("IS"));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def(py::init<const IntSurf_Quadric &>(), py::arg("IS"));

// Fields

// Methods
// cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Set", (void (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)(const BRepAdaptor_Surface &)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Set, "None", py::arg("PS"));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("SetImplicitSurface", (void (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)(const IntSurf_Quadric &)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::SetImplicitSurface, "None", py::arg("IS"));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Set", (void (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)(const Standard_Real)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Set, "None", py::arg("Tolerance"));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("NbVariables", (Standard_Integer (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::NbVariables, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("NbEquations", (Standard_Integer (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::NbEquations, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Value", (Standard_Boolean (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)(const math_Vector &, math_Vector &)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Value, "None", py::arg("X"), py::arg("F"));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Derivatives", (Standard_Boolean (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)(const math_Vector &, math_Matrix &)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Values", (Standard_Boolean (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Root", (Standard_Real (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Root, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Tolerance", (Standard_Real (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Tolerance, "Returns the value Tol so that if Abs(Func.Root())<Tol the function is considered null.");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Point", (const gp_Pnt & (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Point, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("IsTangent", (Standard_Boolean (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)()) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::IsTangent, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Direction3d", (const gp_Vec & (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)()) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Direction3d, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("Direction2d", (const gp_Dir2d & (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)()) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::Direction2d, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("PSurface", (const BRepAdaptor_Surface & (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::PSurface, "None");
cls_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.def("ISurface", (const IntSurf_Quadric & (BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox::ISurface, "None");

// Enums

}