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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepTools_WireExplorer.hxx>

void bind_BRepTools_WireExplorer(py::module &mod){

py::class_<BRepTools_WireExplorer, std::unique_ptr<BRepTools_WireExplorer>> cls_BRepTools_WireExplorer(mod, "BRepTools_WireExplorer", "The WireExplorer is a tool to explore the edges of a wire in a connection order.");

// Constructors
cls_BRepTools_WireExplorer.def(py::init<>());
cls_BRepTools_WireExplorer.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepTools_WireExplorer.def(py::init<const TopoDS_Wire &, const TopoDS_Face &>(), py::arg("W"), py::arg("F"));

// Fields

// Methods
// cls_BRepTools_WireExplorer.def_static("operator new_", (void * (*)(size_t)) &BRepTools_WireExplorer::operator new, "None", py::arg("theSize"));
// cls_BRepTools_WireExplorer.def_static("operator delete_", (void (*)(void *)) &BRepTools_WireExplorer::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_WireExplorer.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_WireExplorer::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_WireExplorer.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_WireExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_WireExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_WireExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_WireExplorer.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_WireExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_WireExplorer.def("Init", (void (BRepTools_WireExplorer::*)(const TopoDS_Wire &)) &BRepTools_WireExplorer::Init, "Initializes an exploration of the wire <W>.", py::arg("W"));
cls_BRepTools_WireExplorer.def("Init", (void (BRepTools_WireExplorer::*)(const TopoDS_Wire &, const TopoDS_Face &)) &BRepTools_WireExplorer::Init, "Initializes an exploration of the wire <W>. F is used to select the edge connected to the previous in the parametric representation of <F>.", py::arg("W"), py::arg("F"));
cls_BRepTools_WireExplorer.def("Init", (void (BRepTools_WireExplorer::*)(const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepTools_WireExplorer::Init, "Initializes an exploration of the wire <W>. F is used to select the edge connected to the previous in the parametric representation of <F>. <UMIn>, <UMax>, <VMin>, <VMax> - the UV bounds of the face <F>.", py::arg("W"), py::arg("F"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepTools_WireExplorer.def("More", (Standard_Boolean (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::More, "Returns True if there is a current edge.");
cls_BRepTools_WireExplorer.def("Next", (void (BRepTools_WireExplorer::*)()) &BRepTools_WireExplorer::Next, "Proceeds to the next edge.");
cls_BRepTools_WireExplorer.def("Current", (const TopoDS_Edge & (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::Current, "Returns the current edge.");
cls_BRepTools_WireExplorer.def("Orientation", (TopAbs_Orientation (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::Orientation, "Returns an Orientation for the current edge.");
cls_BRepTools_WireExplorer.def("CurrentVertex", (const TopoDS_Vertex & (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::CurrentVertex, "Returns the vertex connecting the current edge to the previous one.");
cls_BRepTools_WireExplorer.def("Clear", (void (BRepTools_WireExplorer::*)()) &BRepTools_WireExplorer::Clear, "Clears the content of the explorer.");

// Enums

}