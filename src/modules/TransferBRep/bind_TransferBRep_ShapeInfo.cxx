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
#include <Standard_Type.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TransferBRep_ShapeInfo.hxx>

void bind_TransferBRep_ShapeInfo(py::module &mod){

py::class_<TransferBRep_ShapeInfo, std::unique_ptr<TransferBRep_ShapeInfo>> cls_TransferBRep_ShapeInfo(mod, "TransferBRep_ShapeInfo", "Gives informations on an object, see template DataInfo This class is for Shape");

// Constructors

// Fields

// Methods
// cls_TransferBRep_ShapeInfo.def_static("operator new_", (void * (*)(size_t)) &TransferBRep_ShapeInfo::operator new, "None", py::arg("theSize"));
// cls_TransferBRep_ShapeInfo.def_static("operator delete_", (void (*)(void *)) &TransferBRep_ShapeInfo::operator delete, "None", py::arg("theAddress"));
// cls_TransferBRep_ShapeInfo.def_static("operator new[]_", (void * (*)(size_t)) &TransferBRep_ShapeInfo::operator new[], "None", py::arg("theSize"));
// cls_TransferBRep_ShapeInfo.def_static("operator delete[]_", (void (*)(void *)) &TransferBRep_ShapeInfo::operator delete[], "None", py::arg("theAddress"));
// cls_TransferBRep_ShapeInfo.def_static("operator new_", (void * (*)(size_t, void *)) &TransferBRep_ShapeInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TransferBRep_ShapeInfo.def_static("operator delete_", (void (*)(void *, void *)) &TransferBRep_ShapeInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_TransferBRep_ShapeInfo.def_static("Type_", (opencascade::handle<Standard_Type> (*)(const TopoDS_Shape &)) &TransferBRep_ShapeInfo::Type, "Returns the Type attached to an object Here, TShape (Shape has no Dynamic Type)", py::arg("ent"));
cls_TransferBRep_ShapeInfo.def_static("TypeName_", (Standard_CString (*)(const TopoDS_Shape &)) &TransferBRep_ShapeInfo::TypeName, "Returns Type Name (string) Here, the true name of the Type of a Shape", py::arg("ent"));

// Enums

}