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
#include <Standard_Handle.hxx>
#include <TObj_Model.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TObj_Assistant.hxx>

void bind_TObj_Assistant(py::module &mod){

py::class_<TObj_Assistant, std::unique_ptr<TObj_Assistant, Deleter<TObj_Assistant>>> cls_TObj_Assistant(mod, "TObj_Assistant", "This class provides interface to the static data to be used during save or load models.");

// Constructors

// Fields

// Methods
cls_TObj_Assistant.def_static("FindModel_", (opencascade::handle<TObj_Model> (*)(const Standard_CString)) &TObj_Assistant::FindModel, "Finds model by name", py::arg("theName"));
cls_TObj_Assistant.def_static("BindModel_", (void (*)(const opencascade::handle<TObj_Model>)) &TObj_Assistant::BindModel, "Binds model to the map", py::arg("theModel"));
cls_TObj_Assistant.def_static("ClearModelMap_", (void (*)()) &TObj_Assistant::ClearModelMap, "Clears all records from the model map");
cls_TObj_Assistant.def_static("FindType_", (opencascade::handle<Standard_Type> (*)(const Standard_Integer)) &TObj_Assistant::FindType, "Finds Standard_Type by index; returns NULL handle if not found", py::arg("theTypeIndex"));
cls_TObj_Assistant.def_static("FindTypeIndex_", (Standard_Integer (*)(const opencascade::handle<Standard_Type> &)) &TObj_Assistant::FindTypeIndex, "Rinds index by Standard_Type; returns 0 if not found", py::arg("theType"));
cls_TObj_Assistant.def_static("BindType_", (Standard_Integer (*)(const opencascade::handle<Standard_Type> &)) &TObj_Assistant::BindType, "Binds Standard_Type to the map; returns index of bound type", py::arg("theType"));
cls_TObj_Assistant.def_static("ClearTypeMap_", (void (*)()) &TObj_Assistant::ClearTypeMap, "Clears map of types");
cls_TObj_Assistant.def_static("SetCurrentModel_", (void (*)(const opencascade::handle<TObj_Model> &)) &TObj_Assistant::SetCurrentModel, "Sets current model", py::arg("theModel"));
cls_TObj_Assistant.def_static("GetCurrentModel_", (opencascade::handle<TObj_Model> (*)()) &TObj_Assistant::GetCurrentModel, "Returns current model");
cls_TObj_Assistant.def_static("UnSetCurrentModel_", (void (*)()) &TObj_Assistant::UnSetCurrentModel, "Unsets current model");
cls_TObj_Assistant.def_static("GetAppVersion_", (Standard_Integer (*)()) &TObj_Assistant::GetAppVersion, "Returns the version of application which wrote the currently read document. Returns 0 if it has not been set yet for the current document.");

// Enums

}