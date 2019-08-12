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
#include <TColgp_Array1OfPnt.hxx>
#include <gp_Pln.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <gp_Trsf.hxx>
#include <ShapeAnalysis_Geom.hxx>

void bind_ShapeAnalysis_Geom(py::module &mod){

py::class_<ShapeAnalysis_Geom, std::unique_ptr<ShapeAnalysis_Geom, Deleter<ShapeAnalysis_Geom>>> cls_ShapeAnalysis_Geom(mod, "ShapeAnalysis_Geom", "Analyzing tool aimed to work on primitive geometrical objects");

// Constructors

// Fields

// Methods
// cls_ShapeAnalysis_Geom.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_Geom::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_Geom.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_Geom::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Geom.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_Geom::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_Geom.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_Geom::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Geom.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_Geom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_Geom.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_Geom::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_Geom.def_static("NearestPlane_", [](const TColgp_Array1OfPnt & Pnts, gp_Pln & aPln, Standard_Real & Dmax){ Standard_Boolean rv = ShapeAnalysis_Geom::NearestPlane(Pnts, aPln, Dmax); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Dmax); }, "Builds a plane out of a set of points in array Returns in <dmax> the maximal distance between the produced plane and given points", py::arg("Pnts"), py::arg("aPln"), py::arg("Dmax"));
cls_ShapeAnalysis_Geom.def_static("PositionTrsf_", (Standard_Boolean (*)(const opencascade::handle<TColStd_HArray2OfReal> &, gp_Trsf &, const Standard_Real, const Standard_Real)) &ShapeAnalysis_Geom::PositionTrsf, "Builds transfromation object out of matrix. Matrix must be 3 x 4. Unit is used as multiplier.", py::arg("coefs"), py::arg("trsf"), py::arg("unit"), py::arg("prec"));

// Enums

}