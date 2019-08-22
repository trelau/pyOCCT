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
#include <IntTools_SurfaceRangeLocalizeData.hxx>
#include <IntTools_SurfaceRangeSample.hxx>
#include <Bnd_Box.hxx>
#include <IntTools_ListOfSurfaceRangeSample.hxx>
#include <gp_Pnt.hxx>
#include <IntTools_MapOfSurfaceSample.hxx>
#include <IntTools_DataMapOfSurfaceSampleBox.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray2OfPnt.hxx>

void bind_IntTools_SurfaceRangeLocalizeData(py::module &mod){

py::class_<IntTools_SurfaceRangeLocalizeData> cls_IntTools_SurfaceRangeLocalizeData(mod, "IntTools_SurfaceRangeLocalizeData", "None");

// Constructors
cls_IntTools_SurfaceRangeLocalizeData.def(py::init<>());
cls_IntTools_SurfaceRangeLocalizeData.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("theNbSampleU"), py::arg("theNbSampleV"), py::arg("theMinRangeU"), py::arg("theMinRangeV"));
cls_IntTools_SurfaceRangeLocalizeData.def(py::init<const IntTools_SurfaceRangeLocalizeData &>(), py::arg("Other"));

// Fields

// Methods
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator new_", (void * (*)(size_t)) &IntTools_SurfaceRangeLocalizeData::operator new, "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator delete_", (void (*)(void *)) &IntTools_SurfaceRangeLocalizeData::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_SurfaceRangeLocalizeData::operator new[], "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator delete[]_", (void (*)(void *)) &IntTools_SurfaceRangeLocalizeData::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_SurfaceRangeLocalizeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_SurfaceRangeLocalizeData::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_SurfaceRangeLocalizeData.def("Assign", (IntTools_SurfaceRangeLocalizeData & (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeLocalizeData &)) &IntTools_SurfaceRangeLocalizeData::Assign, "None", py::arg("Other"));
// cls_IntTools_SurfaceRangeLocalizeData.def("operator=", (IntTools_SurfaceRangeLocalizeData & (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeLocalizeData &)) &IntTools_SurfaceRangeLocalizeData::operator=, "None", py::arg("Other"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetNbSampleU", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNbSampleU, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("GetNbSampleV", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNbSampleV, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("GetMinRangeU", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetMinRangeU, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("GetMinRangeV", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetMinRangeV, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("AddOutRange", (void (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeLocalizeData::AddOutRange, "None", py::arg("theRange"));
cls_IntTools_SurfaceRangeLocalizeData.def("AddBox", (void (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &, const Bnd_Box &)) &IntTools_SurfaceRangeLocalizeData::AddBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_SurfaceRangeLocalizeData.def("FindBox", (Standard_Boolean (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &, Bnd_Box &) const) &IntTools_SurfaceRangeLocalizeData::FindBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_SurfaceRangeLocalizeData.def("IsRangeOut", (Standard_Boolean (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &) const) &IntTools_SurfaceRangeLocalizeData::IsRangeOut, "None", py::arg("theRange"));
cls_IntTools_SurfaceRangeLocalizeData.def("ListRangeOut", (void (IntTools_SurfaceRangeLocalizeData::*)(IntTools_ListOfSurfaceRangeSample &) const) &IntTools_SurfaceRangeLocalizeData::ListRangeOut, "None", py::arg("theList"));
cls_IntTools_SurfaceRangeLocalizeData.def("RemoveRangeOutAll", (void (IntTools_SurfaceRangeLocalizeData::*)()) &IntTools_SurfaceRangeLocalizeData::RemoveRangeOutAll, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("SetGridDeflection", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetGridDeflection, "Set the grid deflection.", py::arg("theDeflection"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetGridDeflection", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetGridDeflection, "Query the grid deflection.");
cls_IntTools_SurfaceRangeLocalizeData.def("SetRangeUGrid", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer)) &IntTools_SurfaceRangeLocalizeData::SetRangeUGrid, "Set the range U of the grid of points.", py::arg("theNbUGrid"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetRangeUGrid", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetRangeUGrid, "Query the range U of the grid of points.");
cls_IntTools_SurfaceRangeLocalizeData.def("SetUParam", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetUParam, "Set the U parameter of the grid points at that index.", py::arg("theIndex"), py::arg("theUParam"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetUParam", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetUParam, "Query the U parameter of the grid points at that index.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("SetRangeVGrid", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer)) &IntTools_SurfaceRangeLocalizeData::SetRangeVGrid, "Set the range V of the grid of points.", py::arg("theNbVGrid"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetRangeVGrid", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetRangeVGrid, "Query the range V of the grid of points.");
cls_IntTools_SurfaceRangeLocalizeData.def("SetVParam", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetVParam, "Set the V parameter of the grid points at that index.", py::arg("theIndex"), py::arg("theVParam"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetVParam", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetVParam, "Query the V parameter of the grid points at that index.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("SetGridPoint", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt &)) &IntTools_SurfaceRangeLocalizeData::SetGridPoint, "Set the grid point.", py::arg("theUIndex"), py::arg("theVIndex"), py::arg("thePoint"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetGridPoint", (const gp_Pnt & (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetGridPoint, "Set the grid point.", py::arg("theUIndex"), py::arg("theVIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("SetFrame", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetFrame, "Sets the frame area. Used to work with grid points.", py::arg("theUMin"), py::arg("theUMax"), py::arg("theVMin"), py::arg("theVMax"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetNBUPointsInFrame", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNBUPointsInFrame, "Returns the number of grid points on U direction in frame.");
cls_IntTools_SurfaceRangeLocalizeData.def("GetNBVPointsInFrame", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNBVPointsInFrame, "Returns the number of grid points on V direction in frame.");
cls_IntTools_SurfaceRangeLocalizeData.def("GetPointInFrame", (const gp_Pnt & (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetPointInFrame, "Returns the grid point in frame.", py::arg("theUIndex"), py::arg("theVIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetUParamInFrame", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetUParamInFrame, "Query the U parameter of the grid points at that index in frame.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetVParamInFrame", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetVParamInFrame, "Query the V parameter of the grid points at that index in frame.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("ClearGrid", (void (IntTools_SurfaceRangeLocalizeData::*)()) &IntTools_SurfaceRangeLocalizeData::ClearGrid, "Clears the grid of points.");

// Enums

}