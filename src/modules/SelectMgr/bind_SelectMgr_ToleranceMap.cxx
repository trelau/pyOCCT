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
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <NCollection_DataMap.hxx>
#include <SelectMgr_ToleranceMap.hxx>

void bind_SelectMgr_ToleranceMap(py::module &mod){

py::class_<SelectMgr_ToleranceMap> cls_SelectMgr_ToleranceMap(mod, "SelectMgr_ToleranceMap", "An internal class for calculation of current largest tolerance value which will be applied for creation of selecting frustum by default. Each time the selection set is deactivated, maximum tolerance value will be recalculated. If a user enables custom precision using StdSelect_ViewerSelector3d::SetPixelTolerance, it will be applied to all sensitive entities without any checks.");

// Constructors
cls_SelectMgr_ToleranceMap.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_ToleranceMap.def("Add", (void (SelectMgr_ToleranceMap::*)(const Standard_Integer &)) &SelectMgr_ToleranceMap::Add, "Adds the value given to map, checks if the current tolerance value should be replaced by theTolerance", py::arg("theTolerance"));
cls_SelectMgr_ToleranceMap.def("Decrement", (void (SelectMgr_ToleranceMap::*)(const Standard_Integer &)) &SelectMgr_ToleranceMap::Decrement, "Decrements a counter of the tolerance given, checks if the current tolerance value should be recalculated", py::arg("theTolerance"));
cls_SelectMgr_ToleranceMap.def("Tolerance", (Standard_Integer (SelectMgr_ToleranceMap::*)() const) &SelectMgr_ToleranceMap::Tolerance, "Returns a current tolerance that must be applied");
cls_SelectMgr_ToleranceMap.def("SetCustomTolerance", (void (SelectMgr_ToleranceMap::*)(const Standard_Integer)) &SelectMgr_ToleranceMap::SetCustomTolerance, "Sets tolerance to the given one and disables adaptive checks", py::arg("theTolerance"));
cls_SelectMgr_ToleranceMap.def("ResetDefaults", (void (SelectMgr_ToleranceMap::*)()) &SelectMgr_ToleranceMap::ResetDefaults, "Unsets a custom tolerance and enables adaptive checks");
cls_SelectMgr_ToleranceMap.def("CustomTolerance", (Standard_Integer (SelectMgr_ToleranceMap::*)() const) &SelectMgr_ToleranceMap::CustomTolerance, "Returns the value of custom tolerance regardless of it validity");
cls_SelectMgr_ToleranceMap.def("IsCustomTolSet", (Standard_Boolean (SelectMgr_ToleranceMap::*)() const) &SelectMgr_ToleranceMap::IsCustomTolSet, "Returns true if custom tolerance value is greater than zero");

// Enums

}