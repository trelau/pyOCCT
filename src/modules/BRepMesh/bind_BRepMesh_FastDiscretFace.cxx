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
#include <Standard_Handle.hxx>
#include <BRepMesh_FaceAttribute.hxx>
#include <BRepMesh_FastDiscretFace.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepMesh_Delaun.hxx>
#include <BRepMesh.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_XY.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepMesh_CircleTool.hxx>
#include <NCollection_IncAllocator.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>

void bind_BRepMesh_FastDiscretFace(py::module &mod){

py::class_<BRepMesh_FastDiscretFace, opencascade::handle<BRepMesh_FastDiscretFace>, Standard_Transient> cls_BRepMesh_FastDiscretFace(mod, "BRepMesh_FastDiscretFace", "Algorithm to mesh a face with respect of the frontier the deflection and by option the shared components.");

// Constructors
cls_BRepMesh_FastDiscretFace.def(py::init<const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theAngle"), py::arg("theMinSize"), py::arg("isInternalVerticesMode"), py::arg("isControlSurfaceDeflection"));

// Fields

// Methods
cls_BRepMesh_FastDiscretFace.def("Perform", (void (BRepMesh_FastDiscretFace::*)(const opencascade::handle<BRepMesh_FaceAttribute> &)) &BRepMesh_FastDiscretFace::Perform, "None", py::arg("theAttribute"));
cls_BRepMesh_FastDiscretFace.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FastDiscretFace::get_type_name, "None");
cls_BRepMesh_FastDiscretFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FastDiscretFace::get_type_descriptor, "None");
cls_BRepMesh_FastDiscretFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FastDiscretFace::*)() const) &BRepMesh_FastDiscretFace::DynamicType, "None");

// Enums

}