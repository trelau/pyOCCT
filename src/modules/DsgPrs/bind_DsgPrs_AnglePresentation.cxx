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
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Circ.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <gp_Ax1.hxx>
#include <DsgPrs_AnglePresentation.hxx>

void bind_DsgPrs_AnglePresentation(py::module &mod){

py::class_<DsgPrs_AnglePresentation> cls_DsgPrs_AnglePresentation(mod, "DsgPrs_AnglePresentation", "A framework for displaying angles.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_AnglePresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_AnglePresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_AnglePresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_AnglePresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_AnglePresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_AnglePresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_AnglePresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_AnglePresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_AnglePresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_AnglePresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_AnglePresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_AnglePresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Circ &, const gp_Pnt &, const gp_Pnt &, const gp_Circ &, const gp_Circ &, const Standard_Real)) &DsgPrs_AnglePresentation::Add, "Draws the presenation of the full angle of a cone. VminCircle - a circle at V parameter = Vmin VmaxCircle - a circle at V parameter = Vmax aCircle - a circle at V parameter from projection of aPosition to axis of the cone", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aVal"), py::arg("aText"), py::arg("aCircle"), py::arg("aPosition"), py::arg("Apex"), py::arg("VminCircle"), py::arg("VmaxCircle"), py::arg("aArrowSize"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_AnglePresentation::Add, "Draws the representation of the angle defined by dir1 and dir2, centered on CenterPoint, using the offset point OffsetPoint. Lines are drawn to points AttachmentPoint1 and AttachmentPoint2", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("OffsetPoint"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_AnglePresentation::Add, "Same as above, but <thevalstring> contains conversion in Session units....", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("OffsetPoint"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_AnglePresentation::Add, "Same as above, may add one or two Arrows according to <ArrowSide> value", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_AnglePresentation::Add, "Same as above, but axisdir contains the axis direction useful for Revol that can be opened with 180 degrees", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("axisdir"), py::arg("OffsetPoint"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Boolean, const gp_Ax1 &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_AnglePresentation::Add, "Same as above,may add one or two Arrows according to <ArrowSide> value", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("axisdir"), py::arg("isPlane"), py::arg("AxisOfSurf"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const gp_Pnt &, const gp_Pnt &, const gp_Ax1 &, const DsgPrs_ArrowSide)) &DsgPrs_AnglePresentation::Add, "simple representation of a poor lonesome angle dimension Draw a line from <theCenter> to <AttachmentPoint1>, then operates a rotation around the perpmay add one or two Arrows according to <ArrowSide> value. The attributes (color,arrowsize,...) are driven by the Drawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("theCenter"), py::arg("AttachmentPoint1"), py::arg("theAxe"), py::arg("ArrowSide"));

// Enums

}