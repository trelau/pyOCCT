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
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <IntImp_ConstIsoparametric.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Vec.hxx>
#include <BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.hxx>

void bind_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox(py::module &mod){

py::class_<BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox, std::unique_ptr<BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox>, math_FunctionSetWithDerivatives> cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox(mod, "BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox", "None");

// Constructors
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def(py::init<const BRepAdaptor_Surface &, const BRepAdaptor_Surface &>(), py::arg("S1"), py::arg("S2"));

// Fields

// Methods
// cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("NbVariables", (Standard_Integer (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::NbVariables, "None");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("NbEquations", (Standard_Integer (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::NbEquations, "None");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Value", (Standard_Boolean (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)(const math_Vector &, math_Vector &)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::Value, "None", py::arg("X"), py::arg("F"));
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Derivatives", (Standard_Boolean (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)(const math_Vector &, math_Matrix &)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Values", (Standard_Boolean (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("ComputeParameters", (void (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)(const IntImp_ConstIsoparametric, const TColStd_Array1OfReal &, math_Vector &, math_Vector &, math_Vector &, math_Vector &)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::ComputeParameters, "None", py::arg("ChoixIso"), py::arg("Param"), py::arg("UVap"), py::arg("BornInf"), py::arg("BornSup"), py::arg("Tolerance"));
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Root", (Standard_Real (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::Root, "returns somme des fi*fi");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Point", (gp_Pnt (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::Point, "None");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("IsTangent", (Standard_Boolean (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)(const math_Vector &, TColStd_Array1OfReal &, IntImp_ConstIsoparametric &)) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::IsTangent, "None", py::arg("UVap"), py::arg("Param"), py::arg("BestChoix"));
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Direction", (gp_Dir (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::Direction, "None");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("DirectionOnS1", (gp_Dir2d (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::DirectionOnS1, "None");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("DirectionOnS2", (gp_Dir2d (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::DirectionOnS2, "None");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("AuxillarSurface1", (const BRepAdaptor_Surface & (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::AuxillarSurface1, "None");
cls_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.def("AuxillarSurface2", (const BRepAdaptor_Surface & (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox::AuxillarSurface2, "None");

// Enums

}