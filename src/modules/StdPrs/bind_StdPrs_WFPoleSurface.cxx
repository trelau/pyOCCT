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
#include <Prs3d_Root.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Prs3d_Drawer.hxx>
#include <StdPrs_WFPoleSurface.hxx>

void bind_StdPrs_WFPoleSurface(py::module &mod){

py::class_<StdPrs_WFPoleSurface, Prs3d_Root> cls_StdPrs_WFPoleSurface(mod, "StdPrs_WFPoleSurface", "Computes the presentation of surfaces by drawing a double network of lines linking the poles of the surface in the two parametric direction. The number of lines to be drawn is controlled by the NetworkNumber of the given Drawer.");

// Constructors

// Fields

// Methods
// cls_StdPrs_WFPoleSurface.def_static("operator new_", (void * (*)(size_t)) &StdPrs_WFPoleSurface::operator new, "None", py::arg("theSize"));
// cls_StdPrs_WFPoleSurface.def_static("operator delete_", (void (*)(void *)) &StdPrs_WFPoleSurface::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_WFPoleSurface.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_WFPoleSurface::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_WFPoleSurface.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_WFPoleSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_WFPoleSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_WFPoleSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_WFPoleSurface.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_WFPoleSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_WFPoleSurface.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFPoleSurface::Add, "Adds the surface aSurface to the presentation object aPresentation. The shape's display attributes are set in the attribute manager aDrawer. The surface aSurface is a surface object from Adaptor3d, and provides data from a Geom surface. This makes it possible to use the surface in a geometric algorithm.", py::arg("aPresentation"), py::arg("aSurface"), py::arg("aDrawer"));

// Enums

}