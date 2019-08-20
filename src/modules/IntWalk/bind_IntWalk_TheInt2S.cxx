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
#include <IntWalk_TheFunctionOfTheInt2S.hxx>
#include <IntWalk_TheInt2S.hxx>

void bind_IntWalk_TheInt2S(py::module &mod){

py::class_<IntWalk_TheInt2S, std::unique_ptr<IntWalk_TheInt2S>> cls_IntWalk_TheInt2S(mod, "IntWalk_TheInt2S", "None");

// Constructors
cls_IntWalk_TheInt2S.def(py::init<const TColStd_Array1OfReal &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("Param"), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));
cls_IntWalk_TheInt2S.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));

// Fields

// Methods
// cls_IntWalk_TheInt2S.def_static("operator new_", (void * (*)(size_t)) &IntWalk_TheInt2S::operator new, "None", py::arg("theSize"));
// cls_IntWalk_TheInt2S.def_static("operator delete_", (void (*)(void *)) &IntWalk_TheInt2S::operator delete, "None", py::arg("theAddress"));
// cls_IntWalk_TheInt2S.def_static("operator new[]_", (void * (*)(size_t)) &IntWalk_TheInt2S::operator new[], "None", py::arg("theSize"));
// cls_IntWalk_TheInt2S.def_static("operator delete[]_", (void (*)(void *)) &IntWalk_TheInt2S::operator delete[], "None", py::arg("theAddress"));
// cls_IntWalk_TheInt2S.def_static("operator new_", (void * (*)(size_t, void *)) &IntWalk_TheInt2S::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntWalk_TheInt2S.def_static("operator delete_", (void (*)(void *, void *)) &IntWalk_TheInt2S::operator delete, "None", py::arg(""), py::arg(""));
cls_IntWalk_TheInt2S.def("Perform", (IntImp_ConstIsoparametric (IntWalk_TheInt2S::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &)) &IntWalk_TheInt2S::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is calculated)", py::arg("Param"), py::arg("Rsnld"));
cls_IntWalk_TheInt2S.def("Perform", (IntImp_ConstIsoparametric (IntWalk_TheInt2S::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &, const IntImp_ConstIsoparametric)) &IntWalk_TheInt2S::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is given by ChoixIso)", py::arg("Param"), py::arg("Rsnld"), py::arg("ChoixIso"));
cls_IntWalk_TheInt2S.def("IsDone", (Standard_Boolean (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::IsDone, "Returns TRUE if the creation completed without failure.");
cls_IntWalk_TheInt2S.def("IsEmpty", (Standard_Boolean (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::IsEmpty, "Returns TRUE when there is no solution to the problem.");
cls_IntWalk_TheInt2S.def("Point", (const IntSurf_PntOn2S & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::Point, "Returns the intersection point.");
cls_IntWalk_TheInt2S.def("IsTangent", (Standard_Boolean (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::IsTangent, "Returns True if the surfaces are tangent at the intersection point.");
cls_IntWalk_TheInt2S.def("Direction", (const gp_Dir & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::Direction, "Returns the tangent at the intersection line.");
cls_IntWalk_TheInt2S.def("DirectionOnS1", (const gp_Dir2d & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::DirectionOnS1, "Returns the tangent at the intersection line in the parametric space of the first surface.");
cls_IntWalk_TheInt2S.def("DirectionOnS2", (const gp_Dir2d & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::DirectionOnS2, "Returns the tangent at the intersection line in the parametric space of the second surface.");
cls_IntWalk_TheInt2S.def("Function", (IntWalk_TheFunctionOfTheInt2S & (IntWalk_TheInt2S::*)()) &IntWalk_TheInt2S::Function, "return the math function which is used to compute the intersection");
cls_IntWalk_TheInt2S.def("ChangePoint", (IntSurf_PntOn2S & (IntWalk_TheInt2S::*)()) &IntWalk_TheInt2S::ChangePoint, "return the intersection point which is enable for changing.");

// Enums

}