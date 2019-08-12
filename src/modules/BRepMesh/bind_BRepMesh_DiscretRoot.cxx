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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_DiscretRoot.hxx>
#include <Standard_Type.hxx>

void bind_BRepMesh_DiscretRoot(py::module &mod){

py::class_<BRepMesh_DiscretRoot, opencascade::handle<BRepMesh_DiscretRoot>, Standard_Transient> cls_BRepMesh_DiscretRoot(mod, "BRepMesh_DiscretRoot", "This is a common interface for meshing algorithms instantiated by Mesh Factory and implemented by plugins.");

// Fields

// Methods
cls_BRepMesh_DiscretRoot.def("SetShape", (void (BRepMesh_DiscretRoot::*)(const TopoDS_Shape &)) &BRepMesh_DiscretRoot::SetShape, "Set the shape to triangulate.", py::arg("theShape"));
cls_BRepMesh_DiscretRoot.def("Shape", (const TopoDS_Shape & (BRepMesh_DiscretRoot::*)() const) &BRepMesh_DiscretRoot::Shape, "None");
cls_BRepMesh_DiscretRoot.def("IsDone", (Standard_Boolean (BRepMesh_DiscretRoot::*)() const) &BRepMesh_DiscretRoot::IsDone, "Returns true if triangualtion was performed and has success.");
cls_BRepMesh_DiscretRoot.def("Perform", (void (BRepMesh_DiscretRoot::*)()) &BRepMesh_DiscretRoot::Perform, "Compute triangulation for set shape.");
cls_BRepMesh_DiscretRoot.def_static("get_type_name_", (const char * (*)()) &BRepMesh_DiscretRoot::get_type_name, "None");
cls_BRepMesh_DiscretRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_DiscretRoot::get_type_descriptor, "None");
cls_BRepMesh_DiscretRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_DiscretRoot::*)() const) &BRepMesh_DiscretRoot::DynamicType, "None");

// Enums

}