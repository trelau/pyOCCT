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
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Vec2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <Geom2dAPI_Interpolate.hxx>

void bind_Geom2dAPI_Interpolate(py::module &mod){

py::class_<Geom2dAPI_Interpolate, std::unique_ptr<Geom2dAPI_Interpolate>> cls_Geom2dAPI_Interpolate(mod, "Geom2dAPI_Interpolate", "This class is used to interpolate a BsplineCurve passing through an array of points, with a C2 Continuity if tangency is not requested at the point. If tangency is requested at the point the continuity will be C1. If Perodicity is requested the curve will be closed and the junction will be the first point given. The curve will than be only C1 The curve is defined by a table of points through which it passes, and if required by a parallel table of reals which gives the value of the parameter of each point through which the resulting BSpline curve passes, and by vectors tangential to these points. An Interpolate object provides a framework for: defining the constraints of the BSpline curve, - implementing the interpolation algorithm, and consulting the results.");

// Constructors
cls_Geom2dAPI_Interpolate.def(py::init<const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("PeriodicFlag"), py::arg("Tolerance"));
cls_Geom2dAPI_Interpolate.def(py::init<const opencascade::handle<TColgp_HArray1OfPnt2d> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("Parameters"), py::arg("PeriodicFlag"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dAPI_Interpolate.def_static("operator new_", (void * (*)(size_t)) &Geom2dAPI_Interpolate::operator new, "None", py::arg("theSize"));
// cls_Geom2dAPI_Interpolate.def_static("operator delete_", (void (*)(void *)) &Geom2dAPI_Interpolate::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dAPI_Interpolate.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dAPI_Interpolate::operator new[], "None", py::arg("theSize"));
// cls_Geom2dAPI_Interpolate.def_static("operator delete[]_", (void (*)(void *)) &Geom2dAPI_Interpolate::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dAPI_Interpolate.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dAPI_Interpolate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dAPI_Interpolate.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dAPI_Interpolate::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dAPI_Interpolate.def("Load", [](Geom2dAPI_Interpolate &self, const gp_Vec2d & a0, const gp_Vec2d & a1) -> void { return self.Load(a0, a1); });
cls_Geom2dAPI_Interpolate.def("Load", (void (Geom2dAPI_Interpolate::*)(const gp_Vec2d &, const gp_Vec2d &, const Standard_Boolean)) &Geom2dAPI_Interpolate::Load, "Assigns this constrained BSpline curve to be tangential to vectors InitialTangent and FinalTangent at its first and last points respectively (i.e. the first and last points of the table of points through which the curve passes, as defined at the time of initialization). <Scale> - boolean flag defining whether tangent vectors are to be scaled according to derivatives of lagrange interpolation.", py::arg("InitialTangent"), py::arg("FinalTangent"), py::arg("Scale"));
cls_Geom2dAPI_Interpolate.def("Load", [](Geom2dAPI_Interpolate &self, const TColgp_Array1OfVec2d & a0, const opencascade::handle<TColStd_HArray1OfBoolean> & a1) -> void { return self.Load(a0, a1); });
cls_Geom2dAPI_Interpolate.def("Load", (void (Geom2dAPI_Interpolate::*)(const TColgp_Array1OfVec2d &, const opencascade::handle<TColStd_HArray1OfBoolean> &, const Standard_Boolean)) &Geom2dAPI_Interpolate::Load, "Assigns this constrained BSpline curve to be tangential to vectors defined in the table Tangents, which is parallel to the table of points through which the curve passes, as defined at the time of initialization. Vectors in the table Tangents are defined only if the flag given in the parallel table TangentFlags is true: only these vectors are set as tangency constraints. <Scale> - boolean flag defining whether tangent vectors are to be scaled according to derivatives of lagrange interpolation.", py::arg("Tangents"), py::arg("TangentFlags"), py::arg("Scale"));
// cls_Geom2dAPI_Interpolate.def("ClearTangents", (void (Geom2dAPI_Interpolate::*)()) &Geom2dAPI_Interpolate::ClearTangents, "Clears all tangency constraints on this constrained BSpline curve (as initialized by the function Load).");
cls_Geom2dAPI_Interpolate.def("Perform", (void (Geom2dAPI_Interpolate::*)()) &Geom2dAPI_Interpolate::Perform, "Computes the constrained BSpline curve. Use the function IsDone to verify that the computation is successful, and then the function Curve to obtain the result.");
cls_Geom2dAPI_Interpolate.def("Curve", (const opencascade::handle<Geom2d_BSplineCurve> & (Geom2dAPI_Interpolate::*)() const) &Geom2dAPI_Interpolate::Curve, "Returns the computed BSpline curve. Raises StdFail_NotDone if the interpolation fails.");
cls_Geom2dAPI_Interpolate.def("IsDone", (Standard_Boolean (Geom2dAPI_Interpolate::*)() const) &Geom2dAPI_Interpolate::IsDone, "Returns true if the constrained BSpline curve is successfully constructed. Note: in this case, the result is given by the function Curve.");

// Enums

}