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
#include <SelectMgr_Selection.hxx>
#include <Prs3d_Drawer.hxx>
#include <StdSelect_BRepSelectionTool.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <StdSelect_EdgeFilter.hxx>
#include <StdSelect_FaceFilter.hxx>
#include <StdSelect_ShapeTypeFilter.hxx>
#include <StdSelect_Prs.hxx>
#include <StdSelect_Shape.hxx>
#include <StdSelect.hxx>

void bind_StdSelect(py::module &mod){

py::class_<StdSelect, std::unique_ptr<StdSelect, Deleter<StdSelect>>> cls_StdSelect(mod, "StdSelect", "The StdSelect package provides the following services - the definition of selection modes for topological shapes - the definition of several concrete filtertandard Selection2d.ap classes - 2D and 3D viewer selectors. Note that each new Interactive Object must have all its selection modes defined. Standard Classes is useful to build 3D Selectable Objects, and to process 3D Selections:");

// Constructors

// Fields

// Methods
// cls_StdSelect.def_static("operator new_", (void * (*)(size_t)) &StdSelect::operator new, "None", py::arg("theSize"));
// cls_StdSelect.def_static("operator delete_", (void (*)(void *)) &StdSelect::operator delete, "None", py::arg("theAddress"));
// cls_StdSelect.def_static("operator new[]_", (void * (*)(size_t)) &StdSelect::operator new[], "None", py::arg("theSize"));
// cls_StdSelect.def_static("operator delete[]_", (void (*)(void *)) &StdSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StdSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StdSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdSelect.def_static("operator delete_", (void (*)(void *, void *)) &StdSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StdSelect.def_static("SetDrawerForBRepOwner_", (void (*)(const opencascade::handle<SelectMgr_Selection> &, const opencascade::handle<Prs3d_Drawer> &)) &StdSelect::SetDrawerForBRepOwner, "puts The same drawer in every BRepOwner Of SensitivePrimitive Used Only for hilight Of BRepOwner...", py::arg("aSelection"), py::arg("aDrawer"));

// Enums

}