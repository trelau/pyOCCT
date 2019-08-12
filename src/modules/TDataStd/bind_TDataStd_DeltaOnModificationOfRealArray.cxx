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
#include <TDF_DeltaOnModification.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_RealArray.hxx>
#include <TDataStd_DeltaOnModificationOfRealArray.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>

void bind_TDataStd_DeltaOnModificationOfRealArray(py::module &mod){

py::class_<TDataStd_DeltaOnModificationOfRealArray, opencascade::handle<TDataStd_DeltaOnModificationOfRealArray>, TDF_DeltaOnModification> cls_TDataStd_DeltaOnModificationOfRealArray(mod, "TDataStd_DeltaOnModificationOfRealArray", "This class provides default services for an AttributeDelta on a MODIFICATION action");

// Constructors
cls_TDataStd_DeltaOnModificationOfRealArray.def(py::init<const opencascade::handle<TDataStd_RealArray> &>(), py::arg("Arr"));

// Fields

// Methods
cls_TDataStd_DeltaOnModificationOfRealArray.def("Apply", (void (TDataStd_DeltaOnModificationOfRealArray::*)()) &TDataStd_DeltaOnModificationOfRealArray::Apply, "Applies the delta to the attribute.");
cls_TDataStd_DeltaOnModificationOfRealArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_DeltaOnModificationOfRealArray::get_type_name, "None");
cls_TDataStd_DeltaOnModificationOfRealArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_DeltaOnModificationOfRealArray::get_type_descriptor, "None");
cls_TDataStd_DeltaOnModificationOfRealArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_DeltaOnModificationOfRealArray::*)() const) &TDataStd_DeltaOnModificationOfRealArray::DynamicType, "None");

// Enums

}