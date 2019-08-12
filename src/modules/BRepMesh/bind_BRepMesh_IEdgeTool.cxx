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
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_IEdgeTool.hxx>
#include <Standard_Type.hxx>

void bind_BRepMesh_IEdgeTool(py::module &mod){

py::class_<BRepMesh_IEdgeTool, opencascade::handle<BRepMesh_IEdgeTool>, Standard_Transient> cls_BRepMesh_IEdgeTool(mod, "BRepMesh_IEdgeTool", "Interface class providing API for edge tessellation tools.");

// Fields

// Methods
cls_BRepMesh_IEdgeTool.def("NbPoints", (Standard_Integer (BRepMesh_IEdgeTool::*)() const) &BRepMesh_IEdgeTool::NbPoints, "Returns number of tessellation points.");
cls_BRepMesh_IEdgeTool.def("Value", [](BRepMesh_IEdgeTool &self, const Standard_Integer theIndex, Standard_Real & theParameter, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theParameter, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("theParameter"), py::arg("thePoint"), py::arg("theUV"));
cls_BRepMesh_IEdgeTool.def_static("get_type_name_", (const char * (*)()) &BRepMesh_IEdgeTool::get_type_name, "None");
cls_BRepMesh_IEdgeTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_IEdgeTool::get_type_descriptor, "None");
cls_BRepMesh_IEdgeTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_IEdgeTool::*)() const) &BRepMesh_IEdgeTool::DynamicType, "None");

// Enums

}