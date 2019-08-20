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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeProcess_ShapeContext.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TCollection_AsciiString.hxx>
#include <ShapeProcessAPI_ApplySequence.hxx>

void bind_ShapeProcessAPI_ApplySequence(py::module &mod){

py::class_<ShapeProcessAPI_ApplySequence, std::unique_ptr<ShapeProcessAPI_ApplySequence>> cls_ShapeProcessAPI_ApplySequence(mod, "ShapeProcessAPI_ApplySequence", "Applies one of the sequence read from resource file.");

// Constructors
cls_ShapeProcessAPI_ApplySequence.def(py::init<const Standard_CString>(), py::arg("rscName"));
cls_ShapeProcessAPI_ApplySequence.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("rscName"), py::arg("seqName"));

// Fields

// Methods
// cls_ShapeProcessAPI_ApplySequence.def_static("operator new_", (void * (*)(size_t)) &ShapeProcessAPI_ApplySequence::operator new, "None", py::arg("theSize"));
// cls_ShapeProcessAPI_ApplySequence.def_static("operator delete_", (void (*)(void *)) &ShapeProcessAPI_ApplySequence::operator delete, "None", py::arg("theAddress"));
// cls_ShapeProcessAPI_ApplySequence.def_static("operator new[]_", (void * (*)(size_t)) &ShapeProcessAPI_ApplySequence::operator new[], "None", py::arg("theSize"));
// cls_ShapeProcessAPI_ApplySequence.def_static("operator delete[]_", (void (*)(void *)) &ShapeProcessAPI_ApplySequence::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeProcessAPI_ApplySequence.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeProcessAPI_ApplySequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeProcessAPI_ApplySequence.def_static("operator delete_", (void (*)(void *, void *)) &ShapeProcessAPI_ApplySequence::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeProcessAPI_ApplySequence.def("Context", (opencascade::handle<ShapeProcess_ShapeContext> & (ShapeProcessAPI_ApplySequence::*)()) &ShapeProcessAPI_ApplySequence::Context, "Returns object for managing resource file and sequence of operators.");
cls_ShapeProcessAPI_ApplySequence.def("PrepareShape", [](ShapeProcessAPI_ApplySequence &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.PrepareShape(a0); });
cls_ShapeProcessAPI_ApplySequence.def("PrepareShape", [](ShapeProcessAPI_ApplySequence &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> TopoDS_Shape { return self.PrepareShape(a0, a1); });
cls_ShapeProcessAPI_ApplySequence.def("PrepareShape", (TopoDS_Shape (ShapeProcessAPI_ApplySequence::*)(const TopoDS_Shape &, const Standard_Boolean, const TopAbs_ShapeEnum)) &ShapeProcessAPI_ApplySequence::PrepareShape, "Performs sequence of operators stored in myRsc. If <fillmap> is True adds history 'shape-shape' into myMap for shape and its subshapes until level <until> (included). If <until> is TopAbs_SHAPE, all the subshapes are considered.", py::arg("shape"), py::arg("fillmap"), py::arg("until"));
cls_ShapeProcessAPI_ApplySequence.def("ClearMap", (void (ShapeProcessAPI_ApplySequence::*)()) &ShapeProcessAPI_ApplySequence::ClearMap, "Clears myMap with accumulated history.");
cls_ShapeProcessAPI_ApplySequence.def("Map", (const TopTools_DataMapOfShapeShape & (ShapeProcessAPI_ApplySequence::*)() const) &ShapeProcessAPI_ApplySequence::Map, "Returns myMap with accumulated history.");
cls_ShapeProcessAPI_ApplySequence.def("PrintPreparationResult", (void (ShapeProcessAPI_ApplySequence::*)() const) &ShapeProcessAPI_ApplySequence::PrintPreparationResult, "Prints result of preparation onto the messenger of the context. Note that results can be accumulated from previous preparations it method ClearMap was not called before PrepareShape.");

// Enums

}