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
#include <TNaming_NamedShape.hxx>
#include <TNaming_DeltaOnModification.hxx>
#include <Standard_Type.hxx>
#include <TopTools_HArray1OfShape.hxx>

void bind_TNaming_DeltaOnModification(py::module &mod){

py::class_<TNaming_DeltaOnModification, opencascade::handle<TNaming_DeltaOnModification>, TDF_DeltaOnModification> cls_TNaming_DeltaOnModification(mod, "TNaming_DeltaOnModification", "This class provides default services for an AttributeDelta on a MODIFICATION action.");

// Constructors
cls_TNaming_DeltaOnModification.def(py::init<const opencascade::handle<TNaming_NamedShape> &>(), py::arg("NS"));

// Fields

// Methods
cls_TNaming_DeltaOnModification.def("Apply", (void (TNaming_DeltaOnModification::*)()) &TNaming_DeltaOnModification::Apply, "Applies the delta to the attribute.");
cls_TNaming_DeltaOnModification.def_static("get_type_name_", (const char * (*)()) &TNaming_DeltaOnModification::get_type_name, "None");
cls_TNaming_DeltaOnModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_DeltaOnModification::get_type_descriptor, "None");
cls_TNaming_DeltaOnModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_DeltaOnModification::*)() const) &TNaming_DeltaOnModification::DynamicType, "None");

// Enums

}