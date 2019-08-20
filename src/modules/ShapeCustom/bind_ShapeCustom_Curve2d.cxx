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
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Line.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <ShapeCustom_Curve2d.hxx>

void bind_ShapeCustom_Curve2d(py::module &mod){

py::class_<ShapeCustom_Curve2d, std::unique_ptr<ShapeCustom_Curve2d>> cls_ShapeCustom_Curve2d(mod, "ShapeCustom_Curve2d", "Converts curve2d to analytical form with given precision or simpify curve2d.");

// Constructors

// Fields

// Methods
// cls_ShapeCustom_Curve2d.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom_Curve2d::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom_Curve2d.def_static("operator delete_", (void (*)(void *)) &ShapeCustom_Curve2d::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve2d.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom_Curve2d::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom_Curve2d.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom_Curve2d::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve2d.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom_Curve2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom_Curve2d.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom_Curve2d::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom_Curve2d.def_static("IsLinear_", [](const TColgp_Array1OfPnt2d & thePoles, const Standard_Real theTolerance, Standard_Real & theDeviation){ Standard_Boolean rv = ShapeCustom_Curve2d::IsLinear(thePoles, theTolerance, theDeviation); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDeviation); }, "Check if poleses is in the plane with given precision Returns false if no.", py::arg("thePoles"), py::arg("theTolerance"), py::arg("theDeviation"));
cls_ShapeCustom_Curve2d.def_static("ConvertToLine2d_", [](const opencascade::handle<Geom2d_Curve> & theCurve, const Standard_Real theFirstIn, const Standard_Real theLastIn, const Standard_Real theTolerance, Standard_Real & theNewFirst, Standard_Real & theNewLast, Standard_Real & theDeviation){ opencascade::handle<Geom2d_Line> rv = ShapeCustom_Curve2d::ConvertToLine2d(theCurve, theFirstIn, theLastIn, theTolerance, theNewFirst, theNewLast, theDeviation); return std::tuple<opencascade::handle<Geom2d_Line>, Standard_Real &, Standard_Real &, Standard_Real &>(rv, theNewFirst, theNewLast, theDeviation); }, "Try to convert BSpline2d or Bezier2d to line 2d only if it is linear. Recalculate first and last parameters. Returns line2d or null curve2d.", py::arg("theCurve"), py::arg("theFirstIn"), py::arg("theLastIn"), py::arg("theTolerance"), py::arg("theNewFirst"), py::arg("theNewLast"), py::arg("theDeviation"));
cls_ShapeCustom_Curve2d.def_static("SimplifyBSpline2d_", (Standard_Boolean (*)(opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real)) &ShapeCustom_Curve2d::SimplifyBSpline2d, "Try to remove knots from bspline where local derivatives are the same. Remove knots with given precision. Returns false if Bsplien was not modified", py::arg("theBSpline2d"), py::arg("theTolerance"));

// Enums

}