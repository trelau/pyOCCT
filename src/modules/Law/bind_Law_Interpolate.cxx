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
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <Law_BSpline.hxx>
#include <Law_Interpolate.hxx>

void bind_Law_Interpolate(py::module &mod){

py::class_<Law_Interpolate> cls_Law_Interpolate(mod, "Law_Interpolate", "This class is used to interpolate a BsplineCurve passing through an array of points, with a C2 Continuity if tangency is not requested at the point. If tangency is requested at the point the continuity will be C1. If Perodicity is requested the curve will be closed and the junction will be the first point given. The curve will than be only C1");

// Constructors
cls_Law_Interpolate.def(py::init<const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("PeriodicFlag"), py::arg("Tolerance"));
cls_Law_Interpolate.def(py::init<const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("Parameters"), py::arg("PeriodicFlag"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Law_Interpolate.def_static("operator new_", (void * (*)(size_t)) &Law_Interpolate::operator new, "None", py::arg("theSize"));
// cls_Law_Interpolate.def_static("operator delete_", (void (*)(void *)) &Law_Interpolate::operator delete, "None", py::arg("theAddress"));
// cls_Law_Interpolate.def_static("operator new[]_", (void * (*)(size_t)) &Law_Interpolate::operator new[], "None", py::arg("theSize"));
// cls_Law_Interpolate.def_static("operator delete[]_", (void (*)(void *)) &Law_Interpolate::operator delete[], "None", py::arg("theAddress"));
// cls_Law_Interpolate.def_static("operator new_", (void * (*)(size_t, void *)) &Law_Interpolate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Law_Interpolate.def_static("operator delete_", (void (*)(void *, void *)) &Law_Interpolate::operator delete, "None", py::arg(""), py::arg(""));
cls_Law_Interpolate.def("Load", (void (Law_Interpolate::*)(const Standard_Real, const Standard_Real)) &Law_Interpolate::Load, "loads initial and final tangents if any.", py::arg("InitialTangent"), py::arg("FinalTangent"));
cls_Law_Interpolate.def("Load", (void (Law_Interpolate::*)(const TColStd_Array1OfReal &, const opencascade::handle<TColStd_HArray1OfBoolean> &)) &Law_Interpolate::Load, "loads the tangents. We should have as many tangents as they are points in the array if TangentFlags.Value(i) is Standard_True use the tangent Tangents.Value(i) otherwise the tangent is not constrained.", py::arg("Tangents"), py::arg("TangentFlags"));
// cls_Law_Interpolate.def("ClearTangents", (void (Law_Interpolate::*)()) &Law_Interpolate::ClearTangents, "Clears the tangents if any");
cls_Law_Interpolate.def("Perform", (void (Law_Interpolate::*)()) &Law_Interpolate::Perform, "Makes the interpolation");
cls_Law_Interpolate.def("Curve", (const opencascade::handle<Law_BSpline> & (Law_Interpolate::*)() const) &Law_Interpolate::Curve, "None");
cls_Law_Interpolate.def("IsDone", (Standard_Boolean (Law_Interpolate::*)() const) &Law_Interpolate::IsDone, "None");

// Enums

}