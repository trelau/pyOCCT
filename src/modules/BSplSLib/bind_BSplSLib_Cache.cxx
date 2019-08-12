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
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <BSplSLib_Cache.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_BSplSLib_Cache(py::module &mod){

py::class_<BSplSLib_Cache, opencascade::handle<BSplSLib_Cache>, Standard_Transient> cls_BSplSLib_Cache(mod, "BSplSLib_Cache", "A cache class for Bezier and B-spline surfaces.");

// Constructors
cls_BSplSLib_Cache.def(py::init<>());
cls_BSplSLib_Cache.def(py::init<const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array2OfPnt &>(), py::arg("theDegreeU"), py::arg("thePeriodicU"), py::arg("theFlatKnotsU"), py::arg("theDegreeV"), py::arg("thePeriodicV"), py::arg("theFlatKnotsV"), py::arg("thePoles"));
cls_BSplSLib_Cache.def(py::init<const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array2OfPnt &, const TColStd_Array2OfReal *>(), py::arg("theDegreeU"), py::arg("thePeriodicU"), py::arg("theFlatKnotsU"), py::arg("theDegreeV"), py::arg("thePeriodicV"), py::arg("theFlatKnotsV"), py::arg("thePoles"), py::arg("theWeights"));

// Fields

// Methods
cls_BSplSLib_Cache.def("IsCacheValid", (Standard_Boolean (BSplSLib_Cache::*)(Standard_Real, Standard_Real) const) &BSplSLib_Cache::IsCacheValid, "Verifies validity of the cache using parameters of the point", py::arg("theParameterU"), py::arg("theParameterV"));
cls_BSplSLib_Cache.def("BuildCache", [](BSplSLib_Cache &self, const Standard_Real & a0, const Standard_Real & a1, const Standard_Integer & a2, const Standard_Boolean & a3, const TColStd_Array1OfReal & a4, const Standard_Integer & a5, const Standard_Boolean & a6, const TColStd_Array1OfReal & a7, const TColgp_Array2OfPnt & a8) -> void { return self.BuildCache(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_BSplSLib_Cache.def("BuildCache", (void (BSplSLib_Cache::*)(const Standard_Real &, const Standard_Real &, const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const Standard_Integer &, const Standard_Boolean &, const TColStd_Array1OfReal &, const TColgp_Array2OfPnt &, const TColStd_Array2OfReal *)) &BSplSLib_Cache::BuildCache, "Recomputes the cache data. Does not verify validity of the cache", py::arg("theParameterU"), py::arg("theParameterV"), py::arg("theDegreeU"), py::arg("thePeriodicU"), py::arg("theFlatKnotsU"), py::arg("theDegreeV"), py::arg("thePeriodicV"), py::arg("theFlatKnotsV"), py::arg("thePoles"), py::arg("theWeights"));
cls_BSplSLib_Cache.def("D0", (void (BSplSLib_Cache::*)(const Standard_Real &, const Standard_Real &, gp_Pnt &) const) &BSplSLib_Cache::D0, "Calculates the point on the surface for specified parameters", py::arg("theU"), py::arg("theV"), py::arg("thePoint"));
cls_BSplSLib_Cache.def("D1", (void (BSplSLib_Cache::*)(const Standard_Real &, const Standard_Real &, gp_Pnt &, gp_Vec &, gp_Vec &) const) &BSplSLib_Cache::D1, "Calculates the point on the surface and its first derivative", py::arg("theU"), py::arg("theV"), py::arg("thePoint"), py::arg("theTangentU"), py::arg("theTangentV"));
cls_BSplSLib_Cache.def("D2", (void (BSplSLib_Cache::*)(const Standard_Real &, const Standard_Real &, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BSplSLib_Cache::D2, "Calculates the point on the surface and derivatives till second order", py::arg("theU"), py::arg("theV"), py::arg("thePoint"), py::arg("theTangentU"), py::arg("theTangentV"), py::arg("theCurvatureU"), py::arg("theCurvatureV"), py::arg("theCurvatureUV"));
cls_BSplSLib_Cache.def_static("get_type_name_", (const char * (*)()) &BSplSLib_Cache::get_type_name, "None");
cls_BSplSLib_Cache.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BSplSLib_Cache::get_type_descriptor, "None");
cls_BSplSLib_Cache.def("DynamicType", (const opencascade::handle<Standard_Type> & (BSplSLib_Cache::*)() const) &BSplSLib_Cache::DynamicType, "None");

// Enums

}