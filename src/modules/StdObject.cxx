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
#include <StdObjMgt_WriteData.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <StdObject_gp_Axes.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <TopLoc_Location.hxx>
#include <StdObject_Location.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <ShapePersistent_TopoDS.hxx>
#include <TopoDS_Shape.hxx>
#include <StdPersistent_TopoDS.hxx>
#include <Standard_TypeDef.hxx>
#include <StdObject_Shape.hxx>

PYBIND11_MODULE(StdObject, mod) {

py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");

// FUNCTION: WRITE
mod.def("write", (StdObjMgt_WriteData & (*) (StdObjMgt_WriteData &, const gp_Ax2d &)) &write, "None", py::arg("theWriteData"), py::arg("theAx"));

mod.def("write", (StdObjMgt_WriteData & (*) (StdObjMgt_WriteData &, const gp_Ax1 &)) &write, "None", py::arg("theWriteData"), py::arg("theAx"));

// CLASS: STDOBJECT_LOCATION
py::class_<StdObject_Location> cls_StdObject_Location(mod, "StdObject_Location", "None");

// Methods
cls_StdObject_Location.def("PChildren", (void (StdObject_Location::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdObject_Location::PChildren, "Gets persistent child objects", py::arg("theChildren"));
// cls_StdObject_Location.def("Import", (TopLoc_Location (StdObject_Location::*)() const) &StdObject_Location::Import, "Import transient object from the persistent data.");
cls_StdObject_Location.def_static("Translate_", (StdObject_Location (*)(const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &StdObject_Location::Translate, "Creates a persistent wrapper object for a location", py::arg("theLoc"), py::arg("theMap"));

// CLASS: STDOBJECT_SHAPE
py::class_<StdObject_Shape> cls_StdObject_Shape(mod, "StdObject_Shape", "None");

// Methods
cls_StdObject_Shape.def("Import", (TopoDS_Shape (StdObject_Shape::*)() const) &StdObject_Shape::Import, "Import transient object from the persistent data.");
cls_StdObject_Shape.def("PChildren", (void (StdObject_Shape::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdObject_Shape::PChildren, "None", py::arg("theChildren"));


}
