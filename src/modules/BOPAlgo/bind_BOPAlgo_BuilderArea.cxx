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
#include <BOPAlgo_Algo.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <BOPAlgo_BuilderArea.hxx>

void bind_BOPAlgo_BuilderArea(py::module &mod){

py::class_<BOPAlgo_BuilderArea, std::unique_ptr<BOPAlgo_BuilderArea, py::nodelete>, BOPAlgo_Algo> cls_BOPAlgo_BuilderArea(mod, "BOPAlgo_BuilderArea", "The root class for algorithms to build faces/solids from set of edges/faces");

// Fields

// Methods
// cls_BOPAlgo_BuilderArea.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderArea::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderArea.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderArea::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderArea.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderArea::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderArea.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderArea::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderArea.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderArea.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderArea::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderArea.def("SetContext", (void (BOPAlgo_BuilderArea::*)(const opencascade::handle<IntTools_Context> &)) &BOPAlgo_BuilderArea::SetContext, "Sets the context for the algorithms", py::arg("theContext"));
cls_BOPAlgo_BuilderArea.def("Shapes", (const TopTools_ListOfShape & (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::Shapes, "Returns the input shapes");
cls_BOPAlgo_BuilderArea.def("SetShapes", (void (BOPAlgo_BuilderArea::*)(const TopTools_ListOfShape &)) &BOPAlgo_BuilderArea::SetShapes, "Sets the shapes for building areas", py::arg("theLS"));
cls_BOPAlgo_BuilderArea.def("Loops", (const TopTools_ListOfShape & (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::Loops, "Returns the found loops");
cls_BOPAlgo_BuilderArea.def("Areas", (const TopTools_ListOfShape & (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::Areas, "Returns the found areas");
cls_BOPAlgo_BuilderArea.def("SetAvoidInternalShapes", (void (BOPAlgo_BuilderArea::*)(const Standard_Boolean)) &BOPAlgo_BuilderArea::SetAvoidInternalShapes, "Defines the preventing of addition of internal parts into result. The default value is FALSE, i.e. the internal parts are added into result.", py::arg("theAvoidInternal"));
cls_BOPAlgo_BuilderArea.def("IsAvoidInternalShapes", (Standard_Boolean (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::IsAvoidInternalShapes, "Returns the AvoidInternalShapes flag");

// Enums

}