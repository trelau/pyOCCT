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
#include <DsgPrs_FixPresentation.hxx>

void bind_DsgPrs_FixPresentation(py::module &mod){

py::class_<DsgPrs_FixPresentation> cls_DsgPrs_FixPresentation(mod, "DsgPrs_FixPresentation", "class which draws the presentation of Fixed objects");

// Constructors

// Fields

// Methods
// cls_DsgPrs_FixPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_FixPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_FixPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_FixPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_FixPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_FixPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_FixPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_FixPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_FixPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_FixPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_FixPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_FixPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_FixPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const Standard_Real)) &DsgPrs_FixPresentation::Add, "draws the presentation of fixed objects by drawing the 'fix' symbol at position <aPntEnd>. A binding segment is drawn between <aPntAttach> ( which belongs the the fix object) and <aPntEnd>. aSymbSize is the size of the 'fix'symbol", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPntAttach"), py::arg("aPntEnd"), py::arg("aNormPln"), py::arg("aSymbSize"));

// Enums

}