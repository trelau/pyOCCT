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
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <DsgPrs_TangentPresentation.hxx>

void bind_DsgPrs_TangentPresentation(py::module &mod){

py::class_<DsgPrs_TangentPresentation, std::unique_ptr<DsgPrs_TangentPresentation, Deleter<DsgPrs_TangentPresentation>>> cls_DsgPrs_TangentPresentation(mod, "DsgPrs_TangentPresentation", "A framework to define display of tangents.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_TangentPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_TangentPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_TangentPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_TangentPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_TangentPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_TangentPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_TangentPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_TangentPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_TangentPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_TangentPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_TangentPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_TangentPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_TangentPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Dir &, const Standard_Real)) &DsgPrs_TangentPresentation::Add, "Adds the point OffsetPoint, the direction aDirection and the length aLength to the presentation object aPresentation. The display attributes of the tangent are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("OffsetPoint"), py::arg("aDirection"), py::arg("aLength"));

// Enums

}