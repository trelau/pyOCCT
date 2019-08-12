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
#include <DsgPrs_ShadedPlanePresentation.hxx>

void bind_DsgPrs_ShadedPlanePresentation(py::module &mod){

py::class_<DsgPrs_ShadedPlanePresentation, std::unique_ptr<DsgPrs_ShadedPlanePresentation, Deleter<DsgPrs_ShadedPlanePresentation>>> cls_DsgPrs_ShadedPlanePresentation(mod, "DsgPrs_ShadedPlanePresentation", "A framework to define display of shaded planes.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_ShadedPlanePresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_ShadedPlanePresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_ShadedPlanePresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_ShadedPlanePresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_ShadedPlanePresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_ShadedPlanePresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_ShadedPlanePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_ShadedPlanePresentation::Add, "Adds the points aPt1, aPt2 and aPt3 to the presentation object, aPresentation. The display attributes of the shaded plane are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPt1"), py::arg("aPt2"), py::arg("aPt3"));

// Enums

}