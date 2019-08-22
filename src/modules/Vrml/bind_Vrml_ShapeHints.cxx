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
#include <Standard.hxx>
#include <Vrml_VertexOrdering.hxx>
#include <Vrml_ShapeType.hxx>
#include <Vrml_FaceType.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_ShapeHints.hxx>

void bind_Vrml_ShapeHints(py::module &mod){

py::class_<Vrml_ShapeHints> cls_Vrml_ShapeHints(mod, "Vrml_ShapeHints", "defines a ShapeHints node of VRML specifying properties of geometry and its appearance. The ShapeHints node indicates that IndexedFaceSets are solid, contain ordered vertices, or contain convex faces. These hints allow VRML implementations to optimize certain rendering features. Optimizations that may be performed include enabling back-face culling and disabling two-sided lighting. For example, if an object is solid and has ordered vertices, an implementation may turn on backface culling and turn off two-sided lighting. To ensure that an IndexedFaceSet can be viewed from either direction, set shapeType to be UNKNOWN_SHAPE_TYPE. If you know that your shapes are closed and will alwsys be viewed from the outside, set vertexOrdering to be either CLOCKWISE or COUNTERCLOCKWISE (depending on how you built your object), and set shapeType to be SOLID. Placing this near the top of your VRML file will allow the scene to be rendered much faster. The ShapeHints node also affects how default normals are generated. When an IndexedFaceSet has to generate default normals, it uses the creaseAngle field to determine which edges should be smoothly shaded and which ones should have a sharp crease. The crease angle is the angle between surface normals on adjacent polygons. For example, a crease angle of .5 radians (the default value) means that an edge between two adjacent polygonal faces will be smooth shaded if the normals to the two faces form an angle that is less than .5 radians (about 30 degrees). Otherwise, it will be faceted.");

// Constructors
cls_Vrml_ShapeHints.def(py::init<>());
cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering>(), py::arg("aVertexOrdering"));
cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering, const Vrml_ShapeType>(), py::arg("aVertexOrdering"), py::arg("aShapeType"));
cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering, const Vrml_ShapeType, const Vrml_FaceType>(), py::arg("aVertexOrdering"), py::arg("aShapeType"), py::arg("aFaceType"));
cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering, const Vrml_ShapeType, const Vrml_FaceType, const Standard_Real>(), py::arg("aVertexOrdering"), py::arg("aShapeType"), py::arg("aFaceType"), py::arg("aAngle"));

// Fields

// Methods
// cls_Vrml_ShapeHints.def_static("operator new_", (void * (*)(size_t)) &Vrml_ShapeHints::operator new, "None", py::arg("theSize"));
// cls_Vrml_ShapeHints.def_static("operator delete_", (void (*)(void *)) &Vrml_ShapeHints::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_ShapeHints.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_ShapeHints::operator new[], "None", py::arg("theSize"));
// cls_Vrml_ShapeHints.def_static("operator delete[]_", (void (*)(void *)) &Vrml_ShapeHints::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_ShapeHints.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_ShapeHints::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_ShapeHints.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_ShapeHints::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_ShapeHints.def("SetVertexOrdering", (void (Vrml_ShapeHints::*)(const Vrml_VertexOrdering)) &Vrml_ShapeHints::SetVertexOrdering, "None", py::arg("aVertexOrdering"));
cls_Vrml_ShapeHints.def("VertexOrdering", (Vrml_VertexOrdering (Vrml_ShapeHints::*)() const) &Vrml_ShapeHints::VertexOrdering, "None");
cls_Vrml_ShapeHints.def("SetShapeType", (void (Vrml_ShapeHints::*)(const Vrml_ShapeType)) &Vrml_ShapeHints::SetShapeType, "None", py::arg("aShapeType"));
cls_Vrml_ShapeHints.def("ShapeType", (Vrml_ShapeType (Vrml_ShapeHints::*)() const) &Vrml_ShapeHints::ShapeType, "None");
cls_Vrml_ShapeHints.def("SetFaceType", (void (Vrml_ShapeHints::*)(const Vrml_FaceType)) &Vrml_ShapeHints::SetFaceType, "None", py::arg("aFaceType"));
cls_Vrml_ShapeHints.def("FaceType", (Vrml_FaceType (Vrml_ShapeHints::*)() const) &Vrml_ShapeHints::FaceType, "None");
cls_Vrml_ShapeHints.def("SetAngle", (void (Vrml_ShapeHints::*)(const Standard_Real)) &Vrml_ShapeHints::SetAngle, "None", py::arg("aAngle"));
cls_Vrml_ShapeHints.def("Angle", (Standard_Real (Vrml_ShapeHints::*)() const) &Vrml_ShapeHints::Angle, "None");
cls_Vrml_ShapeHints.def("Print", (Standard_OStream & (Vrml_ShapeHints::*)(Standard_OStream &) const) &Vrml_ShapeHints::Print, "None", py::arg("anOStream"));

// Enums

}