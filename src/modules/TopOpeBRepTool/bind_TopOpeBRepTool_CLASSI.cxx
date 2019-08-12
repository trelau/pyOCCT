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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Bnd_Box2d.hxx>
#include <TopOpeBRepTool_face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeBox2d.hxx>
#include <TopOpeBRepTool_DataMapOfShapeface.hxx>
#include <TopOpeBRepTool_CLASSI.hxx>

void bind_TopOpeBRepTool_CLASSI(py::module &mod){

py::class_<TopOpeBRepTool_CLASSI, std::unique_ptr<TopOpeBRepTool_CLASSI, Deleter<TopOpeBRepTool_CLASSI>>> cls_TopOpeBRepTool_CLASSI(mod, "TopOpeBRepTool_CLASSI", "None");

// Constructors
cls_TopOpeBRepTool_CLASSI.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepTool_CLASSI.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_CLASSI::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_CLASSI::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_CLASSI::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_CLASSI::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_CLASSI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_CLASSI::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_CLASSI.def("Init2d", (void (TopOpeBRepTool_CLASSI::*)(const TopoDS_Face &)) &TopOpeBRepTool_CLASSI::Init2d, "None", py::arg("Fref"));
cls_TopOpeBRepTool_CLASSI.def("HasInit2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)() const) &TopOpeBRepTool_CLASSI::HasInit2d, "None");
cls_TopOpeBRepTool_CLASSI.def("Add2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &)) &TopOpeBRepTool_CLASSI::Add2d, "None", py::arg("S"));
cls_TopOpeBRepTool_CLASSI.def("GetBox2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, Bnd_Box2d &)) &TopOpeBRepTool_CLASSI::GetBox2d, "None", py::arg("S"), py::arg("Box2d"));
cls_TopOpeBRepTool_CLASSI.def("ClassiBnd2d", (Standard_Integer (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &TopOpeBRepTool_CLASSI::ClassiBnd2d, "None", py::arg("S1"), py::arg("S2"), py::arg("tol"), py::arg("checklarge"));
cls_TopOpeBRepTool_CLASSI.def("Classip2d", (Standard_Integer (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepTool_CLASSI::Classip2d, "None", py::arg("S1"), py::arg("S2"), py::arg("stabnd2d12"));
cls_TopOpeBRepTool_CLASSI.def("Getface", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, TopOpeBRepTool_face &) const) &TopOpeBRepTool_CLASSI::Getface, "None", py::arg("S"), py::arg("fa"));
cls_TopOpeBRepTool_CLASSI.def("Classilist", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopTools_ListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_CLASSI::Classilist, "None", py::arg("lS"), py::arg("mapgreasma"));

// Enums

}