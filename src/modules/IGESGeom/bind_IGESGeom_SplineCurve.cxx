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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <IGESGeom_SplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_SplineCurve(py::module &mod){

py::class_<IGESGeom_SplineCurve, opencascade::handle<IGESGeom_SplineCurve>, IGESData_IGESEntity> cls_IGESGeom_SplineCurve(mod, "IGESGeom_SplineCurve", "Defines IGESSplineCurve, Type <112> Form <0> in package IGESGeom The parametric spline is a sequence of parametric polynomial segments. The curve could be of the type Linear, Quadratic, Cubic, Wilson-Fowler, Modified Wilson-Fowler, B-Spline. The N polynomial segments are delimited by the break points T(1), T(2), T(3), ..., T(N+1).");

// Constructors
cls_IGESGeom_SplineCurve.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_SplineCurve.def("Init", (void (IGESGeom_SplineCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &IGESGeom_SplineCurve::Init, "This method is used to set the fields of the class SplineCurve - aType : Spline Type 1 = Linear 2 = Quadratic 3 = Cubic 4 = Wilson-Fowler 5 = Modified Wilson-Fowler 6 = B Spline - aDegree : Degree of continuity w.r.t. arc length - nbDimensions : Number of dimensions 2 = Planar 3 = Non-planar - allBreakPoints : Array of break points - allXPolynomials : X coordinate polynomials of segments - allYPolynomials : Y coordinate polynomials of segments - allZPolynomials : Z coordinate polynomials of segments - allXValues : Values of 1st, 2nd, 3rd derivatives of X polynomials at the terminate point and values of X at terminate point - allYValues : Values of 1st, 2nd, 3rd derivatives of Y polynomials at the terminate point and values of Y at terminate point - allZvalues : Values of 1st, 2nd, 3rd derivatives of Z polynomials at the terminate point and values of Z at terminate point raises exception if allXPolynomials, allYPolynomials & allZPolynomials are not of same size OR allXValues, allYValues & allZValues are not of size 4", py::arg("aType"), py::arg("aDegree"), py::arg("nbDimensions"), py::arg("allBreakPoints"), py::arg("allXPolynomials"), py::arg("allYPolynomials"), py::arg("allZPolynomials"), py::arg("allXvalues"), py::arg("allYvalues"), py::arg("allZvalues"));
cls_IGESGeom_SplineCurve.def("SplineType", (Standard_Integer (IGESGeom_SplineCurve::*)() const) &IGESGeom_SplineCurve::SplineType, "returns the type of Spline curve");
cls_IGESGeom_SplineCurve.def("Degree", (Standard_Integer (IGESGeom_SplineCurve::*)() const) &IGESGeom_SplineCurve::Degree, "returns the degree of the curve");
cls_IGESGeom_SplineCurve.def("NbDimensions", (Standard_Integer (IGESGeom_SplineCurve::*)() const) &IGESGeom_SplineCurve::NbDimensions, "returns the number of dimensions 2 = Planar 3 = Non-planar");
cls_IGESGeom_SplineCurve.def("NbSegments", (Standard_Integer (IGESGeom_SplineCurve::*)() const) &IGESGeom_SplineCurve::NbSegments, "returns the number of segments");
cls_IGESGeom_SplineCurve.def("BreakPoint", (Standard_Real (IGESGeom_SplineCurve::*)(const Standard_Integer) const) &IGESGeom_SplineCurve::BreakPoint, "returns breakpoint of piecewise polynomial raises exception if Index <= 0 or Index > NbSegments() + 1", py::arg("Index"));
cls_IGESGeom_SplineCurve.def("XCoordPolynomial", [](IGESGeom_SplineCurve &self, const Standard_Integer Index, Standard_Real & AX, Standard_Real & BX, Standard_Real & CX, Standard_Real & DX){ self.XCoordPolynomial(Index, AX, BX, CX, DX); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(AX, BX, CX, DX); }, "returns X coordinate polynomial for segment referred to by Index raises exception if Index <= 0 or Index > NbSegments()", py::arg("Index"), py::arg("AX"), py::arg("BX"), py::arg("CX"), py::arg("DX"));
cls_IGESGeom_SplineCurve.def("YCoordPolynomial", [](IGESGeom_SplineCurve &self, const Standard_Integer Index, Standard_Real & AY, Standard_Real & BY, Standard_Real & CY, Standard_Real & DY){ self.YCoordPolynomial(Index, AY, BY, CY, DY); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(AY, BY, CY, DY); }, "returns Y coordinate polynomial for segment referred to by Index raises exception if Index <= 0 or Index > NbSegments()", py::arg("Index"), py::arg("AY"), py::arg("BY"), py::arg("CY"), py::arg("DY"));
cls_IGESGeom_SplineCurve.def("ZCoordPolynomial", [](IGESGeom_SplineCurve &self, const Standard_Integer Index, Standard_Real & AZ, Standard_Real & BZ, Standard_Real & CZ, Standard_Real & DZ){ self.ZCoordPolynomial(Index, AZ, BZ, CZ, DZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(AZ, BZ, CZ, DZ); }, "returns Z coordinate polynomial for segment referred to by Index raises exception if Index <= 0 or Index > NbSegments()", py::arg("Index"), py::arg("AZ"), py::arg("BZ"), py::arg("CZ"), py::arg("DZ"));
cls_IGESGeom_SplineCurve.def("XValues", [](IGESGeom_SplineCurve &self, Standard_Real & TPX0, Standard_Real & TPX1, Standard_Real & TPX2, Standard_Real & TPX3){ self.XValues(TPX0, TPX1, TPX2, TPX3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(TPX0, TPX1, TPX2, TPX3); }, "returns the value of X polynomial, the values of 1st, 2nd and 3rd derivatives of the X polynomial at the terminate point", py::arg("TPX0"), py::arg("TPX1"), py::arg("TPX2"), py::arg("TPX3"));
cls_IGESGeom_SplineCurve.def("YValues", [](IGESGeom_SplineCurve &self, Standard_Real & TPY0, Standard_Real & TPY1, Standard_Real & TPY2, Standard_Real & TPY3){ self.YValues(TPY0, TPY1, TPY2, TPY3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(TPY0, TPY1, TPY2, TPY3); }, "returns the value of Y polynomial, the values of 1st, 2nd and 3rd derivatives of the Y polynomial at the termminate point", py::arg("TPY0"), py::arg("TPY1"), py::arg("TPY2"), py::arg("TPY3"));
cls_IGESGeom_SplineCurve.def("ZValues", [](IGESGeom_SplineCurve &self, Standard_Real & TPZ0, Standard_Real & TPZ1, Standard_Real & TPZ2, Standard_Real & TPZ3){ self.ZValues(TPZ0, TPZ1, TPZ2, TPZ3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(TPZ0, TPZ1, TPZ2, TPZ3); }, "returns the value of Z polynomial, the values of 1st, 2nd and 3rd derivatives of the Z polynomial at the termminate point", py::arg("TPZ0"), py::arg("TPZ1"), py::arg("TPZ2"), py::arg("TPZ3"));
cls_IGESGeom_SplineCurve.def_static("get_type_name_", (const char * (*)()) &IGESGeom_SplineCurve::get_type_name, "None");
cls_IGESGeom_SplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_SplineCurve::get_type_descriptor, "None");
cls_IGESGeom_SplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_SplineCurve::*)() const) &IGESGeom_SplineCurve::DynamicType, "None");

// Enums

}