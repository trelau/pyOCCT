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
#include <Standard_TypeDef.hxx>
#include <DsgPrs_PerpenPresentation.hxx>

void bind_DsgPrs_PerpenPresentation(py::module &mod){

py::class_<DsgPrs_PerpenPresentation> cls_DsgPrs_PerpenPresentation(mod, "DsgPrs_PerpenPresentation", "A framework to define display of perpendicular constraints between shapes.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_PerpenPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_PerpenPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_PerpenPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_PerpenPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_PerpenPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_PerpenPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_PerpenPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_PerpenPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_PerpenPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_PerpenPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_PerpenPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_PerpenPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_PerpenPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_PerpenPresentation::Add, "Defines the display of elements showing perpendicular constraints between shapes. These include the two axis points pAx1 and pAx2, the two points pnt1 and pnt2, the offset point OffsetPoint and the two Booleans intOut1} and intOut2{. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("pAx1"), py::arg("pAx2"), py::arg("pnt1"), py::arg("pnt2"), py::arg("OffsetPoint"), py::arg("intOut1"), py::arg("intOut2"));

// Enums

}