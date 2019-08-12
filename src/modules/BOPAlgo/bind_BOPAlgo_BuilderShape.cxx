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
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BOPAlgo_BuilderShape.hxx>

void bind_BOPAlgo_BuilderShape(py::module &mod){

py::class_<BOPAlgo_BuilderShape, std::unique_ptr<BOPAlgo_BuilderShape, py::nodelete>, BOPAlgo_Algo> cls_BOPAlgo_BuilderShape(mod, "BOPAlgo_BuilderShape", "Root class for algorithms that has shape as result. The class provides the History mechanism, which allows tracking the modification of the input shapes during the operation.");

// Fields

// Methods
// cls_BOPAlgo_BuilderShape.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderShape::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderShape.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderShape::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderShape.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderShape::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderShape.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderShape::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderShape.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderShape.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderShape.def("Shape", (const TopoDS_Shape & (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::Shape, "Returns the result of algorithm");
cls_BOPAlgo_BuilderShape.def("Generated", (const TopTools_ListOfShape & (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::Generated, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));
cls_BOPAlgo_BuilderShape.def("Modified", (const TopTools_ListOfShape & (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::Modified, "Returns the list of shapes modified from the shape theS.", py::arg("theS"));
cls_BOPAlgo_BuilderShape.def("IsDeleted", (Standard_Boolean (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::IsDeleted, "Returns true if the shape theS has been deleted.", py::arg("theS"));
cls_BOPAlgo_BuilderShape.def("HasDeleted", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::HasDeleted, "Returns true if the at least one shape(or subshape) of arguments has been deleted.");
cls_BOPAlgo_BuilderShape.def("HasGenerated", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::HasGenerated, "Returns true if the at least one shape(or subshape) of arguments has generated shapes.");
cls_BOPAlgo_BuilderShape.def("HasModified", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::HasModified, "Returns true if the at least one shape(or subshape) of arguments has modified shapes.");
cls_BOPAlgo_BuilderShape.def("ImagesResult", (const TopTools_IndexedDataMapOfShapeListOfShape & (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::ImagesResult, "None");

// Enums

}