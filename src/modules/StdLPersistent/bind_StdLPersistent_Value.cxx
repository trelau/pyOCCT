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
#include <StdObjMgt_Attribute.hxx>
#include <StdLPersistent_Value.hxx>
#include <StdLPersistent_HString.hxx>
#include <TDF_TagSource.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Reference.hxx>
#include <TDataStd_Comment.hxx>
#include <TDataStd_UAttribute.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataStd_Name.hxx>
#include <TDataStd_AsciiString.hxx>

void bind_StdLPersistent_Value(py::module &mod){

py::class_<StdLPersistent_Value, std::unique_ptr<StdLPersistent_Value, Deleter<StdLPersistent_Value>>> cls_StdLPersistent_Value(mod, "StdLPersistent_Value", "None");

// Constructors

// Fields

// Methods

// Enums

}