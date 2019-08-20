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
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <DsgPrs_MidPointPresentation.hxx>

void bind_DsgPrs_MidPointPresentation(py::module &mod){

py::class_<DsgPrs_MidPointPresentation, std::unique_ptr<DsgPrs_MidPointPresentation>> cls_DsgPrs_MidPointPresentation(mod, "DsgPrs_MidPointPresentation", "None");

// Constructors

// Fields

// Methods
// cls_DsgPrs_MidPointPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_MidPointPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_MidPointPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_MidPointPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_MidPointPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_MidPointPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_MidPointPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_MidPointPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_MidPointPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_MidPointPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_MidPointPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_MidPointPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two vertices.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theAxe"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("first"));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two lines or linear segments.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theAxe"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("Point1"), py::arg("Point2"), py::arg("first"));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Circ &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two entire circles or two circular arcs.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aCircle"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("Point1"), py::arg("Point2"), py::arg("first"));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two entire ellipses or two elliptic arcs.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("anElips"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("Point1"), py::arg("Point2"), py::arg("first"));

// Enums

}