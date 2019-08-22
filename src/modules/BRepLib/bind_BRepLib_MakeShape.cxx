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
#include <BRepLib_Command.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepLib_ShapeModification.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepLib_MakeShape.hxx>

void bind_BRepLib_MakeShape(py::module &mod){

py::class_<BRepLib_MakeShape, BRepLib_Command> cls_BRepLib_MakeShape(mod, "BRepLib_MakeShape", "This is the root class for all shape constructions. It stores the result.");

// Constructors

// Fields

// Methods
// cls_BRepLib_MakeShape.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeShape::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeShape.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeShape::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeShape.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeShape.def("Build", (void (BRepLib_MakeShape::*)()) &BRepLib_MakeShape::Build, "This is called by Shape(). It does nothing but may be redefined.");
cls_BRepLib_MakeShape.def("Shape", (const TopoDS_Shape & (BRepLib_MakeShape::*)()) &BRepLib_MakeShape::Shape, "None");
cls_BRepLib_MakeShape.def("FaceStatus", (BRepLib_ShapeModification (BRepLib_MakeShape::*)(const TopoDS_Face &) const) &BRepLib_MakeShape::FaceStatus, "returns the status of the Face after the shape creation.", py::arg("F"));
cls_BRepLib_MakeShape.def("HasDescendants", (Standard_Boolean (BRepLib_MakeShape::*)(const TopoDS_Face &) const) &BRepLib_MakeShape::HasDescendants, "Returns True if the Face generates new topology.", py::arg("F"));
cls_BRepLib_MakeShape.def("DescendantFaces", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const TopoDS_Face &)) &BRepLib_MakeShape::DescendantFaces, "returns the list of generated Faces.", py::arg("F"));
cls_BRepLib_MakeShape.def("NbSurfaces", (Standard_Integer (BRepLib_MakeShape::*)() const) &BRepLib_MakeShape::NbSurfaces, "returns the number of surfaces after the shape creation.");
cls_BRepLib_MakeShape.def("NewFaces", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const Standard_Integer)) &BRepLib_MakeShape::NewFaces, "Return the faces created for surface I.", py::arg("I"));
cls_BRepLib_MakeShape.def("FacesFromEdges", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const TopoDS_Edge &)) &BRepLib_MakeShape::FacesFromEdges, "returns a list of the created faces from the edge <E>.", py::arg("E"));

// Enums

}