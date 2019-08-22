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
#include <TopoDSToStep_FacetedError.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDSToStep_FacetedTool.hxx>

void bind_TopoDSToStep_FacetedTool(py::module &mod){

py::class_<TopoDSToStep_FacetedTool> cls_TopoDSToStep_FacetedTool(mod, "TopoDSToStep_FacetedTool", "This Tool Class provides Information about Faceted Shapes to be mapped to STEP.");

// Constructors

// Fields

// Methods
// cls_TopoDSToStep_FacetedTool.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep_FacetedTool::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep_FacetedTool.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep_FacetedTool::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep_FacetedTool.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep_FacetedTool::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep_FacetedTool.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep_FacetedTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep_FacetedTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep_FacetedTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep_FacetedTool.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep_FacetedTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep_FacetedTool.def_static("CheckTopoDSShape_", (TopoDSToStep_FacetedError (*)(const TopoDS_Shape &)) &TopoDSToStep_FacetedTool::CheckTopoDSShape, "None", py::arg("SH"));

// Enums

}