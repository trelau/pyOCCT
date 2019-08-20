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
#include <Geom_Plane.hxx>
#include <gp_Dir.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <gp_Circ.hxx>
#include <DsgPrs_EqualDistancePresentation.hxx>

void bind_DsgPrs_EqualDistancePresentation(py::module &mod){

py::class_<DsgPrs_EqualDistancePresentation, std::unique_ptr<DsgPrs_EqualDistancePresentation>> cls_DsgPrs_EqualDistancePresentation(mod, "DsgPrs_EqualDistancePresentation", "A framework to display equal distances between shapes and a given plane. The distance is the length of a projection from the shape to the plane. These distances are used to compare two shapes by this vector alone.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_EqualDistancePresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_EqualDistancePresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_EqualDistancePresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_EqualDistancePresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_EqualDistancePresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_EqualDistancePresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_EqualDistancePresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_EqualDistancePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const opencascade::handle<Geom_Plane> &)) &DsgPrs_EqualDistancePresentation::Add, "Adds the points Point1, Point2, Point3 Point4, and the plane Plane to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. The distance is the length of a projection from the shape to the plane. These distances are used to compare two shapes by this vector alone.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Point4"), py::arg("Plane"));
cls_DsgPrs_EqualDistancePresentation.def_static("AddInterval_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide, gp_Pnt &, gp_Pnt &)) &DsgPrs_EqualDistancePresentation::AddInterval, "is used for presentation of interval between two lines or two points or between a line and a point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPoint1"), py::arg("aPoint2"), py::arg("aDir"), py::arg("aPosition"), py::arg("anArrowSide"), py::arg("anExtremePnt1"), py::arg("anExtremePnt2"));
cls_DsgPrs_EqualDistancePresentation.def_static("AddIntervalBetweenTwoArcs_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Circ &, const gp_Circ &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_EqualDistancePresentation::AddIntervalBetweenTwoArcs, "is used for presentation of interval between two arcs. One of arcs can have a zero radius.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aCircle1"), py::arg("aCircle2"), py::arg("aPoint1"), py::arg("aPoint2"), py::arg("aPoint3"), py::arg("aPoint4"), py::arg("anArrowSide"));

// Enums

}