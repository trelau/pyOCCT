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
#include <StdPersistent_TopoDS.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObject_Shape.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapePersistent_TopoDS.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <StdPersistent_HArray1.hxx>
#include <TopoDS_TWire.hxx>
#include <TopoDS_TShell.hxx>
#include <TopoDS_TSolid.hxx>
#include <TopoDS_TCompSolid.hxx>
#include <TopoDS_TCompound.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <ShapePersistent_TriangleMode.hxx>

void bind_ShapePersistent_TopoDS(py::module &mod){

/*
py::class_<ShapePersistent_TopoDS, StdPersistent_TopoDS> cls_ShapePersistent_TopoDS(mod, "ShapePersistent_TopoDS", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_TopoDS.def_static("Translate_", (opencascade::handle<HShape> (*)(const TopoDS_Shape &, StdObjMgt_TransientPersistentMap &, ShapePersistent_TriangleMode)) &ShapePersistent_TopoDS::Translate, "Create a persistent object for a shape", py::arg("theShape"), py::arg("theMap"), py::arg("theTriangleMode"));

// Enums
*/

}