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
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <GeomAbs_CurveType.hxx>
#include <IntTools_Curve.hxx>

void bind_IntTools_Curve(py::module &mod){

py::class_<IntTools_Curve, std::unique_ptr<IntTools_Curve>> cls_IntTools_Curve(mod, "IntTools_Curve", "The class is a container of one 3D curve, two 2D curves and two Tolerance values. It is used in the Face/Face intersection algorithm to store the results of intersection. In this context: **the 3D curve** is the intersection curve; **the 2D curves** are the PCurves of the 3D curve on the intersecting faces; **the tolerance** is the valid tolerance for 3D curve computed as maximal deviation between 3D curve and 2D curves (or surfaces in case there are no 2D curves); **the tangential tolerance** is the maximal distance from 3D curve to the end of the tangential zone between faces in terms of their tolerance values.");

// Constructors
cls_IntTools_Curve.def(py::init<>());
cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"));
cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"), py::arg("theTolerance"));
cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"), py::arg("theTolerance"), py::arg("theTangentialTolerance"));

// Fields

// Methods
// cls_IntTools_Curve.def_static("operator new_", (void * (*)(size_t)) &IntTools_Curve::operator new, "None", py::arg("theSize"));
// cls_IntTools_Curve.def_static("operator delete_", (void (*)(void *)) &IntTools_Curve::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_Curve.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_Curve::operator new[], "None", py::arg("theSize"));
// cls_IntTools_Curve.def_static("operator delete[]_", (void (*)(void *)) &IntTools_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_Curve.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_Curve.def("SetCurves", (void (IntTools_Curve::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetCurves, "Sets the curves", py::arg("the3dCurve"), py::arg("the2dCurve1"), py::arg("the2dCurve2"));
cls_IntTools_Curve.def("SetCurve", (void (IntTools_Curve::*)(const opencascade::handle<Geom_Curve> &)) &IntTools_Curve::SetCurve, "Sets the 3d curve", py::arg("the3dCurve"));
cls_IntTools_Curve.def("SetFirstCurve2d", (void (IntTools_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetFirstCurve2d, "Sets the first 2d curve", py::arg("the2dCurve1"));
cls_IntTools_Curve.def("SetSecondCurve2d", (void (IntTools_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetSecondCurve2d, "Sets the second 2d curve", py::arg("the2dCurve2"));
cls_IntTools_Curve.def("SetTolerance", (void (IntTools_Curve::*)(const Standard_Real)) &IntTools_Curve::SetTolerance, "Sets the tolerance for the curve", py::arg("theTolerance"));
cls_IntTools_Curve.def("SetTangentialTolerance", (void (IntTools_Curve::*)(const Standard_Real)) &IntTools_Curve::SetTangentialTolerance, "Sets the tangential tolerance", py::arg("theTangentialTolerance"));
cls_IntTools_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (IntTools_Curve::*)() const) &IntTools_Curve::Curve, "Returns 3d curve");
cls_IntTools_Curve.def("FirstCurve2d", (const opencascade::handle<Geom2d_Curve> & (IntTools_Curve::*)() const) &IntTools_Curve::FirstCurve2d, "Returns first 2d curve");
cls_IntTools_Curve.def("SecondCurve2d", (const opencascade::handle<Geom2d_Curve> & (IntTools_Curve::*)() const) &IntTools_Curve::SecondCurve2d, "Returns second 2d curve");
cls_IntTools_Curve.def("Tolerance", (Standard_Real (IntTools_Curve::*)() const) &IntTools_Curve::Tolerance, "Returns the tolerance");
cls_IntTools_Curve.def("TangentialTolerance", (Standard_Real (IntTools_Curve::*)() const) &IntTools_Curve::TangentialTolerance, "Returns the tangential tolerance");
cls_IntTools_Curve.def("HasBounds", (Standard_Boolean (IntTools_Curve::*)() const) &IntTools_Curve::HasBounds, "Returns TRUE if 3d curve is BoundedCurve");
cls_IntTools_Curve.def("Bounds", [](IntTools_Curve &self, Standard_Real & theFirst, Standard_Real & theLast, gp_Pnt & theFirstPnt, gp_Pnt & theLastPnt){ Standard_Boolean rv = self.Bounds(theFirst, theLast, theFirstPnt, theLastPnt); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirst, theLast); }, "If the 3d curve is bounded curve the method will return TRUE and modify the output parameters with boundary parameters of the curve and corresponded 3d points. If the curve does not have bounds, the method will return false and the output parameters will stay untouched.", py::arg("theFirst"), py::arg("theLast"), py::arg("theFirstPnt"), py::arg("theLastPnt"));
cls_IntTools_Curve.def("D0", (Standard_Boolean (IntTools_Curve::*)(const Standard_Real &, gp_Pnt &) const) &IntTools_Curve::D0, "Computes 3d point corresponded to the given parameter if this parameter is inside the boundaries of the curve. Returns TRUE in this case. Otherwise, the point will not be computed and the method will return FALSE.", py::arg("thePar"), py::arg("thePnt"));
cls_IntTools_Curve.def("Type", (GeomAbs_CurveType (IntTools_Curve::*)() const) &IntTools_Curve::Type, "Returns the type of the 3d curve");

// Enums

}