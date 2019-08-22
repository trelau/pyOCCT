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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <Contap_TFunction.hxx>
#include <Contap_SurfFunction.hxx>

void bind_Contap_SurfFunction(py::module &mod){

py::class_<Contap_SurfFunction, math_FunctionSetWithDerivatives> cls_Contap_SurfFunction(mod, "Contap_SurfFunction", "This class describes the function on a parametric surface. the form of the function is F(u,v) = 0 where u and v are the parameteric coordinates of a point on the surface, to compute the contours of the surface.");

// Constructors
cls_Contap_SurfFunction.def(py::init<>());

// Fields

// Methods
// cls_Contap_SurfFunction.def_static("operator new_", (void * (*)(size_t)) &Contap_SurfFunction::operator new, "None", py::arg("theSize"));
// cls_Contap_SurfFunction.def_static("operator delete_", (void (*)(void *)) &Contap_SurfFunction::operator delete, "None", py::arg("theAddress"));
// cls_Contap_SurfFunction.def_static("operator new[]_", (void * (*)(size_t)) &Contap_SurfFunction::operator new[], "None", py::arg("theSize"));
// cls_Contap_SurfFunction.def_static("operator delete[]_", (void (*)(void *)) &Contap_SurfFunction::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_SurfFunction.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_SurfFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_SurfFunction.def_static("operator delete_", (void (*)(void *, void *)) &Contap_SurfFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Contap_SurfFunction::Set, "None", py::arg("S"));
cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Pnt &)) &Contap_SurfFunction::Set, "None", py::arg("Eye"));
cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Dir &)) &Contap_SurfFunction::Set, "None", py::arg("Dir"));
cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Dir &, const Standard_Real)) &Contap_SurfFunction::Set, "None", py::arg("Dir"), py::arg("Angle"));
cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Pnt &, const Standard_Real)) &Contap_SurfFunction::Set, "None", py::arg("Eye"), py::arg("Angle"));
cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const Standard_Real)) &Contap_SurfFunction::Set, "None", py::arg("Tolerance"));
cls_Contap_SurfFunction.def("NbVariables", (Standard_Integer (Contap_SurfFunction::*)() const) &Contap_SurfFunction::NbVariables, "This method has to return 2.");
cls_Contap_SurfFunction.def("NbEquations", (Standard_Integer (Contap_SurfFunction::*)() const) &Contap_SurfFunction::NbEquations, "This method has to return 1.");
cls_Contap_SurfFunction.def("Value", (Standard_Boolean (Contap_SurfFunction::*)(const math_Vector &, math_Vector &)) &Contap_SurfFunction::Value, "The dimension of F is 1.", py::arg("X"), py::arg("F"));
cls_Contap_SurfFunction.def("Derivatives", (Standard_Boolean (Contap_SurfFunction::*)(const math_Vector &, math_Matrix &)) &Contap_SurfFunction::Derivatives, "The dimension of D is (1,2).", py::arg("X"), py::arg("D"));
cls_Contap_SurfFunction.def("Values", (Standard_Boolean (Contap_SurfFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Contap_SurfFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Contap_SurfFunction.def("Root", (Standard_Real (Contap_SurfFunction::*)() const) &Contap_SurfFunction::Root, "Root is the value of the function at the solution. It is a vector of dimension 1, i-e a real.");
cls_Contap_SurfFunction.def("Tolerance", (Standard_Real (Contap_SurfFunction::*)() const) &Contap_SurfFunction::Tolerance, "Returns the value Tol so that if Abs(Func.Root())<Tol the function is considered null.");
cls_Contap_SurfFunction.def("Point", (const gp_Pnt & (Contap_SurfFunction::*)() const) &Contap_SurfFunction::Point, "Returns the value of the solution point on the surface.");
cls_Contap_SurfFunction.def("IsTangent", (Standard_Boolean (Contap_SurfFunction::*)()) &Contap_SurfFunction::IsTangent, "None");
cls_Contap_SurfFunction.def("Direction3d", (const gp_Vec & (Contap_SurfFunction::*)()) &Contap_SurfFunction::Direction3d, "None");
cls_Contap_SurfFunction.def("Direction2d", (const gp_Dir2d & (Contap_SurfFunction::*)()) &Contap_SurfFunction::Direction2d, "None");
cls_Contap_SurfFunction.def("FunctionType", (Contap_TFunction (Contap_SurfFunction::*)() const) &Contap_SurfFunction::FunctionType, "None");
cls_Contap_SurfFunction.def("Eye", (const gp_Pnt & (Contap_SurfFunction::*)() const) &Contap_SurfFunction::Eye, "None");
cls_Contap_SurfFunction.def("Direction", (const gp_Dir & (Contap_SurfFunction::*)() const) &Contap_SurfFunction::Direction, "None");
cls_Contap_SurfFunction.def("Angle", (Standard_Real (Contap_SurfFunction::*)() const) &Contap_SurfFunction::Angle, "None");
cls_Contap_SurfFunction.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (Contap_SurfFunction::*)() const) &Contap_SurfFunction::Surface, "None");

// Enums

}