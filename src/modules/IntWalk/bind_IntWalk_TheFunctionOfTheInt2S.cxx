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
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <IntImp_ConstIsoparametric.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Vec.hxx>
#include <IntWalk_TheFunctionOfTheInt2S.hxx>

void bind_IntWalk_TheFunctionOfTheInt2S(py::module &mod){

py::class_<IntWalk_TheFunctionOfTheInt2S, std::unique_ptr<IntWalk_TheFunctionOfTheInt2S>, math_FunctionSetWithDerivatives> cls_IntWalk_TheFunctionOfTheInt2S(mod, "IntWalk_TheFunctionOfTheInt2S", "None");

// Constructors
cls_IntWalk_TheFunctionOfTheInt2S.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S1"), py::arg("S2"));

// Fields

// Methods
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator new_", (void * (*)(size_t)) &IntWalk_TheFunctionOfTheInt2S::operator new, "None", py::arg("theSize"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator delete_", (void (*)(void *)) &IntWalk_TheFunctionOfTheInt2S::operator delete, "None", py::arg("theAddress"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator new[]_", (void * (*)(size_t)) &IntWalk_TheFunctionOfTheInt2S::operator new[], "None", py::arg("theSize"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator delete[]_", (void (*)(void *)) &IntWalk_TheFunctionOfTheInt2S::operator delete[], "None", py::arg("theAddress"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator new_", (void * (*)(size_t, void *)) &IntWalk_TheFunctionOfTheInt2S::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator delete_", (void (*)(void *, void *)) &IntWalk_TheFunctionOfTheInt2S::operator delete, "None", py::arg(""), py::arg(""));
cls_IntWalk_TheFunctionOfTheInt2S.def("NbVariables", (Standard_Integer (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::NbVariables, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("NbEquations", (Standard_Integer (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::NbEquations, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("Value", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Vector &)) &IntWalk_TheFunctionOfTheInt2S::Value, "None", py::arg("X"), py::arg("F"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Derivatives", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Matrix &)) &IntWalk_TheFunctionOfTheInt2S::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Values", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntWalk_TheFunctionOfTheInt2S::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_IntWalk_TheFunctionOfTheInt2S.def("ComputeParameters", (void (IntWalk_TheFunctionOfTheInt2S::*)(const IntImp_ConstIsoparametric, const TColStd_Array1OfReal &, math_Vector &, math_Vector &, math_Vector &, math_Vector &)) &IntWalk_TheFunctionOfTheInt2S::ComputeParameters, "None", py::arg("ChoixIso"), py::arg("Param"), py::arg("UVap"), py::arg("BornInf"), py::arg("BornSup"), py::arg("Tolerance"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Root", (Standard_Real (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::Root, "returns somme des fi*fi");
cls_IntWalk_TheFunctionOfTheInt2S.def("Point", (gp_Pnt (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::Point, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("IsTangent", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, TColStd_Array1OfReal &, IntImp_ConstIsoparametric &)) &IntWalk_TheFunctionOfTheInt2S::IsTangent, "None", py::arg("UVap"), py::arg("Param"), py::arg("BestChoix"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Direction", (gp_Dir (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::Direction, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("DirectionOnS1", (gp_Dir2d (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::DirectionOnS1, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("DirectionOnS2", (gp_Dir2d (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::DirectionOnS2, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("AuxillarSurface1", (const opencascade::handle<Adaptor3d_HSurface> & (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::AuxillarSurface1, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("AuxillarSurface2", (const opencascade::handle<Adaptor3d_HSurface> & (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::AuxillarSurface2, "None");

// Enums

}