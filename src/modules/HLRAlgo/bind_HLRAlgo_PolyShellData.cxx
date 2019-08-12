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
#include <HLRAlgo_PolyData.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <HLRAlgo_ListOfBPoint.hxx>
#include <HLRAlgo_PolyShellData.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfTransient.hxx>

void bind_HLRAlgo_PolyShellData(py::module &mod){

py::class_<HLRAlgo_PolyShellData, opencascade::handle<HLRAlgo_PolyShellData>, Standard_Transient> cls_HLRAlgo_PolyShellData(mod, "HLRAlgo_PolyShellData", "All the PolyData of a Shell");

// Constructors
cls_HLRAlgo_PolyShellData.def(py::init<const Standard_Integer>(), py::arg("nbFace"));

// Fields

// Methods
cls_HLRAlgo_PolyShellData.def("UpdateGlobalMinMax", (void (HLRAlgo_PolyShellData::*)(HLRAlgo_PolyData::Box &)) &HLRAlgo_PolyShellData::UpdateGlobalMinMax, "None", py::arg("theBox"));
cls_HLRAlgo_PolyShellData.def("UpdateHiding", (void (HLRAlgo_PolyShellData::*)(const Standard_Integer)) &HLRAlgo_PolyShellData::UpdateHiding, "None", py::arg("nbHiding"));
cls_HLRAlgo_PolyShellData.def("Hiding", (Standard_Boolean (HLRAlgo_PolyShellData::*)() const) &HLRAlgo_PolyShellData::Hiding, "None");
cls_HLRAlgo_PolyShellData.def("PolyData", (TColStd_Array1OfTransient & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::PolyData, "None");
cls_HLRAlgo_PolyShellData.def("HidingPolyData", (TColStd_Array1OfTransient & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::HidingPolyData, "None");
cls_HLRAlgo_PolyShellData.def("Edges", (HLRAlgo_ListOfBPoint & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::Edges, "None");
cls_HLRAlgo_PolyShellData.def("Indices", (HLRAlgo_PolyShellData::ShellIndices & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::Indices, "None");
cls_HLRAlgo_PolyShellData.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyShellData::get_type_name, "None");
cls_HLRAlgo_PolyShellData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyShellData::get_type_descriptor, "None");
cls_HLRAlgo_PolyShellData.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyShellData::*)() const) &HLRAlgo_PolyShellData::DynamicType, "None");

// Enums

}