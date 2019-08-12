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
#include <GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.hxx>

void bind_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox(py::module &mod){

py::class_<GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox, std::unique_ptr<GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox, Deleter<GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox>>, math_FunctionSetWithDerivatives> cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox(mod, "GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox", "None");

// Constructors
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S1"), py::arg("S2"));

// Fields

// Methods
// cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("NbVariables", (Standard_Integer (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::NbVariables, "None");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("NbEquations", (Standard_Integer (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::NbEquations, "None");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Value", (Standard_Boolean (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)(const math_Vector &, math_Vector &)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Value, "None", py::arg("X"), py::arg("F"));
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Derivatives", (Standard_Boolean (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)(const math_Vector &, math_Matrix &)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Values", (Standard_Boolean (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)(const math_Vector &, math_Vector &, math_Matrix &)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("ComputeParameters", (void (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)(const IntImp_ConstIsoparametric, const TColStd_Array1OfReal &, math_Vector &, math_Vector &, math_Vector &, math_Vector &)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::ComputeParameters, "None", py::arg("ChoixIso"), py::arg("Param"), py::arg("UVap"), py::arg("BornInf"), py::arg("BornSup"), py::arg("Tolerance"));
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Root", (Standard_Real (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Root, "returns somme des fi*fi");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Point", (gp_Pnt (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Point, "None");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("IsTangent", (Standard_Boolean (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)(const math_Vector &, TColStd_Array1OfReal &, IntImp_ConstIsoparametric &)) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::IsTangent, "None", py::arg("UVap"), py::arg("Param"), py::arg("BestChoix"));
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Direction", (gp_Dir (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Direction, "None");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("DirectionOnS1", (gp_Dir2d (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::DirectionOnS1, "None");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("DirectionOnS2", (gp_Dir2d (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::DirectionOnS2, "None");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("AuxillarSurface1", (const opencascade::handle<Adaptor3d_HSurface> & (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::AuxillarSurface1, "None");
cls_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("AuxillarSurface2", (const opencascade::handle<Adaptor3d_HSurface> & (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox::AuxillarSurface2, "None");

// Enums

}