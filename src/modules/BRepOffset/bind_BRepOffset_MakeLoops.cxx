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
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <BRepAlgo_Image.hxx>
#include <BRepOffset_Analyse.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepOffset_MakeLoops.hxx>

void bind_BRepOffset_MakeLoops(py::module &mod){

py::class_<BRepOffset_MakeLoops, std::unique_ptr<BRepOffset_MakeLoops>> cls_BRepOffset_MakeLoops(mod, "BRepOffset_MakeLoops", "None");

// Constructors
cls_BRepOffset_MakeLoops.def(py::init<>());

// Fields

// Methods
// cls_BRepOffset_MakeLoops.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_MakeLoops::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_MakeLoops.def_static("operator delete_", (void (*)(void *)) &BRepOffset_MakeLoops::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_MakeLoops.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_MakeLoops::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_MakeLoops.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_MakeLoops::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_MakeLoops.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_MakeLoops::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_MakeLoops.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_MakeLoops::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_MakeLoops.def("Build", (void (BRepOffset_MakeLoops::*)(const TopTools_ListOfShape &, const opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &)) &BRepOffset_MakeLoops::Build, "None", py::arg("LF"), py::arg("AsDes"), py::arg("Image"));
cls_BRepOffset_MakeLoops.def("BuildOnContext", (void (BRepOffset_MakeLoops::*)(const TopTools_ListOfShape &, const BRepOffset_Analyse &, const opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &, const Standard_Boolean)) &BRepOffset_MakeLoops::BuildOnContext, "None", py::arg("LContext"), py::arg("Analyse"), py::arg("AsDes"), py::arg("Image"), py::arg("InSide"));
cls_BRepOffset_MakeLoops.def("BuildFaces", (void (BRepOffset_MakeLoops::*)(const TopTools_ListOfShape &, const opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &)) &BRepOffset_MakeLoops::BuildFaces, "None", py::arg("LF"), py::arg("AsDes"), py::arg("Image"));

// Enums

}