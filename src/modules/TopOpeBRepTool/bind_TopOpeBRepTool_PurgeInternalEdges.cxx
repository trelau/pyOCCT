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
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_PurgeInternalEdges.hxx>

void bind_TopOpeBRepTool_PurgeInternalEdges(py::module &mod){

py::class_<TopOpeBRepTool_PurgeInternalEdges> cls_TopOpeBRepTool_PurgeInternalEdges(mod, "TopOpeBRepTool_PurgeInternalEdges", "remove from a shape, the internal edges that are not connected to any face in the shape. We can get the list of the edges as a DataMapOfShapeListOfShape with a Face of the Shape as the key and a list of internal edges as the value. The list of internal edges means edges that are not connected to any face in the shape.");

// Constructors
cls_TopOpeBRepTool_PurgeInternalEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_TopOpeBRepTool_PurgeInternalEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));

// Fields

// Methods
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_PurgeInternalEdges::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_PurgeInternalEdges::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_PurgeInternalEdges::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_PurgeInternalEdges::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_PurgeInternalEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_PurgeInternalEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_PurgeInternalEdges.def("Faces", (void (TopOpeBRepTool_PurgeInternalEdges::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_PurgeInternalEdges::Faces, "returns the list internal edges associated with the faces of the myShape. If PerformNow was False when created, then call the private Perform method that do the main job.", py::arg("theMapFacLstEdg"));
cls_TopOpeBRepTool_PurgeInternalEdges.def("Shape", (TopoDS_Shape & (TopOpeBRepTool_PurgeInternalEdges::*)()) &TopOpeBRepTool_PurgeInternalEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
cls_TopOpeBRepTool_PurgeInternalEdges.def("NbEdges", (Standard_Integer (TopOpeBRepTool_PurgeInternalEdges::*)() const) &TopOpeBRepTool_PurgeInternalEdges::NbEdges, "returns the number of edges candidate to be removed");
cls_TopOpeBRepTool_PurgeInternalEdges.def("IsDone", (Standard_Boolean (TopOpeBRepTool_PurgeInternalEdges::*)() const) &TopOpeBRepTool_PurgeInternalEdges::IsDone, "returns False if the list of internal edges has not been extracted");
cls_TopOpeBRepTool_PurgeInternalEdges.def("Perform", (void (TopOpeBRepTool_PurgeInternalEdges::*)()) &TopOpeBRepTool_PurgeInternalEdges::Perform, "Using the list of internal edge from each face, rebuild myShape by removing thoses edges.");

// Enums

}