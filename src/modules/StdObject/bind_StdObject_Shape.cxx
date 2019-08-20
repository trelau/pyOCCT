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
#include <ShapePersistent_TopoDS.hxx>
#include <TopoDS_Shape.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_Handle.hxx>
#include <StdPersistent_TopoDS.hxx>
#include <StdObject_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <StdObject_Shape.hxx>

void bind_StdObject_Shape(py::module &mod){

py::class_<StdObject_Shape, std::unique_ptr<StdObject_Shape>> cls_StdObject_Shape(mod, "StdObject_Shape", "None");

// Constructors

// Fields

// Methods
cls_StdObject_Shape.def("Import", (TopoDS_Shape (StdObject_Shape::*)() const) &StdObject_Shape::Import, "Import transient object from the persistent data.");
cls_StdObject_Shape.def("PChildren", (void (StdObject_Shape::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdObject_Shape::PChildren, "None", py::arg("theChildren"));

// Enums

}