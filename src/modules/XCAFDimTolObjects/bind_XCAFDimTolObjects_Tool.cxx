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
#include <TDocStd_Document.hxx>
#include <XCAFDimTolObjects_DimensionObjectSequence.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <XCAFDimTolObjects_GeomToleranceObjectSequence.hxx>
#include <XCAFDimTolObjects_DatumObjectSequence.hxx>
#include <XCAFDimTolObjects_DataMapOfToleranceDatum.hxx>
#include <XCAFDimTolObjects_DatumObject.hxx>
#include <XCAFDoc_DimTolTool.hxx>
#include <XCAFDimTolObjects_Tool.hxx>

void bind_XCAFDimTolObjects_Tool(py::module &mod){

py::class_<XCAFDimTolObjects_Tool, std::unique_ptr<XCAFDimTolObjects_Tool>> cls_XCAFDimTolObjects_Tool(mod, "XCAFDimTolObjects_Tool", "None");

// Constructors
cls_XCAFDimTolObjects_Tool.def(py::init<const opencascade::handle<TDocStd_Document> &>(), py::arg("theDoc"));

// Fields

// Methods
// cls_XCAFDimTolObjects_Tool.def_static("operator new_", (void * (*)(size_t)) &XCAFDimTolObjects_Tool::operator new, "None", py::arg("theSize"));
// cls_XCAFDimTolObjects_Tool.def_static("operator delete_", (void (*)(void *)) &XCAFDimTolObjects_Tool::operator delete, "None", py::arg("theAddress"));
// cls_XCAFDimTolObjects_Tool.def_static("operator new[]_", (void * (*)(size_t)) &XCAFDimTolObjects_Tool::operator new[], "None", py::arg("theSize"));
// cls_XCAFDimTolObjects_Tool.def_static("operator delete[]_", (void (*)(void *)) &XCAFDimTolObjects_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFDimTolObjects_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFDimTolObjects_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFDimTolObjects_Tool.def_static("operator delete_", (void (*)(void *, void *)) &XCAFDimTolObjects_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFDimTolObjects_Tool.def("GetDimensions", (void (XCAFDimTolObjects_Tool::*)(XCAFDimTolObjects_DimensionObjectSequence &) const) &XCAFDimTolObjects_Tool::GetDimensions, "Returns a sequence of Dimensions currently stored in the GD&T table", py::arg("theDimensionObjectSequence"));
cls_XCAFDimTolObjects_Tool.def("GetRefDimensions", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, XCAFDimTolObjects_DimensionObjectSequence &) const) &XCAFDimTolObjects_Tool::GetRefDimensions, "Returns all Dimensions defined for Shape", py::arg("theShape"), py::arg("theDimensions"));
cls_XCAFDimTolObjects_Tool.def("GetGeomTolerances", (void (XCAFDimTolObjects_Tool::*)(XCAFDimTolObjects_GeomToleranceObjectSequence &, XCAFDimTolObjects_DatumObjectSequence &, XCAFDimTolObjects_DataMapOfToleranceDatum &) const) &XCAFDimTolObjects_Tool::GetGeomTolerances, "Returns a sequence of Tolerances currently stored in the GD&T table", py::arg("theGeomToleranceObjectSequence"), py::arg("theDatumObjectSequence"), py::arg("theMap"));
cls_XCAFDimTolObjects_Tool.def("GetRefGeomTolerances", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, XCAFDimTolObjects_GeomToleranceObjectSequence &, XCAFDimTolObjects_DatumObjectSequence &, XCAFDimTolObjects_DataMapOfToleranceDatum &) const) &XCAFDimTolObjects_Tool::GetRefGeomTolerances, "Returns all GeomTolerances defined for Shape", py::arg("theShape"), py::arg("theGeomToleranceObjectSequence"), py::arg("theDatumObjectSequence"), py::arg("theMap"));
cls_XCAFDimTolObjects_Tool.def("GetRefDatum", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, opencascade::handle<XCAFDimTolObjects_DatumObject> &) const) &XCAFDimTolObjects_Tool::GetRefDatum, "Returns DatumObject defined for Shape", py::arg("theShape"), py::arg("theDatum"));

// Enums

}