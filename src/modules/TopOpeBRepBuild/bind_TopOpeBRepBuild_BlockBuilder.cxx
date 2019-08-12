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
#include <TopOpeBRepBuild_ShapeSet.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepBuild_BlockIterator.hxx>
#include <TopoDS_Shape.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>

void bind_TopOpeBRepBuild_BlockBuilder(py::module &mod){

py::class_<TopOpeBRepBuild_BlockBuilder, std::unique_ptr<TopOpeBRepBuild_BlockBuilder, Deleter<TopOpeBRepBuild_BlockBuilder>>> cls_TopOpeBRepBuild_BlockBuilder(mod, "TopOpeBRepBuild_BlockBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_BlockBuilder.def(py::init<>());
cls_TopOpeBRepBuild_BlockBuilder.def(py::init<TopOpeBRepBuild_ShapeSet &>(), py::arg("SS"));

// Fields

// Methods
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_BlockBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_BlockBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_BlockBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_BlockBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_BlockBuilder.def("MakeBlock", (void (TopOpeBRepBuild_BlockBuilder::*)(TopOpeBRepBuild_ShapeSet &)) &TopOpeBRepBuild_BlockBuilder::MakeBlock, "None", py::arg("SS"));
cls_TopOpeBRepBuild_BlockBuilder.def("InitBlock", (void (TopOpeBRepBuild_BlockBuilder::*)()) &TopOpeBRepBuild_BlockBuilder::InitBlock, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("MoreBlock", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)() const) &TopOpeBRepBuild_BlockBuilder::MoreBlock, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("NextBlock", (void (TopOpeBRepBuild_BlockBuilder::*)()) &TopOpeBRepBuild_BlockBuilder::NextBlock, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("BlockIterator", (TopOpeBRepBuild_BlockIterator (TopOpeBRepBuild_BlockBuilder::*)() const) &TopOpeBRepBuild_BlockBuilder::BlockIterator, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("Element", (const TopoDS_Shape & (TopOpeBRepBuild_BlockBuilder::*)(const TopOpeBRepBuild_BlockIterator &) const) &TopOpeBRepBuild_BlockBuilder::Element, "Returns the current element of <BI>.", py::arg("BI"));
cls_TopOpeBRepBuild_BlockBuilder.def("Element", (const TopoDS_Shape & (TopOpeBRepBuild_BlockBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_BlockBuilder::Element, "None", py::arg("I"));
cls_TopOpeBRepBuild_BlockBuilder.def("Element", (Standard_Integer (TopOpeBRepBuild_BlockBuilder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_BlockBuilder::Element, "None", py::arg("S"));
cls_TopOpeBRepBuild_BlockBuilder.def("ElementIsValid", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)(const TopOpeBRepBuild_BlockIterator &) const) &TopOpeBRepBuild_BlockBuilder::ElementIsValid, "None", py::arg("BI"));
cls_TopOpeBRepBuild_BlockBuilder.def("ElementIsValid", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_BlockBuilder::ElementIsValid, "None", py::arg("I"));
cls_TopOpeBRepBuild_BlockBuilder.def("AddElement", (Standard_Integer (TopOpeBRepBuild_BlockBuilder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_BlockBuilder::AddElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_BlockBuilder.def("SetValid", (void (TopOpeBRepBuild_BlockBuilder::*)(const TopOpeBRepBuild_BlockIterator &, const Standard_Boolean)) &TopOpeBRepBuild_BlockBuilder::SetValid, "None", py::arg("BI"), py::arg("isvalid"));
cls_TopOpeBRepBuild_BlockBuilder.def("SetValid", (void (TopOpeBRepBuild_BlockBuilder::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepBuild_BlockBuilder::SetValid, "None", py::arg("I"), py::arg("isvalid"));
cls_TopOpeBRepBuild_BlockBuilder.def("CurrentBlockIsRegular", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)()) &TopOpeBRepBuild_BlockBuilder::CurrentBlockIsRegular, "None");

// Enums

}