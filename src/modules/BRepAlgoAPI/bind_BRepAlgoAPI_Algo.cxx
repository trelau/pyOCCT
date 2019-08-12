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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <BOPAlgo_Options.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BRepAlgoAPI_Algo.hxx>

void bind_BRepAlgoAPI_Algo(py::module &mod){

py::class_<BRepAlgoAPI_Algo, std::unique_ptr<BRepAlgoAPI_Algo, py::nodelete>, BRepBuilderAPI_MakeShape> cls_BRepAlgoAPI_Algo(mod, "BRepAlgoAPI_Algo", "Provides the root interface for the API algorithms", py::multiple_inheritance());

// Constructors

// Fields

// Methods
// cls_BRepAlgoAPI_Algo.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Algo::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Algo.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Algo::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Algo.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Algo::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Algo.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Algo::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Algo.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Algo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Algo.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Algo::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Algo.def("Shape", (const TopoDS_Shape & (BRepAlgoAPI_Algo::*)()) &BRepAlgoAPI_Algo::Shape, "None");

// Enums

}