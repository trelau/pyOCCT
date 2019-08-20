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
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepDS_Dumper.hxx>

void bind_TopOpeBRepDS_Dumper(py::module &mod){

py::class_<TopOpeBRepDS_Dumper, std::unique_ptr<TopOpeBRepDS_Dumper>> cls_TopOpeBRepDS_Dumper(mod, "TopOpeBRepDS_Dumper", "None");

// Constructors
cls_TopOpeBRepDS_Dumper.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Fields

// Methods
// cls_TopOpeBRepDS_Dumper.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Dumper::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Dumper.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Dumper::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Dumper.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Dumper::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Dumper.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Dumper::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Dumper.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Dumper::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Dumper.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Dumper::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Dumper.def("SDumpRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_Dumper::SDumpRefOri, "None", py::arg("K"), py::arg("I"));
cls_TopOpeBRepDS_Dumper.def("SDumpRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_Dumper::SDumpRefOri, "None", py::arg("S"));
cls_TopOpeBRepDS_Dumper.def("SPrintShape", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const Standard_Integer) const) &TopOpeBRepDS_Dumper::SPrintShape, "None", py::arg("I"));
cls_TopOpeBRepDS_Dumper.def("SPrintShape", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_Dumper::SPrintShape, "None", py::arg("S"));
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", [](TopOpeBRepDS_Dumper &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SPrintShapeRefOri(a0); });
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &, const TCollection_AsciiString &) const) &TopOpeBRepDS_Dumper::SPrintShapeRefOri, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", [](TopOpeBRepDS_Dumper &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SPrintShapeRefOri(a0); });
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &) const) &TopOpeBRepDS_Dumper::SPrintShapeRefOri, "None", py::arg("L"), py::arg("B"));

// Enums

}