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
#include <gp_Ax2.hxx>
#include <Prs3d_Drawer.hxx>
#include <DsgPrs_DatumPrs.hxx>

void bind_DsgPrs_DatumPrs(py::module &mod){

py::class_<DsgPrs_DatumPrs, std::unique_ptr<DsgPrs_DatumPrs>, Prs3d_Root> cls_DsgPrs_DatumPrs(mod, "DsgPrs_DatumPrs", "A framework for displaying an XYZ trihedron.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_DatumPrs.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_DatumPrs::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_DatumPrs.def_static("operator delete_", (void (*)(void *)) &DsgPrs_DatumPrs::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_DatumPrs.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_DatumPrs::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_DatumPrs.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_DatumPrs::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_DatumPrs.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_DatumPrs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_DatumPrs.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_DatumPrs::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_DatumPrs.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const gp_Ax2 &, const opencascade::handle<Prs3d_Drawer> &)) &DsgPrs_DatumPrs::Add, "Draw XYZ axes at specified location with attributes defined by the attribute manager theDrawer: - Prs3d_DatumAspect defines arrow, line and lenght trihedron axis parameters, - Prs3d_TextAspect defines displayed text. The thihedron origin and axis directions are defined by theDatum coordinate system. DsgPrs_XYZAxisPresentation framework is used to create graphical primitives for each axis. Axes are marked with 'X', 'Y', 'Z' text.", py::arg("thePresentation"), py::arg("theDatum"), py::arg("theDrawer"));

// Enums

}