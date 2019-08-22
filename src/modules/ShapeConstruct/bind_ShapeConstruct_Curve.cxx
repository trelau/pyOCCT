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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <ShapeConstruct_Curve.hxx>

void bind_ShapeConstruct_Curve(py::module &mod){

py::class_<ShapeConstruct_Curve> cls_ShapeConstruct_Curve(mod, "ShapeConstruct_Curve", "Adjusts curve to have start and end points at the given points (currently works on lines and B-Splines only)");

// Constructors

// Fields

// Methods
// cls_ShapeConstruct_Curve.def_static("operator new_", (void * (*)(size_t)) &ShapeConstruct_Curve::operator new, "None", py::arg("theSize"));
// cls_ShapeConstruct_Curve.def_static("operator delete_", (void (*)(void *)) &ShapeConstruct_Curve::operator delete, "None", py::arg("theAddress"));
// cls_ShapeConstruct_Curve.def_static("operator new[]_", (void * (*)(size_t)) &ShapeConstruct_Curve::operator new[], "None", py::arg("theSize"));
// cls_ShapeConstruct_Curve.def_static("operator delete[]_", (void (*)(void *)) &ShapeConstruct_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeConstruct_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeConstruct_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeConstruct_Curve.def_static("operator delete_", (void (*)(void *, void *)) &ShapeConstruct_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeConstruct_Curve.def("AdjustCurve", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom_Curve> & a0, const gp_Pnt & a1, const gp_Pnt & a2) -> Standard_Boolean { return self.AdjustCurve(a0, a1, a2); });
cls_ShapeConstruct_Curve.def("AdjustCurve", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom_Curve> & a0, const gp_Pnt & a1, const gp_Pnt & a2, const Standard_Boolean a3) -> Standard_Boolean { return self.AdjustCurve(a0, a1, a2, a3); });
cls_ShapeConstruct_Curve.def("AdjustCurve", (Standard_Boolean (ShapeConstruct_Curve::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean, const Standard_Boolean) const) &ShapeConstruct_Curve::AdjustCurve, "Modifies a curve in order to make its bounds confused with given points. Works only on lines and B-Splines, returns True in this case, else returns False. For line considers both bounding points, for B-Splines only specified.", py::arg("C3D"), py::arg("P1"), py::arg("P2"), py::arg("take1"), py::arg("take2"));
cls_ShapeConstruct_Curve.def("AdjustCurveSegment", (Standard_Boolean (ShapeConstruct_Curve::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real) const) &ShapeConstruct_Curve::AdjustCurveSegment, "Modifies a curve in order to make its bounds confused with given points. Works only on lines and B-Splines.", py::arg("C3D"), py::arg("P1"), py::arg("P2"), py::arg("U1"), py::arg("U2"));
cls_ShapeConstruct_Curve.def("AdjustCurve2d", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom2d_Curve> & a0, const gp_Pnt2d & a1, const gp_Pnt2d & a2) -> Standard_Boolean { return self.AdjustCurve2d(a0, a1, a2); });
cls_ShapeConstruct_Curve.def("AdjustCurve2d", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom2d_Curve> & a0, const gp_Pnt2d & a1, const gp_Pnt2d & a2, const Standard_Boolean a3) -> Standard_Boolean { return self.AdjustCurve2d(a0, a1, a2, a3); });
cls_ShapeConstruct_Curve.def("AdjustCurve2d", (Standard_Boolean (ShapeConstruct_Curve::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean, const Standard_Boolean) const) &ShapeConstruct_Curve::AdjustCurve2d, "Modifies a curve in order to make its bounds confused with given points. Works only on lines and B-Splines, returns True in this case, else returns False.", py::arg("C2D"), py::arg("P1"), py::arg("P2"), py::arg("take1"), py::arg("take2"));
cls_ShapeConstruct_Curve.def("ConvertToBSpline", (opencascade::handle<Geom_BSplineCurve> (ShapeConstruct_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real) const) &ShapeConstruct_Curve::ConvertToBSpline, "Converts a curve of any type (only part from first to last) to bspline. The method of conversion depends on the type of original curve: BSpline -> C.Segment(first,last) Bezier and Line -> GeomConvert::CurveToBSplineCurve(C).Segment(first,last) Conic and Other -> Approx_Curve3d(C[first,last],prec,C1,9,1000)", py::arg("C"), py::arg("first"), py::arg("last"), py::arg("prec"));
cls_ShapeConstruct_Curve.def("ConvertToBSpline", (opencascade::handle<Geom2d_BSplineCurve> (ShapeConstruct_Curve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real) const) &ShapeConstruct_Curve::ConvertToBSpline, "Converts a curve of any type (only part from first to last) to bspline. The method of conversion depends on the type of original curve: BSpline -> C.Segment(first,last) Bezier and Line -> GeomConvert::CurveToBSplineCurve(C).Segment(first,last) Conic and Other -> Approx_Curve2d(C[first,last],prec,C1,9,1000)", py::arg("C"), py::arg("first"), py::arg("last"), py::arg("prec"));
cls_ShapeConstruct_Curve.def_static("FixKnots_", (Standard_Boolean (*)(opencascade::handle<TColStd_HArray1OfReal> &)) &ShapeConstruct_Curve::FixKnots, "None", py::arg("knots"));
cls_ShapeConstruct_Curve.def_static("FixKnots_", (Standard_Boolean (*)(TColStd_Array1OfReal &)) &ShapeConstruct_Curve::FixKnots, "Fix bspline knots to ensure that there is enough gap between neighbouring values Returns True if something fixed (by shifting knot)", py::arg("knots"));

// Enums

}