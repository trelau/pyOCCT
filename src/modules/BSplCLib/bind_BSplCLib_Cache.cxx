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
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <BSplCLib_Cache.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_BSplCLib_Cache(py::module &mod){

py::class_<BSplCLib_Cache, opencascade::handle<BSplCLib_Cache>, Standard_Transient> cls_BSplCLib_Cache(mod, "BSplCLib_Cache", "A cache class for Bezier and B-spline curves.");

// Constructors
cls_BSplCLib_Cache.def(py::init<>());
cls_BSplCLib_Cache.def(py::init<const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array1OfPnt2d &>(), py::arg("theDegree"), py::arg("thePeriodic"), py::arg("theFlatKnots"), py::arg("thePoles2d"));
cls_BSplCLib_Cache.def(py::init<const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array1OfPnt2d &, const TColStd_Array1OfReal *>(), py::arg("theDegree"), py::arg("thePeriodic"), py::arg("theFlatKnots"), py::arg("thePoles2d"), py::arg("theWeights"));
cls_BSplCLib_Cache.def(py::init<const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array1OfPnt &>(), py::arg("theDegree"), py::arg("thePeriodic"), py::arg("theFlatKnots"), py::arg("thePoles"));
cls_BSplCLib_Cache.def(py::init<const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal *>(), py::arg("theDegree"), py::arg("thePeriodic"), py::arg("theFlatKnots"), py::arg("thePoles"), py::arg("theWeights"));

// Fields

// Methods
cls_BSplCLib_Cache.def("IsCacheValid", (Standard_Boolean (BSplCLib_Cache::*)(Standard_Real) const) &BSplCLib_Cache::IsCacheValid, "Verifies validity of the cache using flat parameter of the point", py::arg("theParameter"));
cls_BSplCLib_Cache.def("BuildCache", [](BSplCLib_Cache &self, const Standard_Real & a0, const Standard_Integer & a1, const Standard_Boolean & a2, const TColStd_Array1OfReal & a3, const TColgp_Array1OfPnt2d & a4) -> void { return self.BuildCache(a0, a1, a2, a3, a4); });
cls_BSplCLib_Cache.def("BuildCache", (void (BSplCLib_Cache::*)(const Standard_Real &, const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array1OfPnt2d &, const TColStd_Array1OfReal *)) &BSplCLib_Cache::BuildCache, "Recomputes the cache data for 2D curves. Does not verify validity of the cache", py::arg("theParameter"), py::arg("theDegree"), py::arg("thePeriodic"), py::arg("theFlatKnots"), py::arg("thePoles2d"), py::arg("theWeights"));
cls_BSplCLib_Cache.def("BuildCache", [](BSplCLib_Cache &self, const Standard_Real & a0, const Standard_Integer & a1, const Standard_Boolean & a2, const TColStd_Array1OfReal & a3, const TColgp_Array1OfPnt & a4) -> void { return self.BuildCache(a0, a1, a2, a3, a4); });
cls_BSplCLib_Cache.def("BuildCache", (void (BSplCLib_Cache::*)(const Standard_Real &, const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal *)) &BSplCLib_Cache::BuildCache, "Recomputes the cache data for 3D curves. Does not verify validity of the cache", py::arg("theParameter"), py::arg("theDegree"), py::arg("thePeriodic"), py::arg("theFlatKnots"), py::arg("thePoles"), py::arg("theWeights"));
cls_BSplCLib_Cache.def("D0", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt2d &) const) &BSplCLib_Cache::D0, "Calculates the point on the curve in the specified parameter", py::arg("theParameter"), py::arg("thePoint"));
cls_BSplCLib_Cache.def("D0", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt &) const) &BSplCLib_Cache::D0, "None", py::arg("theParameter"), py::arg("thePoint"));
cls_BSplCLib_Cache.def("D1", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt2d &, gp_Vec2d &) const) &BSplCLib_Cache::D1, "Calculates the point on the curve and its first derivative in the specified parameter", py::arg("theParameter"), py::arg("thePoint"), py::arg("theTangent"));
cls_BSplCLib_Cache.def("D1", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt &, gp_Vec &) const) &BSplCLib_Cache::D1, "None", py::arg("theParameter"), py::arg("thePoint"), py::arg("theTangent"));
cls_BSplCLib_Cache.def("D2", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &BSplCLib_Cache::D2, "Calculates the point on the curve and two derivatives in the specified parameter", py::arg("theParameter"), py::arg("thePoint"), py::arg("theTangent"), py::arg("theCurvature"));
cls_BSplCLib_Cache.def("D2", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt &, gp_Vec &, gp_Vec &) const) &BSplCLib_Cache::D2, "None", py::arg("theParameter"), py::arg("thePoint"), py::arg("theTangent"), py::arg("theCurvature"));
cls_BSplCLib_Cache.def("D3", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &BSplCLib_Cache::D3, "Calculates the point on the curve and three derivatives in the specified parameter", py::arg("theParameter"), py::arg("thePoint"), py::arg("theTangent"), py::arg("theCurvature"), py::arg("theTorsion"));
cls_BSplCLib_Cache.def("D3", (void (BSplCLib_Cache::*)(const Standard_Real &, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BSplCLib_Cache::D3, "None", py::arg("theParameter"), py::arg("thePoint"), py::arg("theTangent"), py::arg("theCurvature"), py::arg("theTorsion"));
cls_BSplCLib_Cache.def_static("get_type_name_", (const char * (*)()) &BSplCLib_Cache::get_type_name, "None");
cls_BSplCLib_Cache.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BSplCLib_Cache::get_type_descriptor, "None");
cls_BSplCLib_Cache.def("DynamicType", (const opencascade::handle<Standard_Type> & (BSplCLib_Cache::*)() const) &BSplCLib_Cache::DynamicType, "None");

// Enums

}