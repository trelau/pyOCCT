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
#include <StdLPersistent_Collection.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <Standard_TypeDef.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <TDataStd_BooleanArray.hxx>
#include <TDataStd_IntegerArray.hxx>
#include <TDataStd_RealArray.hxx>
#include <TDataStd_ByteArray.hxx>
#include <TDataStd_ExtStringArray.hxx>
#include <TDataStd_ReferenceArray.hxx>
#include <TDataStd_IntegerList.hxx>
#include <TDataStd_RealList.hxx>
#include <TDataStd_BooleanList.hxx>
#include <TDataStd_ExtStringList.hxx>
#include <TDataStd_ReferenceList.hxx>
#include <TDataStd_IntPackedMap.hxx>

void bind_StdLPersistent_Collection(py::module &mod){

py::class_<StdLPersistent_Collection, std::unique_ptr<StdLPersistent_Collection>> cls_StdLPersistent_Collection(mod, "StdLPersistent_Collection", "None");

// Constructors

// Fields

// Methods

// Enums

}