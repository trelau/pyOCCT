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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <BRepBuilderAPI_FastSewing.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <NCollection_CellFilter.hxx>
#include <BRep_Builder.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <NCollection_List.hxx>
#include <NCollection_Vector.hxx>
#include <Standard_RangeError.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <NCollection_Sequence.hxx>
#include <TopoDS_Edge.hxx>

void bind_BRepBuilderAPI_FastSewing(py::module &mod){

py::class_<BRepBuilderAPI_FastSewing, opencascade::handle<BRepBuilderAPI_FastSewing>, Standard_Transient> cls_BRepBuilderAPI_FastSewing(mod, "BRepBuilderAPI_FastSewing", "This class performs fast sewing of surfaces (faces). It supposes that all surfaces are finite and are naturally restricted by their bounds. Moreover, it supposes that stitched together surfaces have the same parameterization along common boundaries, therefore it does not perform time-consuming check for SameParameter property of edges.");

// Constructors
cls_BRepBuilderAPI_FastSewing.def(py::init<>());
cls_BRepBuilderAPI_FastSewing.def(py::init<const Standard_Real>(), py::arg("theTolerance"));

// Fields

// Methods
cls_BRepBuilderAPI_FastSewing.def("Add", (Standard_Boolean (BRepBuilderAPI_FastSewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_FastSewing::Add, "Adds faces of a shape", py::arg("theShape"));
cls_BRepBuilderAPI_FastSewing.def("Add", (Standard_Boolean (BRepBuilderAPI_FastSewing::*)(const opencascade::handle<Geom_Surface> &)) &BRepBuilderAPI_FastSewing::Add, "Adds a surface", py::arg("theSurface"));
cls_BRepBuilderAPI_FastSewing.def("Perform", (void (BRepBuilderAPI_FastSewing::*)()) &BRepBuilderAPI_FastSewing::Perform, "Compute resulted shape");
cls_BRepBuilderAPI_FastSewing.def("SetTolerance", (void (BRepBuilderAPI_FastSewing::*)(const Standard_Real)) &BRepBuilderAPI_FastSewing::SetTolerance, "Sets tolerance", py::arg("theToler"));
cls_BRepBuilderAPI_FastSewing.def("GetTolerance", (Standard_Real (BRepBuilderAPI_FastSewing::*)() const) &BRepBuilderAPI_FastSewing::GetTolerance, "Returns tolerance");
cls_BRepBuilderAPI_FastSewing.def("GetResult", (const TopoDS_Shape & (BRepBuilderAPI_FastSewing::*)() const) &BRepBuilderAPI_FastSewing::GetResult, "Returns resulted shape");
cls_BRepBuilderAPI_FastSewing.def("GetStatuses", [](BRepBuilderAPI_FastSewing &self) -> BRepBuilderAPI_FastSewing::FS_VARStatuses { return self.GetStatuses(); });
cls_BRepBuilderAPI_FastSewing.def("GetStatuses", (BRepBuilderAPI_FastSewing::FS_VARStatuses (BRepBuilderAPI_FastSewing::*)(Standard_OStream *const)) &BRepBuilderAPI_FastSewing::GetStatuses, "Returns list of statuses. Print message if theOS != 0", py::arg("theOS"));
cls_BRepBuilderAPI_FastSewing.def_static("get_type_name_", (const char * (*)()) &BRepBuilderAPI_FastSewing::get_type_name, "None");
cls_BRepBuilderAPI_FastSewing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBuilderAPI_FastSewing::get_type_descriptor, "None");
cls_BRepBuilderAPI_FastSewing.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBuilderAPI_FastSewing::*)() const) &BRepBuilderAPI_FastSewing::DynamicType, "None");

// Enums
py::enum_<BRepBuilderAPI_FastSewing::FS_Statuses>(cls_BRepBuilderAPI_FastSewing, "FS_Statuses", "Enumeration of result statuses")
	.value("FS_OK", BRepBuilderAPI_FastSewing::FS_Statuses::FS_OK)
	.value("FS_Degenerated", BRepBuilderAPI_FastSewing::FS_Statuses::FS_Degenerated)
	.value("FS_FindVertexError", BRepBuilderAPI_FastSewing::FS_Statuses::FS_FindVertexError)
	.value("FS_FindEdgeError", BRepBuilderAPI_FastSewing::FS_Statuses::FS_FindEdgeError)
	.value("FS_FaceWithNullSurface", BRepBuilderAPI_FastSewing::FS_Statuses::FS_FaceWithNullSurface)
	.value("FS_NotNaturalBoundsFace", BRepBuilderAPI_FastSewing::FS_Statuses::FS_NotNaturalBoundsFace)
	.value("FS_InfiniteSurface", BRepBuilderAPI_FastSewing::FS_Statuses::FS_InfiniteSurface)
	.value("FS_EmptyInput", BRepBuilderAPI_FastSewing::FS_Statuses::FS_EmptyInput)
	.value("FS_Exception", BRepBuilderAPI_FastSewing::FS_Statuses::FS_Exception)
	.export_values();

}