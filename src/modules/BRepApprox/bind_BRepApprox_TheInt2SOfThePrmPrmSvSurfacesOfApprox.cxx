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
#include <TColStd_Array1OfReal.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <IntImp_ConstIsoparametric.hxx>
#include <math_FunctionSetRoot.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.hxx>
#include <BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.hxx>

void bind_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox(py::module &mod){

py::class_<BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox> cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox(mod, "BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox", "None");

// Constructors
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def(py::init<const TColStd_Array1OfReal &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, const Standard_Real>(), py::arg("Param"), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def(py::init<const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));

// Fields

// Methods
// cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Perform", (IntImp_ConstIsoparametric (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is calculated)", py::arg("Param"), py::arg("Rsnld"));
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Perform", (IntImp_ConstIsoparametric (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &, const IntImp_ConstIsoparametric)) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is given by ChoixIso)", py::arg("Param"), py::arg("Rsnld"), py::arg("ChoixIso"));
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("IsDone", (Standard_Boolean (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::IsDone, "Returns TRUE if the creation completed without failure.");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("IsEmpty", (Standard_Boolean (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::IsEmpty, "Returns TRUE when there is no solution to the problem.");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Point", (const IntSurf_PntOn2S & (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::Point, "Returns the intersection point.");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("IsTangent", (Standard_Boolean (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::IsTangent, "Returns True if the surfaces are tangent at the intersection point.");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Direction", (const gp_Dir & (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::Direction, "Returns the tangent at the intersection line.");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("DirectionOnS1", (const gp_Dir2d & (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::DirectionOnS1, "Returns the tangent at the intersection line in the parametric space of the first surface.");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("DirectionOnS2", (const gp_Dir2d & (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)() const) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::DirectionOnS2, "Returns the tangent at the intersection line in the parametric space of the second surface.");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("Function", (BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox & (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)()) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::Function, "return the math function which is used to compute the intersection");
cls_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.def("ChangePoint", (IntSurf_PntOn2S & (BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::*)()) &BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox::ChangePoint, "return the intersection point which is enable for changing.");

// Enums

}