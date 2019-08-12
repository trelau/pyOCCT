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
#include <IGESBasic_HArray2OfHArray1OfReal.hxx>
#include <IGESGeom_SplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_SplineSurface(py::module &mod){

py::class_<IGESGeom_SplineSurface, opencascade::handle<IGESGeom_SplineSurface>, IGESData_IGESEntity> cls_IGESGeom_SplineSurface(mod, "IGESGeom_SplineSurface", "defines IGESSplineSurface, Type <114> Form <0> in package IGESGeom A parametric spline surface is a grid of polynomial patches. Patch could be of the type Linear, Quadratic, Cubic, Wilson-Fowler, Modified Wilson-Fowler, B-Spline The M * N grid of patches is defined by the 'u' break points TU(1), TU(2), ..., TU(M+1) and the 'v' break points TV(1), TV(2), TV(3) ..., TV(N+1).");

// Constructors
cls_IGESGeom_SplineSurface.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_SplineSurface.def("Init", (void (IGESGeom_SplineSurface::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<IGESBasic_HArray2OfHArray1OfReal> &, const opencascade::handle<IGESBasic_HArray2OfHArray1OfReal> &, const opencascade::handle<IGESBasic_HArray2OfHArray1OfReal> &)) &IGESGeom_SplineSurface::Init, "This method is used to set the fields of the class SplineSurface - aBoundaryType : Type of Spline boundary 1 = Linear 2 = Quadratic 3 = Cubic 4 = Wilson-Fowler 5 = Modified Wilson-Fowler 6 = B-spline - aPatchType : Type of patch contained in the grid 1 = Cartesian Product 0 = Unspecified - allUBreakpoints : u values of grid lines - allVBreakpoints : v values of grid lines - allXCoeffs : X coefficients of M x N patches - allYCoeffs : Y coefficients of M x N patches - allZCoeffs : Z coefficients of M x N patches raises exception if allXCoeffs, allYCoeffs & allZCoeffs are not of the same size. or if the size of each element of the double array is not 16", py::arg("aBoundaryType"), py::arg("aPatchType"), py::arg("allUBreakpoints"), py::arg("allVBreakpoints"), py::arg("allXCoeffs"), py::arg("allYCoeffs"), py::arg("allZCoeffs"));
cls_IGESGeom_SplineSurface.def("NbUSegments", (Standard_Integer (IGESGeom_SplineSurface::*)() const) &IGESGeom_SplineSurface::NbUSegments, "returns the number of U segments");
cls_IGESGeom_SplineSurface.def("NbVSegments", (Standard_Integer (IGESGeom_SplineSurface::*)() const) &IGESGeom_SplineSurface::NbVSegments, "returns the number of V segments");
cls_IGESGeom_SplineSurface.def("BoundaryType", (Standard_Integer (IGESGeom_SplineSurface::*)() const) &IGESGeom_SplineSurface::BoundaryType, "returns boundary type");
cls_IGESGeom_SplineSurface.def("PatchType", (Standard_Integer (IGESGeom_SplineSurface::*)() const) &IGESGeom_SplineSurface::PatchType, "returns patch type");
cls_IGESGeom_SplineSurface.def("UBreakPoint", (Standard_Real (IGESGeom_SplineSurface::*)(const Standard_Integer) const) &IGESGeom_SplineSurface::UBreakPoint, "returns U break point of the grid line referred to by anIndex raises exception if anIndex <= 0 or anIndex > NbUSegments() + 1", py::arg("anIndex"));
cls_IGESGeom_SplineSurface.def("VBreakPoint", (Standard_Real (IGESGeom_SplineSurface::*)(const Standard_Integer) const) &IGESGeom_SplineSurface::VBreakPoint, "returns V break point of the grid line referred to by anIndex raises exception if anIndex <= 0 or anIndex > NbVSegments() + 1", py::arg("anIndex"));
cls_IGESGeom_SplineSurface.def("XPolynomial", (opencascade::handle<TColStd_HArray1OfReal> (IGESGeom_SplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_SplineSurface::XPolynomial, "returns X polynomial of patch referred to by anIndex1, anIndex2 raises exception if anIndex1 <= 0 or anIndex1 > NbUSegments() or anIndex2 <= 0 or anIndex2 > NbVSegments()", py::arg("anIndex1"), py::arg("anIndex2"));
cls_IGESGeom_SplineSurface.def("YPolynomial", (opencascade::handle<TColStd_HArray1OfReal> (IGESGeom_SplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_SplineSurface::YPolynomial, "returns Y polynomial of patch referred to by anIndex1, anIndex2 raises exception if anIndex1 <= 0 or anIndex1 > NbUSegments() or anIndex2 <= 0 or anIndex2 > NbVSegments()", py::arg("anIndex1"), py::arg("anIndex2"));
cls_IGESGeom_SplineSurface.def("ZPolynomial", (opencascade::handle<TColStd_HArray1OfReal> (IGESGeom_SplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_SplineSurface::ZPolynomial, "returns Z polynomial of patch referred to by anIndex1, anIndex2 raises exception if anIndex1 <= 0 or anIndex1 > NbUSegments() or anIndex2 <= 0 or anIndex2 > NbVSegments()", py::arg("anIndex1"), py::arg("anIndex2"));
cls_IGESGeom_SplineSurface.def("Polynomials", (void (IGESGeom_SplineSurface::*)(opencascade::handle<IGESBasic_HArray2OfHArray1OfReal> &, opencascade::handle<IGESBasic_HArray2OfHArray1OfReal> &, opencascade::handle<IGESBasic_HArray2OfHArray1OfReal> &) const) &IGESGeom_SplineSurface::Polynomials, "returns in one all the polynomial values 'in bulk' usefull for massive treatements", py::arg("XCoef"), py::arg("YCoef"), py::arg("ZCoef"));
cls_IGESGeom_SplineSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_SplineSurface::get_type_name, "None");
cls_IGESGeom_SplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_SplineSurface::get_type_descriptor, "None");
cls_IGESGeom_SplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_SplineSurface::*)() const) &IGESGeom_SplineSurface::DynamicType, "None");

// Enums

}