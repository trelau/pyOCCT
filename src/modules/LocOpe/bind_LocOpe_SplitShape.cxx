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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <LocOpe_SplitShape.hxx>

void bind_LocOpe_SplitShape(py::module &mod){

py::class_<LocOpe_SplitShape, std::unique_ptr<LocOpe_SplitShape>> cls_LocOpe_SplitShape(mod, "LocOpe_SplitShape", "Provides a tool to cut : - edges with a vertices, - faces with wires, and rebuilds the shape containing the edges and the faces.");

// Constructors
cls_LocOpe_SplitShape.def(py::init<>());
cls_LocOpe_SplitShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_LocOpe_SplitShape.def_static("operator new_", (void * (*)(size_t)) &LocOpe_SplitShape::operator new, "None", py::arg("theSize"));
// cls_LocOpe_SplitShape.def_static("operator delete_", (void (*)(void *)) &LocOpe_SplitShape::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_SplitShape.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_SplitShape::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_SplitShape.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_SplitShape::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_SplitShape.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_SplitShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_SplitShape.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_SplitShape::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_SplitShape.def("Init", (void (LocOpe_SplitShape::*)(const TopoDS_Shape &)) &LocOpe_SplitShape::Init, "Initializes the process on the shape <S>.", py::arg("S"));
cls_LocOpe_SplitShape.def("CanSplit", (Standard_Boolean (LocOpe_SplitShape::*)(const TopoDS_Edge &) const) &LocOpe_SplitShape::CanSplit, "Tests if it is possible to split the edge <E>.", py::arg("E"));
cls_LocOpe_SplitShape.def("Add", (void (LocOpe_SplitShape::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &)) &LocOpe_SplitShape::Add, "Adds the vertex <V> on the edge <E>, at parameter <P>.", py::arg("V"), py::arg("P"), py::arg("E"));
cls_LocOpe_SplitShape.def("Add", (Standard_Boolean (LocOpe_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_SplitShape::Add, "Adds the wire <W> on the face <F>.", py::arg("W"), py::arg("F"));
cls_LocOpe_SplitShape.def("Add", (Standard_Boolean (LocOpe_SplitShape::*)(const TopTools_ListOfShape &, const TopoDS_Face &)) &LocOpe_SplitShape::Add, "Adds the list of wires <Lwires> on the face <F>.", py::arg("Lwires"), py::arg("F"));
cls_LocOpe_SplitShape.def("Shape", (const TopoDS_Shape & (LocOpe_SplitShape::*)() const) &LocOpe_SplitShape::Shape, "Returns the 'original' shape.");
cls_LocOpe_SplitShape.def("DescendantShapes", (const TopTools_ListOfShape & (LocOpe_SplitShape::*)(const TopoDS_Shape &)) &LocOpe_SplitShape::DescendantShapes, "Returns the list of descendant shapes of <S>.", py::arg("S"));
cls_LocOpe_SplitShape.def("LeftOf", (const TopTools_ListOfShape & (LocOpe_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_SplitShape::LeftOf, "Returns the 'left' part defined by the wire <W> on the face <F>. The returned list of shape is in fact a list of faces. The face <F> is considered with its topological orientation in the original shape. <W> is considered with its orientation.", py::arg("W"), py::arg("F"));

// Enums

}