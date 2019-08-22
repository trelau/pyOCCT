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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <IntImp_ConstIsoparametric.hxx>
#include <math_FunctionSetRoot.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.hxx>

void bind_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox(py::module &mod){

py::class_<GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox> cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox(mod, "GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox", "None");

// Constructors
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def(py::init<const TColStd_Array1OfReal &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("Param"), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));

// Fields

// Methods
// cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Perform", (IntImp_ConstIsoparametric (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is calculated)", py::arg("Param"), py::arg("Rsnld"));
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Perform", (IntImp_ConstIsoparametric (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &, const IntImp_ConstIsoparametric)) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is given by ChoixIso)", py::arg("Param"), py::arg("Rsnld"), py::arg("ChoixIso"));
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("IsDone", (Standard_Boolean (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::IsDone, "Returns TRUE if the creation completed without failure.");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("IsEmpty", (Standard_Boolean (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::IsEmpty, "Returns TRUE when there is no solution to the problem.");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Point", (const IntSurf_PntOn2S & (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Point, "Returns the intersection point.");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("IsTangent", (Standard_Boolean (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::IsTangent, "Returns True if the surfaces are tangent at the intersection point.");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Direction", (const gp_Dir & (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Direction, "Returns the tangent at the intersection line.");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("DirectionOnS1", (const gp_Dir2d & (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::DirectionOnS1, "Returns the tangent at the intersection line in the parametric space of the first surface.");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("DirectionOnS2", (const gp_Dir2d & (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)() const) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::DirectionOnS2, "Returns the tangent at the intersection line in the parametric space of the second surface.");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("Function", (GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox & (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)()) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::Function, "return the math function which is used to compute the intersection");
cls_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.def("ChangePoint", (IntSurf_PntOn2S & (GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::*)()) &GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox::ChangePoint, "return the intersection point which is enable for changing.");

// Enums

}