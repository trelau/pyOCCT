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
#include <StdPrs_ShadedSurface.hxx>

void bind_StdPrs_ShadedSurface(py::module &mod){

py::class_<StdPrs_ShadedSurface, std::unique_ptr<StdPrs_ShadedSurface, Deleter<StdPrs_ShadedSurface>>, Prs3d_Root> cls_StdPrs_ShadedSurface(mod, "StdPrs_ShadedSurface", "Computes the shading presentation of surfaces. Draws a surface by drawing the isoparametric curves with respect to a maximal chordial deviation. The number of isoparametric curves to be drawn and their color are controlled by the furnished Drawer.");

// Constructors

// Fields

// Methods
// cls_StdPrs_ShadedSurface.def_static("operator new_", (void * (*)(size_t)) &StdPrs_ShadedSurface::operator new, "None", py::arg("theSize"));
// cls_StdPrs_ShadedSurface.def_static("operator delete_", (void (*)(void *)) &StdPrs_ShadedSurface::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_ShadedSurface.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_ShadedSurface::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_ShadedSurface.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_ShadedSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_ShadedSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_ShadedSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_ShadedSurface.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_ShadedSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_ShadedSurface.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ShadedSurface::Add, "Adds the surface aSurface to the presentation object aPresentation. The surface's display attributes are set in the attribute manager aDrawer. The surface object from Adaptor3d provides data from a Geom surface in order to use the surface in an algorithm.", py::arg("aPresentation"), py::arg("aSurface"), py::arg("aDrawer"));

// Enums

}