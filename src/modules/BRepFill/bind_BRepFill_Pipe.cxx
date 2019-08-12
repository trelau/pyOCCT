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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <GeomFill_Trihedron.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <BRepFill_LocationLaw.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepFill_DataMapOfShapeHArray2OfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepFill_Pipe.hxx>

void bind_BRepFill_Pipe(py::module &mod){

py::class_<BRepFill_Pipe, std::unique_ptr<BRepFill_Pipe, Deleter<BRepFill_Pipe>>> cls_BRepFill_Pipe(mod, "BRepFill_Pipe", "Create a shape by sweeping a shape (the profile) along a wire (the spine).");

// Constructors
cls_BRepFill_Pipe.def(py::init<>());
cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Spine"), py::arg("Profile"));
cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"));
cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"), py::arg("ForceApproxC1"));
cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron, const Standard_Boolean, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"), py::arg("ForceApproxC1"), py::arg("GeneratePartCase"));

// Fields

// Methods
// cls_BRepFill_Pipe.def_static("operator new_", (void * (*)(size_t)) &BRepFill_Pipe::operator new, "None", py::arg("theSize"));
// cls_BRepFill_Pipe.def_static("operator delete_", (void (*)(void *)) &BRepFill_Pipe::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_Pipe.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_Pipe::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_Pipe.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_Pipe::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_Pipe.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_Pipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_Pipe.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_Pipe::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_Pipe.def("Perform", [](BRepFill_Pipe &self, const TopoDS_Wire & a0, const TopoDS_Shape & a1) -> void { return self.Perform(a0, a1); });
cls_BRepFill_Pipe.def("Perform", (void (BRepFill_Pipe::*)(const TopoDS_Wire &, const TopoDS_Shape &, const Standard_Boolean)) &BRepFill_Pipe::Perform, "None", py::arg("Spine"), py::arg("Profile"), py::arg("GeneratePartCase"));
cls_BRepFill_Pipe.def("Spine", (const TopoDS_Shape & (BRepFill_Pipe::*)() const) &BRepFill_Pipe::Spine, "None");
cls_BRepFill_Pipe.def("Profile", (const TopoDS_Shape & (BRepFill_Pipe::*)() const) &BRepFill_Pipe::Profile, "None");
cls_BRepFill_Pipe.def("Shape", (const TopoDS_Shape & (BRepFill_Pipe::*)() const) &BRepFill_Pipe::Shape, "None");
cls_BRepFill_Pipe.def("ErrorOnSurface", (Standard_Real (BRepFill_Pipe::*)() const) &BRepFill_Pipe::ErrorOnSurface, "None");
cls_BRepFill_Pipe.def("FirstShape", (const TopoDS_Shape & (BRepFill_Pipe::*)() const) &BRepFill_Pipe::FirstShape, "None");
cls_BRepFill_Pipe.def("LastShape", (const TopoDS_Shape & (BRepFill_Pipe::*)() const) &BRepFill_Pipe::LastShape, "None");
cls_BRepFill_Pipe.def("Generated", (void (BRepFill_Pipe::*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepFill_Pipe::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"), py::arg("L"));
cls_BRepFill_Pipe.def("Face", (TopoDS_Face (BRepFill_Pipe::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFill_Pipe::Face, "Returns the face created from an edge of the spine and an edge of the profile. if the edges are not in the spine or the profile", py::arg("ESpine"), py::arg("EProfile"));
cls_BRepFill_Pipe.def("Edge", (TopoDS_Edge (BRepFill_Pipe::*)(const TopoDS_Edge &, const TopoDS_Vertex &)) &BRepFill_Pipe::Edge, "Returns the edge created from an edge of the spine and a vertex of the profile. if the edge or the vertex are not in the spine or the profile.", py::arg("ESpine"), py::arg("VProfile"));
cls_BRepFill_Pipe.def("Section", (TopoDS_Shape (BRepFill_Pipe::*)(const TopoDS_Vertex &) const) &BRepFill_Pipe::Section, "Returns the shape created from the profile at the position of the vertex VSpine. if the vertex is not in the Spine", py::arg("VSpine"));
cls_BRepFill_Pipe.def("PipeLine", (TopoDS_Wire (BRepFill_Pipe::*)(const gp_Pnt &)) &BRepFill_Pipe::PipeLine, "Create a Wire by sweeping the Point along the <spine> if the <Spine> is undefined", py::arg("Point"));

// Enums

}