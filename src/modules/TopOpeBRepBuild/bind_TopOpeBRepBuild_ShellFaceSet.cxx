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
#include <TopOpeBRepBuild_ShapeSet.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Solid.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepBuild_ShellFaceSet.hxx>

void bind_TopOpeBRepBuild_ShellFaceSet(py::module &mod){

py::class_<TopOpeBRepBuild_ShellFaceSet, TopOpeBRepBuild_ShapeSet> cls_TopOpeBRepBuild_ShellFaceSet(mod, "TopOpeBRepBuild_ShellFaceSet", "a bound is a shell, a boundelement is a face. The ShapeSet stores : - a list of shell (bounds), - a list of face (boundelements) to start reconstructions, - a map of edge giving the list of face incident to an edge.");

// Constructors
cls_TopOpeBRepBuild_ShellFaceSet.def(py::init<>());
cls_TopOpeBRepBuild_ShellFaceSet.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def(py::init<const TopoDS_Shape &, const Standard_Address>(), py::arg("S"), py::arg("Addr"));

// Fields

// Methods
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShellFaceSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShellFaceSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShellFaceSet.def("Solid", (const TopoDS_Solid & (TopOpeBRepBuild_ShellFaceSet::*)() const) &TopOpeBRepBuild_ShellFaceSet::Solid, "None");
cls_TopOpeBRepBuild_ShellFaceSet.def("AddShape", (void (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceSet::AddShape, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def("AddStartElement", (void (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceSet::AddStartElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def("AddElement", (void (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceSet::AddElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def("DumpSS", (void (TopOpeBRepBuild_ShellFaceSet::*)()) &TopOpeBRepBuild_ShellFaceSet::DumpSS, "None");
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));

// Enums

}