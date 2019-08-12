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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <ShapeUpgrade_SplitSurface.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitSurface(py::module &mod){

py::class_<ShapeUpgrade_SplitSurface, opencascade::handle<ShapeUpgrade_SplitSurface>, Standard_Transient> cls_ShapeUpgrade_SplitSurface(mod, "ShapeUpgrade_SplitSurface", "Splits a Surface with a criterion.");

// Constructors
cls_ShapeUpgrade_SplitSurface.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_SplitSurface.def("Init", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<Geom_Surface> &)) &ShapeUpgrade_SplitSurface::Init, "Initializes with single supporting surface.", py::arg("S"));
cls_ShapeUpgrade_SplitSurface.def("Init", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ShapeUpgrade_SplitSurface::Init, "Initializes with single supporting surface with bounding parameters.", py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"));
cls_ShapeUpgrade_SplitSurface.def("SetUSplitValues", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<TColStd_HSequenceOfReal> &)) &ShapeUpgrade_SplitSurface::SetUSplitValues, "Sets U parameters where splitting has to be done", py::arg("UValues"));
cls_ShapeUpgrade_SplitSurface.def("SetVSplitValues", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<TColStd_HSequenceOfReal> &)) &ShapeUpgrade_SplitSurface::SetVSplitValues, "Sets V parameters where splitting has to be done", py::arg("VValues"));
cls_ShapeUpgrade_SplitSurface.def("Build", (void (ShapeUpgrade_SplitSurface::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurface::Build, "Performs splitting of the supporting surface. If resulting surface is B-Spline and Segment is True, the result is composed with segments of the surface bounded by the U and V SplitValues (method Geom_BSplineSurface::Segment is used). If Segment is False, the result is composed with Geom_RectangularTrimmedSurface all based on the same complete surface. Fields myNbResultingRow and myNbResultingCol must be set to specify the size of resulting grid of surfaces.", py::arg("Segment"));
cls_ShapeUpgrade_SplitSurface.def("Compute", [](ShapeUpgrade_SplitSurface &self) -> void { return self.Compute(); });
cls_ShapeUpgrade_SplitSurface.def("Compute", (void (ShapeUpgrade_SplitSurface::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurface::Compute, "Calculates points for correction/splitting of the surface.", py::arg("Segment"));
cls_ShapeUpgrade_SplitSurface.def("Perform", [](ShapeUpgrade_SplitSurface &self) -> void { return self.Perform(); });
cls_ShapeUpgrade_SplitSurface.def("Perform", (void (ShapeUpgrade_SplitSurface::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurface::Perform, "Performs correction/splitting of the surface. First defines splitting values by method Compute(), then calls method Build().", py::arg("Segment"));
cls_ShapeUpgrade_SplitSurface.def("USplitValues", (const opencascade::handle<TColStd_HSequenceOfReal> & (ShapeUpgrade_SplitSurface::*)() const) &ShapeUpgrade_SplitSurface::USplitValues, "returns all the U splitting values including the First and Last parameters of the input surface");
cls_ShapeUpgrade_SplitSurface.def("VSplitValues", (const opencascade::handle<TColStd_HSequenceOfReal> & (ShapeUpgrade_SplitSurface::*)() const) &ShapeUpgrade_SplitSurface::VSplitValues, "returns all the splitting V values including the First and Last parameters of the input surface");
cls_ShapeUpgrade_SplitSurface.def("Status", (Standard_Boolean (ShapeUpgrade_SplitSurface::*)(const ShapeExtend_Status) const) &ShapeUpgrade_SplitSurface::Status, "Returns the status OK - no splitting is needed DONE1 - splitting required and gives more than one patch DONE2 - splitting is required, but gives only single patch (initial) DONE3 - geometric form of the surface or parametrisation is modified", py::arg("status"));
cls_ShapeUpgrade_SplitSurface.def("ResSurfaces", (const opencascade::handle<ShapeExtend_CompositeSurface> & (ShapeUpgrade_SplitSurface::*)() const) &ShapeUpgrade_SplitSurface::ResSurfaces, "Returns obtained surfaces after splitting as CompositeSurface");
cls_ShapeUpgrade_SplitSurface.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurface::get_type_name, "None");
cls_ShapeUpgrade_SplitSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurface::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurface::*)() const) &ShapeUpgrade_SplitSurface::DynamicType, "None");

// Enums

}